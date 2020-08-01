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

#include "StructuresVk.h"
#include "UtilityVk.h"


using namespace Kodiak;
using namespace std;


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

	// TODO: Validate the requested extensions and layers against the lists of available extensions and layers

	const vector<const char*> instanceExtensions =
	{
#if ENABLE_VULKAN_VALIDATION
			VK_EXT_DEBUG_REPORT_EXTENSION_NAME,
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