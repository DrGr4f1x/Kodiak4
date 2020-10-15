//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author: David Elder
//

#include "Stdafx.h"

#include "UtilityVk.h"


using namespace std;


namespace Kodiak
{

vector<VkLayerProperties> EnumerateInstanceLayers()
{
	vector<VkLayerProperties> properties;
	uint32_t numLayers = 0;

	ThrowIfFailed(VkFunc::EnumerateInstanceLayerProperties(&numLayers, nullptr));

	if (numLayers > 0)
	{
		properties.resize(numLayers);
		ThrowIfFailed(VkFunc::EnumerateInstanceLayerProperties(&numLayers, properties.data()));
	}

	return properties;
}


vector<VkExtensionProperties> EnumerateInstanceExtensions(const char* pLayerName)
{
	vector<VkExtensionProperties> properties;
	uint32_t numExtensions = 0;

	ThrowIfFailed(VkFunc::EnumerateInstanceExtensionProperties(pLayerName, &numExtensions, nullptr));

	if (numExtensions > 0)
	{
		properties.resize(numExtensions);
		ThrowIfFailed(VkFunc::EnumerateInstanceExtensionProperties(pLayerName, &numExtensions, properties.data()));
	}

	return properties;
}


vector<VkPhysicalDevice> EnumeratePhysicalDevices(VkInstance instance)
{
	vector<VkPhysicalDevice> devices;
	uint32_t numDevices = 0;

	ThrowIfFailed(vkEnumeratePhysicalDevices(instance, &numDevices, nullptr));
	assert(numDevices > 0);

	devices.resize(numDevices);
	auto res = vkEnumeratePhysicalDevices(instance, &numDevices, devices.data());
	if (res)
	{
		Utility::ExitFatal("Could not enumerate physical devices", "Fatal error");
	}

	return devices;
}


vector<VkExtensionProperties> EnumerateDeviceExtensions(VkPhysicalDevice device)
{
	vector<VkExtensionProperties> extensions;
	uint32_t numExtensions = 0;

	ThrowIfFailed(vkEnumerateDeviceExtensionProperties(device, nullptr, &numExtensions, nullptr));

	if (numExtensions > 0)
	{
		extensions.resize(numExtensions);
		ThrowIfFailed(vkEnumerateDeviceExtensionProperties(device, nullptr, &numExtensions, extensions.data()));
	}

	return extensions;
}


vector<VkQueueFamilyProperties> EnumerateQueueFamilies(VkPhysicalDevice device)
{
	vector<VkQueueFamilyProperties> queueFamilies;
	uint32_t numQueueFamilies = 0;

	vkGetPhysicalDeviceQueueFamilyProperties(device, &numQueueFamilies, nullptr);
	assert(numQueueFamilies > 0);

	if (numQueueFamilies > 0)
	{
		queueFamilies.resize(numQueueFamilies);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &numQueueFamilies, queueFamilies.data());
	}

	return queueFamilies;
}


vector<VkSurfaceFormatKHR> EnumerateSurfaceFormats(VkPhysicalDevice device, VkSurfaceKHR surface)
{
	vector<VkSurfaceFormatKHR> surfaceFormats;
	uint32_t numFormats = 0;

	ThrowIfFailed(vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &numFormats, nullptr));
	assert(numFormats > 0);

	if (numFormats > 0)
	{
		surfaceFormats.resize(numFormats);
		ThrowIfFailed(vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &numFormats, surfaceFormats.data()));
	}

	return surfaceFormats;
}


vector<VkPresentModeKHR> EnumeratePresentModes(VkPhysicalDevice device, VkSurfaceKHR surface)
{
	vector<VkPresentModeKHR> presentModes;
	uint32_t numPresentModes = 0;

	ThrowIfFailed(vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &numPresentModes, nullptr));
	assert(numPresentModes > 0);

	if (numPresentModes > 0)
	{
		presentModes.resize(numPresentModes);
		ThrowIfFailed(vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &numPresentModes, presentModes.data()));
	}

	return presentModes;
}


void LogApplicationInfo(const VkApplicationInfo& appInfo)
{
	LOG_NOTICE << "  Vulkan application info";
	LOG_NOTICE << "    Application name: " << appInfo.pApplicationName;
	LOG_NOTICE << "    API version: " << VK_VERSION_MAJOR(appInfo.apiVersion) << "." << VK_VERSION_MINOR(appInfo.apiVersion)
		<< "." << VK_VERSION_PATCH(appInfo.apiVersion);
	LOG_NOTICE << "    Engine name: " << appInfo.pEngineName;
	LOG_NOTICE << "    Engine version: " << KODIAK_VERSION_MAJOR(appInfo.engineVersion) << "." <<
		KODIAK_VERSION_MINOR(appInfo.engineVersion) << "." << KODIAK_VERSION_PATCH(appInfo.engineVersion) << std::endl;
}


void LogPhysicalDeviceProperties(VkPhysicalDeviceProperties properties)
{
	LOG_NOTICE << "  Physical device properties";
	LOG_NOTICE << "    API version: " << VK_VERSION_MAJOR(properties.apiVersion) << "." << VK_VERSION_MINOR(properties.apiVersion)
		<< "." << VK_VERSION_PATCH(properties.apiVersion);
	LOG_NOTICE << "    Driver version: " << properties.driverVersion;
	LOG_NOTICE << "    Vendor: " << VendorIdToGpuVendor(properties.vendorID);
	switch (properties.deviceType)
	{
	case VK_PHYSICAL_DEVICE_TYPE_OTHER:
		LOG_NOTICE << "    Device type: OTHER";
		break;

	case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
		LOG_NOTICE << "    Device type: INTEGRATED_GPU";
		break;

	case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
		LOG_NOTICE << "    Device type: DISCRETE_GPU";
		break;

	case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
		LOG_NOTICE << "    Device type: VIRTUAL_GPU";
		break;

	case VK_PHYSICAL_DEVICE_TYPE_CPU:
		LOG_NOTICE << "    Device type: CPU";
		break;
	}
	LOG_NOTICE << "    Device name: " << properties.deviceName << std::endl;
}

} // namespace Kodiak