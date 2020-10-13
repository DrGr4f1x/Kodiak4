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


VkResult FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges)
{
	DECLARE_EXTERN_FUNCTION(vkFlushMappedMemoryRanges);
	return fp_vkFlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}


VkResult InvalidateMappedMemoryRanges(
	VkDevice device,
	uint32_t memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges)
{
	DECLARE_EXTERN_FUNCTION(vkInvalidateMappedMemoryRanges);
	return fp_vkInvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);
}


void GetDeviceMemoryCommitment(VkDevice device, VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes)
{
	DECLARE_EXTERN_FUNCTION(vkGetDeviceMemoryCommitment);
	fp_vkGetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);
}


VkResult BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	DECLARE_EXTERN_FUNCTION(vkBindBufferMemory);
	return fp_vkBindBufferMemory(device, buffer, memory, memoryOffset);
}


VkResult BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
	DECLARE_EXTERN_FUNCTION(vkBindImageMemory);
	return fp_vkBindImageMemory(device, image, memory, memoryOffset);
}


void GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements)
{
	DECLARE_EXTERN_FUNCTION(vkGetBufferMemoryRequirements);
	fp_vkGetBufferMemoryRequirements(device, buffer, pMemoryRequirements);
}


void GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements)
{
	DECLARE_EXTERN_FUNCTION(vkGetImageMemoryRequirements);
	fp_vkGetImageMemoryRequirements(device, image, pMemoryRequirements);
}


void GetImageSparseMemoryRequirements(
	VkDevice device,
	VkImage image,
	uint32_t* pSparseMemoryRequirementCount,
	VkSparseImageMemoryRequirements* pSparseMemoryRequirements)
{
	DECLARE_EXTERN_FUNCTION(vkGetImageSparseMemoryRequirements);
	fp_vkGetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}


VkResult CreateFence(
	VkDevice device,
	const VkFenceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkFence* pFence)
{
	DECLARE_EXTERN_FUNCTION(vkCreateFence);
	return fp_vkCreateFence(device, pCreateInfo, pAllocator, pFence);
}


void DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyFence);
	fp_vkDestroyFence(device, fence, pAllocator);
}


VkResult ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
	DECLARE_EXTERN_FUNCTION(vkResetFences);
	return fp_vkResetFences(device, fenceCount, pFences);
}


VkResult GetFenceStatus(VkDevice device, VkFence fence)
{
	DECLARE_EXTERN_FUNCTION(vkGetFenceStatus);
	return fp_vkGetFenceStatus(device, fence);
}


VkResult WaitForFences(
	VkDevice device,
	uint32_t fenceCount,
	const VkFence* pFences,
	VkBool32 waitAll,
	uint64_t timeout)
{
	DECLARE_EXTERN_FUNCTION(vkWaitForFences);
	return fp_vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}


VkResult CreateSemaphore(
	VkDevice device,
	const VkSemaphoreCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkSemaphore* pSemaphore)
{
	DECLARE_EXTERN_FUNCTION(vkCreateSemaphore);
	return fp_vkCreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);
}


void DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroySemaphore);
	fp_vkDestroySemaphore(device, semaphore, pAllocator);
}


VkResult CreateEvent(
	VkDevice device,
	const VkEventCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkEvent* pEvent)
{
	DECLARE_EXTERN_FUNCTION(vkCreateEvent);
	return fp_vkCreateEvent(device, pCreateInfo, pAllocator, pEvent);
}


void DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyEvent);
	fp_vkDestroyEvent(device, event, pAllocator);
}


VkResult GetEventStatus(VkDevice device, VkEvent event)
{
	DECLARE_EXTERN_FUNCTION(vkGetEventStatus);
	return fp_vkGetEventStatus(device, event);
}


VkResult SetEvent(VkDevice device, VkEvent event)
{
	DECLARE_EXTERN_FUNCTION(vkSetEvent);
	return fp_vkSetEvent(device, event);
}


VkResult ResetEvent(VkDevice device, VkEvent event)
{
	DECLARE_EXTERN_FUNCTION(vkResetEvent);
	return fp_vkResetEvent(device, event);
}


VkResult CreateQueryPool(
	VkDevice device,
	const VkQueryPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkQueryPool* pQueryPool)
{
	DECLARE_EXTERN_FUNCTION(vkCreateQueryPool);
	return fp_vkCreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);
}


void DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyQueryPool);
	fp_vkDestroyQueryPool(device, queryPool, pAllocator);
}


VkResult GetQueryPoolResults(
	VkDevice device,
	VkQueryPool queryPool,
	uint32_t firstQuery,
	uint32_t queryCount,
	size_t dataSize,
	void* pData,
	VkDeviceSize stride,
	VkQueryResultFlags flags)
{
	DECLARE_EXTERN_FUNCTION(vkGetQueryPoolResults);
	return fp_vkGetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);
}


VkResult CreateBuffer(
	VkDevice device,
	const VkBufferCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkBuffer* pBuffer)
{
	DECLARE_EXTERN_FUNCTION(vkCreateBuffer);
	return fp_vkCreateBuffer(device, pCreateInfo, pAllocator, pBuffer);
}


void DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyBuffer);
	fp_vkDestroyBuffer(device, buffer, pAllocator);
}

VkResult CreateBufferView(VkDevice device,
	const VkBufferViewCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkBufferView* pView)
{
	DECLARE_EXTERN_FUNCTION(vkCreateBufferView);
	return fp_vkCreateBufferView(device, pCreateInfo, pAllocator, pView);
}


void DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyBufferView);
	fp_vkDestroyBufferView(device, bufferView, pAllocator);
}


VkResult CreateImage(
	VkDevice device,
	const VkImageCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkImage* pImage)
{
	DECLARE_EXTERN_FUNCTION(vkCreateImage);
	return fp_vkCreateImage(device, pCreateInfo, pAllocator, pImage);
}


void DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyImage);
	fp_vkDestroyImage(device, image, pAllocator);
}


void GetImageSubresourceLayout(
	VkDevice device,
	VkImage image,
	const VkImageSubresource* pSubresource,
	VkSubresourceLayout* pLayout)
{
	DECLARE_EXTERN_FUNCTION(vkGetImageSubresourceLayout);
	fp_vkGetImageSubresourceLayout(device, image, pSubresource, pLayout);
}


VkResult CreateImageView(
	VkDevice device,
	const VkImageViewCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkImageView* pView)
{
	DECLARE_EXTERN_FUNCTION(vkCreateImageView);
	return fp_vkCreateImageView(device, pCreateInfo, pAllocator, pView);
}


void DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyImageView);
	fp_vkDestroyImageView(device, imageView, pAllocator);
}


VkResult CreateShaderModule(
	VkDevice device,
	const VkShaderModuleCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkShaderModule* pShaderModule)
{
	DECLARE_EXTERN_FUNCTION(vkCreateShaderModule);
	return fp_vkCreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);
}


void DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyShaderModule);
	fp_vkDestroyShaderModule(device, shaderModule, pAllocator);
}


VkResult CreatePipelineCache(
	VkDevice device,
	const VkPipelineCacheCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkPipelineCache* pPipelineCache)
{
	DECLARE_EXTERN_FUNCTION(vkCreatePipelineCache);
	return fp_vkCreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);
}


void DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyPipelineCache);
	fp_vkDestroyPipelineCache(device, pipelineCache, pAllocator);
}


VkResult GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData)
{
	DECLARE_EXTERN_FUNCTION(vkGetPipelineCacheData);
	return fp_vkGetPipelineCacheData(device, pipelineCache, pDataSize, pData);
}


VkResult MergePipelineCaches(
	VkDevice device,
	VkPipelineCache dstCache,
	uint32_t srcCacheCount,
	const VkPipelineCache* pSrcCaches)
{
	DECLARE_EXTERN_FUNCTION(vkMergePipelineCaches);
	return fp_vkMergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);
}


VkResult CreateGraphicsPipelines(
	VkDevice device,
	VkPipelineCache pipelineCache,
	uint32_t createInfoCount,
	const VkGraphicsPipelineCreateInfo* pCreateInfos,
	const VkAllocationCallbacks* pAllocator,
	VkPipeline* pPipelines)
{
	DECLARE_EXTERN_FUNCTION(vkCreateGraphicsPipelines);
	return fp_vkCreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}


VkResult CreateComputePipelines(
	VkDevice device,
	VkPipelineCache pipelineCache,
	uint32_t createInfoCount,
	const VkComputePipelineCreateInfo* pCreateInfos,
	const VkAllocationCallbacks* pAllocator,
	VkPipeline* pPipelines)
{
	DECLARE_EXTERN_FUNCTION(vkCreateComputePipelines);
	return fp_vkCreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);
}


void DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyPipeline);
	return fp_vkDestroyPipeline(device, pipeline, pAllocator);
}


VkResult CreatePipelineLayout(
	VkDevice device,
	const VkPipelineLayoutCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkPipelineLayout* pPipelineLayout)
{
	DECLARE_EXTERN_FUNCTION(vkCreatePipelineLayout);
	return fp_vkCreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);
}


void DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyPipelineLayout);
	fp_vkDestroyPipelineLayout(device, pipelineLayout, pAllocator);
}


VkResult CreateSampler(
	VkDevice device,
	const VkSamplerCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkSampler* pSampler)
{
	DECLARE_EXTERN_FUNCTION(vkCreateSampler);
	return fp_vkCreateSampler(device, pCreateInfo, pAllocator, pSampler);
}


void DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroySampler);
	fp_vkDestroySampler(device, sampler, pAllocator);
}


VkResult CreateDescriptorSetLayout(
	VkDevice device,
	const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDescriptorSetLayout* pSetLayout)
{
	DECLARE_EXTERN_FUNCTION(vkCreateDescriptorSetLayout);
	return fp_vkCreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);
}


void DestroyDescriptorSetLayout(
	VkDevice device,
	VkDescriptorSetLayout descriptorSetLayout,
	const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyDescriptorSetLayout);
	fp_vkDestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);
}


VkResult CreateDescriptorPool(
	VkDevice device,
	const VkDescriptorPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDescriptorPool* pDescriptorPool)
{
	DECLARE_EXTERN_FUNCTION(vkCreateDescriptorPool);
	return fp_vkCreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);
}


void DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyDescriptorPool);
	fp_vkDestroyDescriptorPool(device, descriptorPool, pAllocator);
}


VkResult ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags)
{
	DECLARE_EXTERN_FUNCTION(vkResetDescriptorPool);
	return fp_vkResetDescriptorPool(device, descriptorPool, flags);
}


VkResult AllocateDescriptorSets(
	VkDevice device,
	const VkDescriptorSetAllocateInfo* pAllocateInfo,
	VkDescriptorSet* pDescriptorSets)
{
	DECLARE_EXTERN_FUNCTION(vkAllocateDescriptorSets);
	return fp_vkAllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);
}


VkResult FreeDescriptorSets(
	VkDevice device,
	VkDescriptorPool descriptorPool,
	uint32_t descriptorSetCount,
	const VkDescriptorSet* pDescriptorSets)
{
	DECLARE_EXTERN_FUNCTION(vkFreeDescriptorSets);
	return fp_vkFreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);
}


void UpdateDescriptorSets(
	VkDevice device,
	uint32_t descriptorWriteCount,
	const VkWriteDescriptorSet* pDescriptorWrites,
	uint32_t descriptorCopyCount,
	const VkCopyDescriptorSet* pDescriptorCopies)
{
	DECLARE_EXTERN_FUNCTION(vkUpdateDescriptorSets);
	fp_vkUpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}


VkResult CreateFramebuffer(
	VkDevice device,
	const VkFramebufferCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkFramebuffer* pFramebuffer)
{
	DECLARE_EXTERN_FUNCTION(vkCreateFramebuffer);
	return fp_vkCreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);
}


void DestroyFramebuffer(
	VkDevice device,
	VkFramebuffer framebuffer,
	const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyFramebuffer);
	fp_vkDestroyFramebuffer(device, framebuffer, pAllocator);
}


VkResult CreateRenderPass(
	VkDevice device,
	const VkRenderPassCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkRenderPass* pRenderPass)
{
	DECLARE_EXTERN_FUNCTION(vkCreateRenderPass);
	return fp_vkCreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);
}


void DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyRenderPass);
	fp_vkDestroyRenderPass(device, renderPass, pAllocator);
}


void GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass, VkExtent2D* pGranularity)
{
	DECLARE_EXTERN_FUNCTION(vkGetRenderAreaGranularity);
	fp_vkGetRenderAreaGranularity(device, renderPass, pGranularity);
}


VkResult CreateCommandPool(
	VkDevice device,
	const VkCommandPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkCommandPool* pCommandPool)
{
	DECLARE_EXTERN_FUNCTION(vkCreateCommandPool);
	return fp_vkCreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);
}


void DestroyCommandPool(VkDevice device, VkCommandPool commandPool, const VkAllocationCallbacks* pAllocator)
{
	DECLARE_EXTERN_FUNCTION(vkDestroyCommandPool);
	fp_vkDestroyCommandPool(device, commandPool, pAllocator);
}


VkResult ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags)
{
	DECLARE_EXTERN_FUNCTION(vkResetCommandPool);
	return fp_vkResetCommandPool(device, commandPool, flags);
}


VkResult AllocateCommandBuffers(
	VkDevice device,
	const VkCommandBufferAllocateInfo* pAllocateInfo,
	VkCommandBuffer* pCommandBuffers)
{
	DECLARE_EXTERN_FUNCTION(vkAllocateCommandBuffers);
	return fp_vkAllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);
}


void FreeCommandBuffers(
	VkDevice device,
	VkCommandPool commandPool,
	uint32_t commandBufferCount,
	const VkCommandBuffer* pCommandBuffers)
{
	DECLARE_EXTERN_FUNCTION(vkFreeCommandBuffers);
	fp_vkFreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);
}


VkResult QueueSubmit(
	VkQueue queue,
	uint32_t submitCount,
	const VkSubmitInfo* pSubmits,
	VkFence fence)
{
	DECLARE_EXTERN_FUNCTION(vkQueueSubmit);
	return fp_vkQueueSubmit(queue, submitCount, pSubmits, fence);
}


VkResult QueueWaitIdle(VkQueue queue)
{
	DECLARE_EXTERN_FUNCTION(vkQueueWaitIdle);
	return fp_vkQueueWaitIdle(queue);
}


VkResult QueueBindSparse(
	VkQueue queue,
	uint32_t bindInfoCount,
	const VkBindSparseInfo* pBindInfo,
	VkFence fence)
{
	DECLARE_EXTERN_FUNCTION(vkQueueBindSparse);
	return fp_vkQueueBindSparse(queue, bindInfoCount, pBindInfo, fence);
}

} // namespace VK


#undef DECLARE_EXTERN_FUNCTION