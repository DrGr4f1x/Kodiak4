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

#define VMA_IMPLEMENTATION
#include "Extern\VulkanMemoryAllocator\vk_mem_alloc.h"


using namespace Kodiak;
using namespace std;


// Extension function pointers
#if ENABLE_VULKAN_DEBUG_MARKUP || ENABLE_VULKAN_VALIDATION
PFN_vkCmdBeginDebugUtilsLabelEXT		vkCmdBeginDebugUtilsLabel = nullptr;
PFN_vkCmdEndDebugUtilsLabelEXT			vkCmdEndDebugUtilsLabel = nullptr;
PFN_vkCmdInsertDebugUtilsLabelEXT		vkCmdInsertDebugUtilsLabel = nullptr;
PFN_vkQueueBeginDebugUtilsLabelEXT		vkQueueBeginDebugUtilsLabel = nullptr;
PFN_vkQueueEndDebugUtilsLabelEXT		vkQueueEndDebugUtilsLabel = nullptr;
PFN_vkQueueInsertDebugUtilsLabelEXT		vkQueueInsertDebugUtilsLabel = nullptr;
PFN_vkSetDebugUtilsObjectNameEXT		vkSetDebugUtilsObjectName = nullptr;
PFN_vkSetDebugUtilsObjectTagEXT			vkSetDebugUtilsObjectTag = nullptr;
#endif

#if ENABLE_VULKAN_VALIDATION
PFN_vkCreateDebugUtilsMessengerEXT		vkCreateDebugUtilsMessenger = nullptr;
PFN_vkDestroyDebugUtilsMessengerEXT		vkDestroyDebugUtilsMessenger = nullptr;
PFN_vkSubmitDebugUtilsMessageEXT		vkSubmitDebugUtilsMessage = nullptr;
#endif

PFN_vkAcquireNextImageKHR				vkAcquireNextImage = nullptr;
PFN_vkAcquireNextImage2KHR				vkAcquireNextImage2 = nullptr;
PFN_vkCreateSwapchainKHR				vkCreateSwapchain = nullptr;
PFN_vkDestroySwapchainKHR				vkDestroySwapchain = nullptr;
PFN_vkGetSwapchainImagesKHR				vkGetSwapchainImages = nullptr;
PFN_vkQueuePresentKHR					vkQueuePresent = nullptr;


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

	CreateLogicalDevice();
	InitializeExtensions();

	m_allocator = CreateAllocator();

	CreateSurface();
	CreateSwapchain();
}


void GraphicsDevice::Finalize()
{}


shared_ptr<AllocatorRef> GraphicsDevice::CreateAllocator() const
{
	VmaAllocatorCreateInfo createInfo = {};
	createInfo.physicalDevice = *m_physicalDevice;
	createInfo.device = *m_device;

	VmaAllocator vmaAllocator{ VK_NULL_HANDLE };
	ThrowIfFailed(vmaCreateAllocator(&createInfo, &vmaAllocator));

	auto allocator = AllocatorRef::Create(m_instance, m_physicalDevice, m_device, vmaAllocator);
	return allocator;
}


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


void GraphicsDevice::CreateLogicalDevice()
{
	// Desired queues need to be requested upon logical device creation
	// Due to differing queue family configurations of Vulkan implementations this can be a bit tricky, especially if the application
	// requests different queue types

	vector<VkDeviceQueueCreateInfo> queueCreateInfos{};

	// Get queue family indices for the requested queue family types
	// Note that the indices may overlap depending on the implementation

	const float defaultQueuePriority = 0.0f;

	// Graphics queue
	m_queueFamilyIndices.graphics = GetQueueFamilyIndex(VK_QUEUE_GRAPHICS_BIT);
	VkDeviceQueueCreateInfo queueInfo = DeviceQueueCreateInfo();
	queueInfo.queueFamilyIndex = m_queueFamilyIndices.graphics;
	queueInfo.queueCount = 1;
	queueInfo.pQueuePriorities = &defaultQueuePriority;
	queueCreateInfos.push_back(queueInfo);

	// Dedicated compute queue
	m_queueFamilyIndices.compute = GetQueueFamilyIndex(VK_QUEUE_COMPUTE_BIT);
	if (m_queueFamilyIndices.compute != m_queueFamilyIndices.graphics)
	{
		// If compute family index differs, we need an additional queue create info for the compute queue
		VkDeviceQueueCreateInfo queueInfo = DeviceQueueCreateInfo();
		queueInfo.queueFamilyIndex = m_queueFamilyIndices.compute;
		queueInfo.queueCount = 1;
		queueInfo.pQueuePriorities = &defaultQueuePriority;
		queueCreateInfos.push_back(queueInfo);
	}

	// Dedicated transfer queue
	m_queueFamilyIndices.transfer = GetQueueFamilyIndex(VK_QUEUE_TRANSFER_BIT);
	if ((m_queueFamilyIndices.transfer != m_queueFamilyIndices.graphics) && (m_queueFamilyIndices.transfer != m_queueFamilyIndices.compute))
	{
		// If compute family index differs, we need an additional queue create info for the transfer queue
		VkDeviceQueueCreateInfo queueInfo = DeviceQueueCreateInfo();
		queueInfo.queueFamilyIndex = m_queueFamilyIndices.transfer;
		queueInfo.queueCount = 1;
		queueInfo.pQueuePriorities = &defaultQueuePriority;
		queueCreateInfos.push_back(queueInfo);
	}

	// Get the enabled device extensions
	vector<const char*> extensionNames = m_extensions.GetEnabledExtensionNames();

	// Create the device
	VkDeviceCreateInfo createInfo = DeviceCreateInfo();
	createInfo.pNext = &m_enabledFeatures.deviceFeatures2;
	createInfo.queueCreateInfoCount = (uint32_t)queueCreateInfos.size();
	createInfo.pQueueCreateInfos = queueCreateInfos.data();
	createInfo.pEnabledFeatures = nullptr;
	createInfo.enabledLayerCount = 0;
	createInfo.ppEnabledLayerNames = nullptr;
	createInfo.enabledExtensionCount = (uint32_t)extensionNames.size();
	createInfo.ppEnabledExtensionNames = extensionNames.data();

	VkDevice vkDevice{ VK_NULL_HANDLE };
	ThrowIfFailed(vkCreateDevice(*m_physicalDevice, &createInfo, nullptr, &vkDevice));
	m_device = DeviceRef::Create(m_physicalDevice, vkDevice);
}


void GraphicsDevice::CreateSurface()
{
	// Create surface
	VkWin32SurfaceCreateInfoKHR surfaceCreateInfo = Win32SurfaceCreateInfo();
	surfaceCreateInfo.hinstance = m_hinst;
	surfaceCreateInfo.hwnd = m_hwnd;

	VkSurfaceKHR vkSurface{ VK_NULL_HANDLE };
	VkResult res = vkCreateWin32SurfaceKHR(*m_instance, &surfaceCreateInfo, nullptr, &vkSurface);

	if (res != VK_SUCCESS)
	{
		Utility::ExitFatal("Could not create surface!", "Fatal error");
	}

	m_surface = SurfaceRef::Create(m_instance, vkSurface);

	// Get list of supported surface formats
	vector<VkSurfaceFormatKHR> surfaceFormats = EnumerateSurfaceFormats(*m_physicalDevice, *m_surface);

	// If the surface format list only includes one entry with VK_FORMAT_UNDEFINED,
	// there is no preferred format, so we assume VK_FORMAT_B8G8R8A8_UNORM
	if ((surfaceFormats.size() == 1) && (surfaceFormats[0].format == VK_FORMAT_UNDEFINED))
	{
		m_colorFormat = MapVulkanFormatToEngine(VK_FORMAT_B8G8R8A8_UNORM);
		m_colorSpace = surfaceFormats[0].colorSpace;
	}
	else
	{
		// iterate over the list of available surface format and
		// check for the presence of VK_FORMAT_B8G8R8A8_UNORM
		bool found_B8G8R8A8_UNORM = false;
		for (auto&& surfaceFormat : surfaceFormats)
		{
			if (surfaceFormat.format == VK_FORMAT_B8G8R8A8_UNORM)
			{
				m_colorFormat = MapVulkanFormatToEngine(surfaceFormat.format);
				m_colorSpace = surfaceFormat.colorSpace;
				found_B8G8R8A8_UNORM = true;
				break;
			}
		}

		// in case VK_FORMAT_B8G8R8A8_UNORM is not available
		// select the first available color format
		if (!found_B8G8R8A8_UNORM)
		{
			m_colorFormat = MapVulkanFormatToEngine(surfaceFormats[0].format);
			m_colorSpace = surfaceFormats[0].colorSpace;
		}
	}
}


void GraphicsDevice::CreateSwapchain()
{
	auto oldSwapchain = m_swapchain;

	VkPhysicalDevice physicalDevice = *m_physicalDevice;
	VkSurfaceKHR surface = *m_surface;

	// Get physical device surface properties and formats
	VkSurfaceCapabilitiesKHR surfCaps;
	ThrowIfFailed(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, &surfCaps));

	// Check physical device surface support
	VkBool32 surfaceSupported = VK_FALSE;
	ThrowIfFailed(vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice, m_queueFamilyIndices.graphics, surface, &surfaceSupported));
	assert(surfaceSupported == VK_TRUE);

	// Get available present modes
	vector<VkPresentModeKHR> presentModes = EnumeratePresentModes(physicalDevice, surface);

	VkExtent2D swapchainExtent = {};
	// If width (and height) equals the special value 0xFFFFFFFF, the size of the surface will be set by the swapchain
	if (surfCaps.currentExtent.width == (uint32_t)-1)
	{
		// If the surface size is undefined, the size is set to
		// the size of the images requested.
		swapchainExtent.width = m_width;
		swapchainExtent.height = m_height;
	}
	else
	{
		// If the surface size is defined, the swap chain size must match
		swapchainExtent = surfCaps.currentExtent;
		m_width = surfCaps.currentExtent.width;
		m_height = surfCaps.currentExtent.height;
	}

	// Select a present mode for the swapchain

	// The VK_PRESENT_MODE_FIFO_KHR mode must always be present as per spec
	// This mode waits for the vertical blank ("v-sync")
	VkPresentModeKHR swapchainPresentMode = VK_PRESENT_MODE_FIFO_KHR;

	// If v-sync is not requested, try to find a mailbox mode
	// It's the lowest latency non-tearing present mode available
	if (!m_vsync)
	{
		for (size_t i = 0; i < presentModes.size(); ++i)
		{
			if (presentModes[i] == VK_PRESENT_MODE_MAILBOX_KHR)
			{
				swapchainPresentMode = VK_PRESENT_MODE_MAILBOX_KHR;
				break;
			}
			if ((swapchainPresentMode != VK_PRESENT_MODE_MAILBOX_KHR) && (presentModes[i] == VK_PRESENT_MODE_IMMEDIATE_KHR))
			{
				swapchainPresentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
			}
		}
	}

	// Determine the number of images
	const uint32_t NumSwapChainBuffers = 3; // TODO - Put this somewhere else
	uint32_t desiredNumberOfSwapchainImages = max(surfCaps.minImageCount + 1, NumSwapChainBuffers);
	if ((surfCaps.maxImageCount > 0) && (desiredNumberOfSwapchainImages > surfCaps.maxImageCount))
	{
		desiredNumberOfSwapchainImages = surfCaps.maxImageCount;
	}

	// Find the transformation of the surface
	VkSurfaceTransformFlagBitsKHR preTransform;
	if (surfCaps.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
	{
		// We prefer a non-rotated transform
		preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
	}
	else
	{
		preTransform = surfCaps.currentTransform;
	}

	// Find a supported composite alpha format (not all devices support alpha opaque)
	VkCompositeAlphaFlagBitsKHR compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	// Simply select the first composite alpha format available
	vector<VkCompositeAlphaFlagBitsKHR> compositeAlphaFlags =
	{
		VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
		VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
		VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,
		VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR,
	};

	for (auto& compositeAlphaFlag : compositeAlphaFlags)
	{
		if (surfCaps.supportedCompositeAlpha & compositeAlphaFlag)
		{
			compositeAlpha = compositeAlphaFlag;
			break;
		};
	}

	auto vkFormat = static_cast<VkFormat>(m_colorFormat);

	VkImageUsageFlags usage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;

	// Set additional usage flag for blitting from the swapchain images if supported
	VkFormatProperties formatProps;
	vkGetPhysicalDeviceFormatProperties(physicalDevice, vkFormat, &formatProps);
	if (formatProps.optimalTilingFeatures & VK_FORMAT_FEATURE_BLIT_DST_BIT)
	{
		usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
	}

	// Create the swapchain
	VkSwapchainKHR oldsc = VK_NULL_HANDLE;
	if (oldSwapchain)
	{
		oldsc = *oldSwapchain;
	}

	VkSwapchainCreateInfoKHR swapchainCreateInfo = SwapchainCreateInfo();
	swapchainCreateInfo.surface = surface;
	swapchainCreateInfo.minImageCount = desiredNumberOfSwapchainImages;
	swapchainCreateInfo.imageFormat = vkFormat;
	swapchainCreateInfo.imageColorSpace = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
	swapchainCreateInfo.imageExtent = swapchainExtent;
	swapchainCreateInfo.imageUsage = usage;
	swapchainCreateInfo.preTransform = preTransform;
	swapchainCreateInfo.imageArrayLayers = 1u;
	swapchainCreateInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
	swapchainCreateInfo.queueFamilyIndexCount = 0;
	swapchainCreateInfo.pQueueFamilyIndices = nullptr;
	swapchainCreateInfo.presentMode = swapchainPresentMode;
	swapchainCreateInfo.oldSwapchain = oldsc;
	// Setting clipped to VK_TRUE allows the implementation to discard rendering outside of the surface area
	swapchainCreateInfo.clipped = VK_TRUE;
	swapchainCreateInfo.compositeAlpha = compositeAlpha;

	VkSwapchainKHR vkSwapchain{ VK_NULL_HANDLE };
	ThrowIfFailed(vkCreateSwapchain(*m_device, &swapchainCreateInfo, nullptr, &vkSwapchain));
	m_swapchain = SwapchainRef::Create(m_device, vkSwapchain);

	// Count actual swapchain images
	uint32_t imageCount{ 0 };
	ThrowIfFailed(vkGetSwapchainImages(*m_device, *m_swapchain, &imageCount, nullptr));

	// Get the swap chain images
	vector<VkImage> images(imageCount);
	ThrowIfFailed(vkGetSwapchainImages(*m_device, *m_swapchain, &imageCount, images.data()));

	m_swapchainImages.reserve(imageCount);
	for (auto image : images)
	{
		m_swapchainImages.push_back(ImageRef::Create(m_device, image));
	}
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

	// Get queue family properties
	m_queueFamilyProperties = EnumerateQueueFamilies(*m_physicalDevice);
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

	// Always enable the swapchain extension
	m_extensions.EnableExtension(m_extensions.swapchainKHR.GetName(), m_enabledFeatures, m_deviceProperties);
}


void GraphicsDevice::InitializeExtensions()
{
	m_extensions.InitializeExtensions(m_device);

	// Create the debug callback for validation
#if ENABLE_VULKAN_VALIDATION

#endif
}


uint32_t GraphicsDevice::GetQueueFamilyIndex(VkQueueFlags queueFlags) const
{
	uint32_t index = 0;

	// Dedicated queue for compute
	// Try to find a queue family index that supports compute but not graphics
	if (queueFlags & VK_QUEUE_COMPUTE_BIT)
	{
		for (const auto& properties : m_queueFamilyProperties)
		{
			if ((properties.queueFlags & queueFlags) && ((properties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0))
			{
				return index;
			}
			++index;
		}
	}

	// Dedicated queue for transfer
	// Try to find a queue family index that supports transfer but not graphics and compute
	if (queueFlags & VK_QUEUE_TRANSFER_BIT)
	{
		index = 0;
		for (const auto& properties : m_queueFamilyProperties)
		{
			if ((properties.queueFlags & queueFlags) && ((properties.queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0) && ((properties.queueFlags & VK_QUEUE_COMPUTE_BIT) == 0))
			{
				return index;
			}
			++index;
		}
	}

	// For other queue types or if no separate compute queue is present, return the first one to support the requested flags
	index = 0;
	for (const auto& properties : m_queueFamilyProperties)
	{
		if (properties.queueFlags & queueFlags)
		{
			return index;
		}
		++index;
	}

	throw runtime_error("Could not find a matching queue family index");
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