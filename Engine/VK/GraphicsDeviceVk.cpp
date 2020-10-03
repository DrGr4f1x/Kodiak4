//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#include "Stdafx.h"

#include "GraphicsDeviceVk.h"

#include "GraphicsFeatures.h"

#include "DeviceFeatureHandlersVk.h"
#include "StructuresVk.h"
#include "UtilityVk.h"


using namespace Kodiak;
using namespace std;


DeviceProperties::DeviceProperties()
{
	deviceProperties2 = PhysicalDeviceProperties2();
	deviceProperties1_1 = PhysicalDeviceVulkan11Properties();
	deviceProperties1_2 = PhysicalDeviceVulkan12Properties();

	ResetPNextChain();
}


void DeviceProperties::ResetPNextChain()
{
	deviceProperties2.pNext = &deviceProperties1_1;
	deviceProperties1_1.pNext = &deviceProperties1_2;
	deviceProperties1_2.pNext = nullptr;
	ppNext = &deviceProperties1_2.pNext;
}


DeviceFeatures::DeviceFeatures()
{
	deviceFeatures2 = PhysicalDeviceFeatures2();
	deviceFeatures1_1 = PhysicalDeviceVulkan11Features();
	deviceFeatures1_2 = PhysicalDeviceVulkan12Features();

	ResetPNextChain();
}


void DeviceFeatures::ResetPNextChain()
{
	deviceFeatures2.pNext = &deviceFeatures1_1;
	deviceFeatures1_1.pNext = &deviceFeatures1_2;
	deviceFeatures1_2.pNext = nullptr;
	ppNext = &deviceFeatures1_2.pNext;
}


GraphicsDevice::GraphicsDevice()
{}


void GraphicsDevice::Initialize(
	const std::string& appName,
	HINSTANCE hinst,
	HWND hwnd,
	uint32_t width,
	uint32_t height,
	Format colorFormat,
	Format depthFormat)
{
	LOG_NOTICE << "  Initializing graphics device" << endl;;

	// Store properties from the application
	m_appName = appName;

	m_hinst = hinst;
	m_hwnd = hwnd;

	m_width = width;
	m_height = height;
	m_colorFormat = colorFormat;
	m_depthFormat = depthFormat;

	// Initialization begins here
	CreateInstance();

	SelectPhysicalDevice();
	GetPhysicalDeviceFeatures();
	EnableApplicationFeatures();

	InitializeDebugMarkup();
	InitializeValidation();
}


void GraphicsDevice::Finalize()
{}


void GraphicsDevice::CreateInstance()
{
	auto appInfo = ApplicationInfo();
	appInfo.pApplicationName = m_appName.c_str();
	appInfo.apiVersion = VK_API_VERSION_1_2;
	appInfo.pEngineName = s_engineName.c_str();
	appInfo.engineVersion = s_engineVersion;
	LogApplicationInfo(appInfo);

	// TODO: Validate the requested extensions and layers against the lists of available extensions and layers

	const vector<const char*> instanceExtensions =
	{
#if ENABLE_VULKAN_DEBUG_MARKUP || ENABLE_VULKAN_VALIDATION
			VK_EXT_DEBUG_UTILS_EXTENSION_NAME,
#endif

#if ENABLE_VULKAN_VALIDATION
			VK_EXT_VALIDATION_FEATURES_EXTENSION_NAME,
#endif
			VK_KHR_SURFACE_EXTENSION_NAME,
			VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME,
			VK_KHR_WIN32_SURFACE_EXTENSION_NAME
	};

	const vector<const char*> instanceLayers =
	{
#if ENABLE_VULKAN_VALIDATION
			"VK_LAYER_KHRONOS_validation"
#endif
	};

	auto createInfo = InstanceCreateInfo();
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = (uint32_t)instanceExtensions.size();
	createInfo.ppEnabledExtensionNames = instanceExtensions.data();
	createInfo.enabledLayerCount = (uint32_t)instanceLayers.size();
	createInfo.ppEnabledLayerNames = instanceLayers.data();

	VkInstance vkInstance{ VK_NULL_HANDLE };
	auto res = vkCreateInstance(&createInfo, nullptr, &vkInstance);
	if (VK_SUCCESS != res)
	{
		Utility::ExitFatal("Could not create Vulkan instance", "Fatal error");
	}

	m_instance = InstanceRef::Create(vkInstance);
}


void GraphicsDevice::SelectPhysicalDevice()
{
	// GPU selection
	auto physicalDevices = EnumeratePhysicalDevices(*m_instance);

	// TODO: Specify this somewhere application-accessible
	GpuClass gpuClass = GpuClass::HighPerformance;

	uint32_t deviceIndex = 0;
	bool isDeviceSelected = false;
	for (auto physicalDevice : physicalDevices)
	{
		vkGetPhysicalDeviceProperties2(physicalDevice, &m_deviceProperties.deviceProperties2);

		auto deviceType = m_deviceProperties.deviceProperties2.properties.deviceType;
		if (gpuClass == GpuClass::LowPower && deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU)
		{
			isDeviceSelected = true;
			break;
		}
		else if (gpuClass == GpuClass::HighPerformance && deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
		{
			isDeviceSelected = true;
			break;
		}

		++deviceIndex;
	}

	// If we didn't find a suitable physical device, just select the first one
	if (!isDeviceSelected)
	{
		deviceIndex = 0;
		vkGetPhysicalDeviceProperties2(physicalDevices[deviceIndex], &m_deviceProperties.deviceProperties2);
	}

	// Log the basic device properties for the selected physical device
	LogPhysicalDeviceProperties(m_deviceProperties.deviceProperties2.properties);

	m_physicalDevice = PhysicalDeviceRef::Create(m_instance, physicalDevices[deviceIndex]);
}


void GraphicsDevice::GetPhysicalDeviceFeatures()
{
	// Get memory properties
	vkGetPhysicalDeviceMemoryProperties(*m_physicalDevice, &m_memoryProperties);

	// Get device features
	vkGetPhysicalDeviceFeatures2(*m_physicalDevice, &m_supportedFeatures.deviceFeatures2);

	// Get supported extensions
	m_supportedFeatures.extensions = EnumerateDeviceExtensions(*m_physicalDevice);
	m_extensions.SetExtensionAvailability(m_supportedFeatures.extensions);

	// Get queue families
	m_queueFamilies = EnumerateQueueFamilies(*m_physicalDevice);
}


void GraphicsDevice::EnableApplicationFeatures()
{
	// Reconcile the optional and required feature sets.  If a feature is enabled for both,
	// treat it as required.
	for (size_t i = 0; i < g_requiredFeatures.GetNumFeatures(); ++i)
	{
		if (g_optionalFeatures[i] && g_requiredFeatures[i])
		{
			g_optionalFeatures[i] = false;
		}
	}

	// Enable the features requested by the application
	EnableFeatures(false);	// optional features
	EnableFeatures(true);	// required features

	// Enable debug and validation extensions
#if ENABLE_VULKAN_DEBUG_MARKUP || ENABLE_VULKAN_VALIDATION
	m_extensions.EnableExtension(m_extensions.debugUtilsEXT.GetName(), m_enabledFeatures, m_deviceProperties);
#endif

#if ENABLE_VULKAN_VALIDATION
	m_extensions.EnableExtension(m_extensions.validationFeaturesEXT.GetName(), m_enabledFeatures, m_deviceProperties);
#endif
}


void GraphicsDevice::EnableFeatures(bool required)
{
	auto& requestedFeatures = required ? g_requiredFeatures : g_optionalFeatures;
	auto& enabledFeatures = const_cast<GraphicsFeatureSet&>(g_enabledFeatures);

	vector<string> missingFeatures;

	auto TryEnableFeature = [&](const string& featureName, bool enabled)
	{
		if (!enabled)
			missingFeatures.push_back(featureName);
	};

	FeatureProxy featureProxy{ *m_instance, m_supportedFeatures, m_enabledFeatures, m_deviceProperties, m_extensions };

	const auto numFeatures = requestedFeatures.GetNumFeatures();
	for (auto i = 0; i < numFeatures; ++i)
	{
		const auto& requestedFeature = requestedFeatures[i];
		auto& enabledFeature = enabledFeatures[i];

		if (!requestedFeature)
			continue;

		const string& featureName = requestedFeature.GetName();

		switch (requestedFeature.GetFeature())
		{
		case GraphicsFeature::RobustBufferAccess:
			TryEnableFeature(featureName, EnableRobustBufferAccess(featureProxy));
			break;

		case GraphicsFeature::FullDrawIndexUint32:
			TryEnableFeature(featureName, EnableFullDrawIndexUint32(featureProxy));
			break;

		case GraphicsFeature::TextureCubeArray:
			TryEnableFeature(featureName, EnableTextureCubeArray(featureProxy));
			break;

		case GraphicsFeature::IndependentBlend:
			TryEnableFeature(featureName, EnableIndependentBlend(featureProxy));
			break;

		case GraphicsFeature::GeometryShader:
			TryEnableFeature(featureName, EnableGeometryShader(featureProxy));
			break;

		case GraphicsFeature::TessellationShader:
			TryEnableFeature(featureName, EnableTessellationShader(featureProxy));
			break;

		case GraphicsFeature::SampleRateShading:
			TryEnableFeature(featureName, EnableSampleRateShading(featureProxy));
			break;

		case GraphicsFeature::DualSrcBlend:
			TryEnableFeature(featureName, EnableDualSrcBlend(featureProxy));
			break;

		case GraphicsFeature::LogicOp:
			TryEnableFeature(featureName, EnableLogicOp(featureProxy));
			break;

		case GraphicsFeature::MultiDrawIndirect:
			TryEnableFeature(featureName, EnableMultiDrawIndirect(featureProxy));
			break;

		case GraphicsFeature::DrawIndirectFirstInstance:
			TryEnableFeature(featureName, EnableDrawIndirectFirstInstance(featureProxy));
			break;

		case GraphicsFeature::DepthClamp:
			TryEnableFeature(featureName, EnableDepthClamp(featureProxy));
			break;

		case GraphicsFeature::DepthBiasClamp:
			TryEnableFeature(featureName, EnableDepthBiasClamp(featureProxy));
			break;

		case GraphicsFeature::FillModeNonSolid:
			TryEnableFeature(featureName, EnableFillModeNonSolid(featureProxy));
			break;

		case GraphicsFeature::DepthBounds:
			TryEnableFeature(featureName, EnableDepthBounds(featureProxy));
			break;

		case GraphicsFeature::WideLines:
			TryEnableFeature(featureName, EnableWideLines(featureProxy));
			break;

		case GraphicsFeature::LargePoints:
			TryEnableFeature(featureName, EnableLargePoints(featureProxy));
			break;

		case GraphicsFeature::AlphaToOne:
			TryEnableFeature(featureName, EnableAlphaToOne(featureProxy));
			break;

		case GraphicsFeature::MultiViewport:
			TryEnableFeature(featureName, EnableMultiViewport(featureProxy));
			break;

		case GraphicsFeature::SamplerAnisotropy:
			TryEnableFeature(featureName, EnableSamplerAnisotropy(featureProxy));
			break;

		case GraphicsFeature::TextureCompressionETC2:
			TryEnableFeature(featureName, EnableTextureCompressionETC2(featureProxy));
			break;

		case GraphicsFeature::TextureCompressionASTC_LDR:
			TryEnableFeature(featureName, EnableTextureCompressionASTC_LDR(featureProxy));
			break;

		case GraphicsFeature::TextureCompressionBC:
			TryEnableFeature(featureName, EnableTextureCompressionBC(featureProxy));
			break;

		case GraphicsFeature::OcclusionQueryPrecise:
			TryEnableFeature(featureName, EnableOcclusionQueryPrecise(featureProxy));
			break;

		case GraphicsFeature::PipelineStatisticsQuery:
			TryEnableFeature(featureName, EnablePipelineStatisticsQuery(featureProxy));
			break;

		case GraphicsFeature::VertexPipelineStoresAndAtomics:
			TryEnableFeature(featureName, EnableVertexPipelineStoresAndAtomics(featureProxy));
			break;

		case GraphicsFeature::PixelShaderStoresAndAtomics:
			TryEnableFeature(featureName, EnablePixelShaderStoresAndAtomics(featureProxy));
			break;

		case GraphicsFeature::ShaderTessellationAndGeometryPointSize:
			TryEnableFeature(featureName, EnableShaderTessellationAndGeometryPointSize(featureProxy));
			break;

		case GraphicsFeature::ShaderTextureGatherExtended:
			TryEnableFeature(featureName, EnableShaderTextureGatherExtended(featureProxy));
			break;

		case GraphicsFeature::ShaderUAVExtendedFormats:
			TryEnableFeature(featureName, EnableShaderUAVExtendedFormats(featureProxy));
			break;

		case GraphicsFeature::ShaderClipDistance:
			TryEnableFeature(featureName, EnableShaderClipDistance(featureProxy));
			break;

		case GraphicsFeature::ShaderCullDistance:
			TryEnableFeature(featureName, EnableShaderCullDistance(featureProxy));
			break;

		case GraphicsFeature::ShaderFloat64:
			TryEnableFeature(featureName, EnableShaderFloat64(featureProxy));
			break;

		case GraphicsFeature::ShaderFloat16:
			TryEnableFeature(featureName, EnableShaderFloat16(featureProxy));
			break;

		case GraphicsFeature::ShaderInt64:
			TryEnableFeature(featureName, EnableShaderInt64(featureProxy));
			break;

		case GraphicsFeature::ShaderInt16:
			TryEnableFeature(featureName, EnableShaderInt16(featureProxy));
			break;

		case GraphicsFeature::ShaderInt8:
			TryEnableFeature(featureName, EnableShaderInt8(featureProxy));
			break;

		case GraphicsFeature::VariableMultisampleRate:
			TryEnableFeature(featureName, EnableVariableMultisampleRate(featureProxy));
			break;
		}
	}
}