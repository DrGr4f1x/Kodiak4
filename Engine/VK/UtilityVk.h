//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author: David Elder
//

#pragma once

namespace Kodiak
{

std::vector<VkLayerProperties> EnumerateInstanceLayers()
{
	std::vector<VkLayerProperties> properties;
	uint32_t numLayers = 0;

	ThrowIfFailed(vkEnumerateInstanceLayerProperties(&numLayers, nullptr));

	if (numLayers > 0)
	{
		properties.resize(numLayers);
		ThrowIfFailed(vkEnumerateInstanceLayerProperties(&numLayers, properties.data()));
	}

	return properties;
}


std::vector<VkExtensionProperties> EnumerateInstanceExtensions(const char* pLayerName = nullptr)
{
	std::vector<VkExtensionProperties> properties;
	uint32_t numExtensions = 0;

	ThrowIfFailed(vkEnumerateInstanceExtensionProperties(pLayerName, &numExtensions, nullptr));

	if (numExtensions > 0)
	{
		properties.resize(numExtensions);
		ThrowIfFailed(vkEnumerateInstanceExtensionProperties(pLayerName, &numExtensions, properties.data()));
	}

	return properties;
}


std::vector<VkPhysicalDevice> EnumeratePhysicalDevices(VkInstance instance)
{
	std::vector<VkPhysicalDevice> devices;
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


std::vector<VkExtensionProperties> EnumerateDeviceExtensions(VkPhysicalDevice device)
{
	std::vector<VkExtensionProperties> extensions;
	uint32_t numExtensions = 0;

	ThrowIfFailed(vkEnumerateDeviceExtensionProperties(device, nullptr, &numExtensions, nullptr));

	if (numExtensions > 0)
	{
		extensions.resize(numExtensions);
		ThrowIfFailed(vkEnumerateDeviceExtensionProperties(device, nullptr, &numExtensions, extensions.data()));
	}

	return extensions;
}


std::vector<VkQueueFamilyProperties> EnumerateQueueFamilies(VkPhysicalDevice device)
{
	std::vector<VkQueueFamilyProperties> queueFamilies;
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