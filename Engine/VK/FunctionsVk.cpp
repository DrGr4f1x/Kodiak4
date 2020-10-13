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

#include "FunctionsVk.h"

using namespace std;
using namespace Kodiak;

#define DECLARE_EXTERN_FUNCTION(name) \
extern PFN_##name fp_##name; \
VALIDATE_FUNCTION_POINTER(fp_##name)


namespace VkFunc
{

PFN_vkVoidFunction GetInstanceProcAddr(VkInstance instance, const char* pName)
{
	DECLARE_EXTERN_FUNCTION(vkGetInstanceProcAddr);
	return fp_vkGetInstanceProcAddr(instance, pName);
}


VkResult EnumerateInstanceVersion(uint32_t* pApiVersion)
{
	DECLARE_EXTERN_FUNCTION(vkEnumerateInstanceVersion);
	return fp_vkEnumerateInstanceVersion(pApiVersion);
}


VkResult EnumerateInstanceExtensionProperties(
	const char* pLayerName,
	uint32_t* pPropertyCount,
	VkExtensionProperties* pProperties)
{
	DECLARE_EXTERN_FUNCTION(vkEnumerateInstanceExtensionProperties);
	return fp_vkEnumerateInstanceExtensionProperties(pLayerName, pPropertyCount, pProperties);
}


VkResult EnumerateInstanceLayerProperties(uint32_t* pPropertyCount, VkLayerProperties* pProperties)
{
	DECLARE_EXTERN_FUNCTION(vkEnumerateInstanceLayerProperties);
	return fp_vkEnumerateInstanceLayerProperties(pPropertyCount, pProperties);
}


VkResult CreateInstance(
	const VkInstanceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkInstance* pInstance)
{
	DECLARE_EXTERN_FUNCTION(vkCreateInstance);
	return fp_vkCreateInstance(pCreateInfo, pAllocator, pInstance);
}


PFN_vkVoidFunction GetDeviceProcAddr(VkDevice device, const char* pName)
{
	DECLARE_EXTERN_FUNCTION(vkGetDeviceProcAddr);
	return fp_vkGetDeviceProcAddr(device, pName);
}


void DestroyInstance(VkInstance instance, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyInstance);
	fp_vkDestroyInstance(instance, pAllocator);
}


VkResult EnumeratePhysicalDevices(
	VkInstance instance,
	uint32_t* pPhysicalDeviceCount,
	VkPhysicalDevice* pPhysicalDevices)
{
	DECLARE_EXTERN_FUNCTION(vkEnumeratePhysicalDevices);
	return fp_vkEnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);
}


void GetPhysicalDeviceFeatures(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures* pFeatures)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceFeatures);
	fp_vkGetPhysicalDeviceFeatures(physicalDevice, pFeatures);
}


void GetPhysicalDeviceFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkFormatProperties* pFormatProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceFormatProperties);
	fp_vkGetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);
}


VkResult GetPhysicalDeviceImageFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkImageType type,
	VkImageTiling tiling,
	VkImageUsageFlags usage,
	VkImageCreateFlags flags,
	VkImageFormatProperties* pImageFormatProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
	return fp_vkGetPhysicalDeviceImageFormatProperties(
		physicalDevice,
		format,
		type,
		tiling,
		usage,
		flags,
		pImageFormatProperties);
}


void GetPhysicalDeviceProperties(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties* pProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceProperties);
	fp_vkGetPhysicalDeviceProperties(physicalDevice, pProperties);
}


void GetPhysicalDeviceQueueFamilyProperties(
	VkPhysicalDevice physicalDevice,
	uint32_t* pQueueFamilyPropertyCount,
	VkQueueFamilyProperties* pQueueFamilyProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
	fp_vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}


void GetPhysicalDeviceMemoryProperties(
	VkPhysicalDevice physicalDevice,
	VkPhysicalDeviceMemoryProperties* pMemoryProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
	fp_vkGetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);
}


void GetPhysicalDeviceSparseImageFormatProperties(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkImageType type,
	VkSampleCountFlagBits samples,
	VkImageUsageFlags usage,
	VkImageTiling tiling,
	uint32_t* pPropertyCount,
	VkSparseImageFormatProperties* pProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties);
	fp_vkGetPhysicalDeviceSparseImageFormatProperties(
		physicalDevice,
		format,
		type,
		samples,
		usage,
		tiling,
		pPropertyCount,
		pProperties);
}


VkResult CreateDevice(
	VkPhysicalDevice physicalDevice,
	const VkDeviceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDevice* pDevice)
{
	DECLARE_EXTERN_FUNCTION(vkCreateDevice);
	return fp_vkCreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);
}


VkResult EnumeratePhysicalDeviceGroups(
	VkInstance instance,
	uint32_t* pPhysicalDeivceGroupCount,
	VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
	DECLARE_EXTERN_FUNCTION(vkEnumeratePhysicalDeviceGroups);
	return fp_vkEnumeratePhysicalDeviceGroups(instance, pPhysicalDeivceGroupCount, pPhysicalDeviceGroupProperties);
}


void GetPhysicalDeviceFeatures2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceFeatures2* pFeatures)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceFeatures2);
	fp_vkGetPhysicalDeviceFeatures2(physicalDevice, pFeatures);
}


void GetPhysicalDeviceProperties2(VkPhysicalDevice physicalDevice, VkPhysicalDeviceProperties2* pProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceProperties2);
	fp_vkGetPhysicalDeviceProperties2(physicalDevice, pProperties);
}


void GetPhysicalDeviceFormatProperties2(
	VkPhysicalDevice physicalDevice,
	VkFormat format,
	VkFormatProperties2* pFormatProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceFormatProperties2);
	fp_vkGetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);
}


VkResult GetPhysicalDeviceImageFormatProperties2(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceImageFormatInfo2* pImageFormatInfo,
	VkImageFormatProperties2* pImageFormatProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceImageFormatProperties2);
	return fp_vkGetPhysicalDeviceImageFormatProperties2(
		physicalDevice,
		pImageFormatInfo,
		pImageFormatProperties);
}


void GetPhysicalDeviceQueueFamilyProperties2(
	VkPhysicalDevice physicalDevice,
	uint32_t* pQueueFamilyPropertyCount,
	VkQueueFamilyProperties2* pQueueFamilyProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties2);
	fp_vkGetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}


void GetPhysicalDeviceMemoryProperties2(
	VkPhysicalDevice physicalDevice,
	VkPhysicalDeviceMemoryProperties2* pMemoryProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceMemoryProperties2);
	fp_vkGetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);
}


void GetPhysicalDeviceExternalBufferProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalBufferInfo* pExternalBufferInfo,
	VkExternalBufferProperties* pExternalBufferProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceExternalBufferProperties);
	fp_vkGetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}


void GetPhysicalDeviceExternalFenceProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalFenceInfo* pExternalFenceInfo,
	VkExternalFenceProperties* pExternalFenceProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceExternalFenceProperties);
	fp_vkGetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}


void GetPhysicalDeviceExternalSemaphoreProperties(
	VkPhysicalDevice physicalDevice,
	const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
	VkExternalSemaphoreProperties* pExternalSemaphoreProperties)
{
	DECLARE_EXTERN_FUNCTION(vkGetPhysicalDeviceExternalSemaphoreProperties);
	fp_vkGetPhysicalDeviceExternalSemaphoreProperties(
		physicalDevice,
		pExternalSemaphoreInfo,
		pExternalSemaphoreProperties);
}


void DestroyDevice(VkDevice device, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyDevice);
	fp_vkDestroyDevice(device, pAllocator);
}


void GetDeviceQueue(VkDevice device, uint32_t queueFamilyIndex, uint32_t queueIndex, VkQueue* pQueue)
{
	DECLARE_EXTERN_FUNCTION(vkGetDeviceQueue);
	fp_vkGetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);
}


VkResult DeviceWaitIdle(VkDevice device)
{
	DECLARE_EXTERN_FUNCTION(vkDeviceWaitIdle);
	return fp_vkDeviceWaitIdle(device);
}


VkResult AllocateMemory(
	VkDevice device,
	const VkMemoryAllocateInfo* pAllocateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDeviceMemory* pMemory)
{
	DECLARE_EXTERN_FUNCTION(vkAllocateMemory);
	return fp_vkAllocateMemory(device, pAllocateInfo, pAllocator, pMemory);
}


void FreeMemory(VkDevice device, VkDeviceMemory memory, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkFreeMemory);
	fp_vkFreeMemory(device, memory, pAllocator);
}


VkResult MapMemory(
	VkDevice device,
	VkDeviceMemory memory,
	VkDeviceSize offset,
	VkDeviceSize size,
	VkMemoryMapFlags flags,
	void** ppData)
{
	DECLARE_EXTERN_FUNCTION(vkMapMemory);
	return vkMapMemory(device, memory, offset, size, flags, ppData);
}


void UnmapMemory(VkDevice device, VkDeviceMemory deviceMemory)
{
	DECLARE_EXTERN_FUNCTION(vkUnmapMemory);
	fp_vkUnmapMemory(device, deviceMemory);
}


VkResult FlushMappedMemoryRanges(
	VkDevice device,
	uint32_t memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges)
{
	DECLARE_EXTERN_FUNCTION(vkFlushMappedMemoryRanges);
	return fp_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}

} // namespace VK


#undef DECLARE_EXTERN_FUNCTION