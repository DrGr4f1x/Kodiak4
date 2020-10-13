//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#pragma once

namespace VkFunc
{

// Base instance functions
PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* pName);
VkResult EnumerateInstanceVersion(uint32_t* pApiVersion);
VkResult EnumerateInstanceExtensionProperties(
	const char* pLayerName,
	uint32_t* pPropertyCount,
	VkExtensionProperties* pProperties);
VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties);
VkResult CreateInstance(
	const VkInstanceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkInstance* pInstance);


// Vulkan 1.0 instance functions
PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* pName);
void DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator);
VkResult EnumeratePhysicalDevices(
	VkInstance instance,
	uint32_t* pPhysicalDeviceCount,
	VkPhysicalDevice* pPhysicalDevices);
void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures);
void GetPhysicalDeviceFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkFormatProperties* pFormatProperties);
VkResult GetPhysicalDeviceImageFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkImageType type,
	VkImageTiling tiling,
	VkImageUsageFlags usage,
	VkImageCreateFlags flags,
	VkImageFormatProperties* pImageFormatProperties);
void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties);
void GetPhysicalDeviceQueueFamilyProperties(
	VkPhysicalDevice physicalDevice,
	uint32_t* pQueueFamilyPropertyCount,
	VkQueueFamilyProperties* pQueueFamilyProperties);
void GetPhysicalDeviceMemoryProperties(
	VkPhysicalDevice physicalDevice,
	VkPhysicalDeviceMemoryProperties* pMemoryProperties);
void GetPhysicalDeviceSparseImageFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkImageType type,
	VkSampleCountFlagBits samples,
	VkImageUsageFlags usage,
	VkImageTiling tiling,
	uint32_t* pPropertyCount,
	VkSparseImageFormatProperties* pProperties);
VkResult CreateDevice(
	VkPhysicalDevice physicalDevice,
	const VkDeviceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDevice* pDevice);


// Vulkan 1.1 instance functions
VkResult EnumeratePhysicalDeviceGroups(
	VkInstance instance,
	uint32_t* pPhysicalDeivceGroupCount,
	VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties);
void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures);
void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties);
void GetPhysicalDeviceFormatProperties2(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkFormatProperties2* pFormatProperties);
VkResult GetPhysicalDeviceImageFormatProperties2(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
	VkImageFormatProperties2* pImageFormatProperties);
void GetPhysicalDeviceQueueFamilyProperties2(
	VkPhysicalDevice physicalDevice,
	uint32_t* pQueueFamilyPropertyCount,
	VkQueueFamilyProperties2* pQueueFamilyProperties);
void GetPhysicalDeviceMemoryProperties2(
	VkPhysicalDevice physicalDevice,
	VkPhysicalDeviceMemoryProperties2* pMemoryProperties);
void GetPhysicalDeviceExternalBufferProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
	VkExternalBufferProperties* pExternalBufferProperties);
void GetPhysicalDeviceExternalFenceProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
	VkExternalFenceProperties* pExternalFenceProperties);
void GetPhysicalDeviceExternalSemaphoreProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
	VkExternalSemaphoreProperties* pExternalSemaphoreProperties);


// Vulkan 1.0 device functions
void DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator);
void GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue);
VkResult DeviceWaitIdle(VkDevice device);
VkResult AllocateMemory(
	VkDevice device,
	const VkMemoryAllocateInfo* pAllocateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDeviceMemory* pMemory);
void FreeMemory(VkDevice device, VkDeviceMemory memory,	const VkAllocationCallbacks* pAllocator);
VkResult MapMemory(
	VkDevice device,
	VkDeviceMemory memory,
	VkDeviceSize offset,
	VkDeviceSize size,
	VkMemoryMapFlags flags,
	void** ppData);
void UnmapMemory(VkDevice device, VkDeviceMemory memory);
VkResult FlushMappedMemoryRanges(
	VkDevice device,
	uint32_t memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges);

// Core queue functions

// Core command buffer functions

} // namespace VK