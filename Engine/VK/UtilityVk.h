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

std::vector<VkLayerProperties> EnumerateInstanceLayers();
std::vector<VkExtensionProperties> EnumerateInstanceExtensions(const char* pLayerName = nullptr);
std::vector<VkPhysicalDevice> EnumeratePhysicalDevices(VkInstance instance);
std::vector<VkExtensionProperties> EnumerateDeviceExtensions(VkPhysicalDevice device);
std::vector<VkQueueFamilyProperties> EnumerateQueueFamilies(VkPhysicalDevice device);
std::vector<VkSurfaceFormatKHR> EnumerateSurfaceFormats(VkPhysicalDevice device, VkSurfaceKHR surface);
std::vector<VkPresentModeKHR> EnumeratePresentModes(VkPhysicalDevice device, VkSurfaceKHR surface);


void LogApplicationInfo(const VkApplicationInfo& appInfo);
void LogPhysicalDeviceProperties(VkPhysicalDeviceProperties properties);

} // namespace Kodiak