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

#include "LoaderVk.h"

#include "FunctionsVk.h"


using namespace std;


#define DECLARE_FUNCTION(name) \
PFN_##name fp_##name = nullptr

#define LOAD_FUNCTION(name) \
fp_##name = (PFN_##name)vkGetInstanceProcAddr(VK_NULL_HANDLE, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)

#define LOAD_INSTANCE_FUNCTION(name) \
fp_##name = (PFN_##name)VkFunc::GetInstanceProcAddr(instance, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)

#define LOAD_DEVICE_FUNCTION(name) \
fp_##name = (PFN_##name)VkFunc::GetDeviceProcAddr(device, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)


// Base instance functions (can be loaded with NULL VkInstance handle)
DECLARE_FUNCTION(vkGetInstanceProcAddr);
DECLARE_FUNCTION(vkEnumerateInstanceVersion);
DECLARE_FUNCTION(vkEnumerateInstanceExtensionProperties);
DECLARE_FUNCTION(vkEnumerateInstanceLayerProperties);
DECLARE_FUNCTION(vkCreateInstance);


// Vulkan 1.0 instance functions
DECLARE_FUNCTION(vkGetDeviceProcAddr);
DECLARE_FUNCTION(vkDestroyInstance);
DECLARE_FUNCTION(vkEnumeratePhysicalDevices);
DECLARE_FUNCTION(vkGetPhysicalDeviceFeatures);
DECLARE_FUNCTION(vkGetPhysicalDeviceFormatProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
DECLARE_FUNCTION(vkCreateDevice);

// Vulkan 1.1 instance functions
DECLARE_FUNCTION(vkEnumeratePhysicalDeviceGroups);
DECLARE_FUNCTION(vkGetPhysicalDeviceFeatures2);
DECLARE_FUNCTION(vkGetPhysicalDeviceProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceFormatProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceMemoryProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties2);
DECLARE_FUNCTION(vkGetPhysicalDeviceExternalBufferProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceExternalFenceProperties);
DECLARE_FUNCTION(vkGetPhysicalDeviceExternalSemaphoreProperties);

// Vulkan 1.0 device functions
DECLARE_FUNCTION(vkDestroyDevice);
DECLARE_FUNCTION(vkGetDeviceQueue);
DECLARE_FUNCTION(vkDeviceWaitIdle);
DECLARE_FUNCTION(vkAllocateMemory);
DECLARE_FUNCTION(vkFreeMemory);
DECLARE_FUNCTION(vkMapMemory);
DECLARE_FUNCTION(vkUnmapMemory);
DECLARE_FUNCTION(vkFlushMappedMemoryRanges);
DECLARE_FUNCTION(vkInvalidateMappedMemoryRanges);
DECLARE_FUNCTION(vkGetDeviceMemoryCommitment);
DECLARE_FUNCTION(vkBindBufferMemory);
DECLARE_FUNCTION(vkBindImageMemory);
DECLARE_FUNCTION(vkGetBufferMemoryRequirements);
DECLARE_FUNCTION(vkGetImageMemoryRequirements);
DECLARE_FUNCTION(vkGetImageSparseMemoryRequirements);
DECLARE_FUNCTION(vkCreateFence);
DECLARE_FUNCTION(vkDestroyFence);
DECLARE_FUNCTION(vkResetFences);
DECLARE_FUNCTION(vkGetFenceStatus);
DECLARE_FUNCTION(vkWaitForFences);
DECLARE_FUNCTION(vkCreateSemaphore);
DECLARE_FUNCTION(vkDestroySemaphore);
DECLARE_FUNCTION(vkCreateEvent);
DECLARE_FUNCTION(vkDestroyEvent);
DECLARE_FUNCTION(vkGetEventStatus);
DECLARE_FUNCTION(vkSetEvent);
DECLARE_FUNCTION(vkResetEvent);
DECLARE_FUNCTION(vkCreateQueryPool);
DECLARE_FUNCTION(vkDestroyQueryPool);
DECLARE_FUNCTION(vkGetQueryPoolResults);
DECLARE_FUNCTION(vkCreateBuffer);
DECLARE_FUNCTION(vkDestroyBuffer);
DECLARE_FUNCTION(vkCreateBufferView);
DECLARE_FUNCTION(vkDestroyBufferView);
DECLARE_FUNCTION(vkCreateImage);
DECLARE_FUNCTION(vkDestroyImage);
DECLARE_FUNCTION(vkGetImageSubresourceLayout);
DECLARE_FUNCTION(vkCreateImageView);
DECLARE_FUNCTION(vkDestroyImageView);
DECLARE_FUNCTION(vkCreateShaderModule);
DECLARE_FUNCTION(vkDestroyShaderModule);
DECLARE_FUNCTION(vkCreatePipelineCache);
DECLARE_FUNCTION(vkDestroyPipelineCache);
DECLARE_FUNCTION(vkGetPipelineCacheData);
DECLARE_FUNCTION(vkMergePipelineCaches);
DECLARE_FUNCTION(vkCreateGraphicsPipelines);
DECLARE_FUNCTION(vkCreateComputePipelines);
DECLARE_FUNCTION(vkDestroyPipeline);
DECLARE_FUNCTION(vkCreatePipelineLayout);
DECLARE_FUNCTION(vkDestroyPipelineLayout);
DECLARE_FUNCTION(vkCreateSampler);
DECLARE_FUNCTION(vkDestroySampler);
DECLARE_FUNCTION(vkCreateDescriptorSetLayout);
DECLARE_FUNCTION(vkDestroyDescriptorSetLayout);
DECLARE_FUNCTION(vkCreateDescriptorPool);
DECLARE_FUNCTION(vkDestroyDescriptorPool);
DECLARE_FUNCTION(vkResetDescriptorPool);
DECLARE_FUNCTION(vkAllocateDescriptorSets);
DECLARE_FUNCTION(vkFreeDescriptorSets);
DECLARE_FUNCTION(vkUpdateDescriptorSets);
DECLARE_FUNCTION(vkCreateFramebuffer);
DECLARE_FUNCTION(vkDestroyFramebuffer);
DECLARE_FUNCTION(vkCreateRenderPass);
DECLARE_FUNCTION(vkDestroyRenderPass);
DECLARE_FUNCTION(vkGetRenderAreaGranularity);
DECLARE_FUNCTION(vkCreateCommandPool);
DECLARE_FUNCTION(vkDestroyCommandPool);
DECLARE_FUNCTION(vkResetCommandPool);
DECLARE_FUNCTION(vkAllocateCommandBuffers);
DECLARE_FUNCTION(vkFreeCommandBuffers);

DECLARE_FUNCTION(vkQueueSubmit);
DECLARE_FUNCTION(vkQueueWaitIdle);
DECLARE_FUNCTION(vkQueueBindSparse);

DECLARE_FUNCTION(vkBeginCommandBuffer);
DECLARE_FUNCTION(vkEndCommandBuffer);
DECLARE_FUNCTION(vkResetCommandBuffer);
DECLARE_FUNCTION(vkCmdBindPipeline);
DECLARE_FUNCTION(vkCmdSetViewport);
DECLARE_FUNCTION(vkCmdSetScissor);
DECLARE_FUNCTION(vkCmdSetLineWidth);
DECLARE_FUNCTION(vkCmdSetDepthBias);
DECLARE_FUNCTION(vkCmdSetBlendConstants);
DECLARE_FUNCTION(vkCmdSetDepthBounds);
DECLARE_FUNCTION(vkCmdSetStencilCompareMask);
DECLARE_FUNCTION(vkCmdSetStencilWriteMask);
DECLARE_FUNCTION(vkCmdSetStencilReference);
DECLARE_FUNCTION(vkCmdBindDescriptorSets);
DECLARE_FUNCTION(vkCmdBindIndexBuffer);
DECLARE_FUNCTION(vkCmdBindVertexBuffers);
DECLARE_FUNCTION(vkCmdDraw);
DECLARE_FUNCTION(vkCmdDrawIndexed);
DECLARE_FUNCTION(vkCmdDrawIndirect);
DECLARE_FUNCTION(vkCmdDrawIndexedIndirect);
DECLARE_FUNCTION(vkCmdDispatch);
DECLARE_FUNCTION(vkCmdDispatchIndirect);
DECLARE_FUNCTION(vkCmdCopyBuffer);
DECLARE_FUNCTION(vkCmdCopyImage);
DECLARE_FUNCTION(vkCmdBlitImage);
DECLARE_FUNCTION(vkCmdCopyBufferToImage);
DECLARE_FUNCTION(vkCmdCopyImageToBuffer);
DECLARE_FUNCTION(vkCmdUpdateBuffer);
DECLARE_FUNCTION(vkCmdFillBuffer);
DECLARE_FUNCTION(vkCmdClearColorImage);
DECLARE_FUNCTION(vkCmdClearDepthStencilImage);
DECLARE_FUNCTION(vkCmdClearAttachments);
DECLARE_FUNCTION(vkCmdResolveImage);
DECLARE_FUNCTION(vkCmdSetEvent);
DECLARE_FUNCTION(vkCmdResetEvent);
DECLARE_FUNCTION(vkCmdWaitEvents);
DECLARE_FUNCTION(vkCmdPipelineBarrier);
DECLARE_FUNCTION(vkCmdBeginQuery);
DECLARE_FUNCTION(vkCmdEndQuery);
DECLARE_FUNCTION(vkCmdResetQueryPool);
DECLARE_FUNCTION(vkCmdWriteTimestamp);
DECLARE_FUNCTION(vkCmdCopyQueryPoolResults);
DECLARE_FUNCTION(vkCmdPushConstants);
DECLARE_FUNCTION(vkCmdBeginRenderPass);
DECLARE_FUNCTION(vkCmdNextSubpass);
DECLARE_FUNCTION(vkCmdEndRenderPass);
DECLARE_FUNCTION(vkCmdExecuteCommands);


// Vulkan 1.1 device functions
DECLARE_FUNCTION(vkBindBufferMemory2);
DECLARE_FUNCTION(vkBindImageMemory2);
DECLARE_FUNCTION(vkGetDeviceGroupPeerMemoryFeatures);
DECLARE_FUNCTION(vkGetImageMemoryRequirements2);
DECLARE_FUNCTION(vkGetBufferMemoryRequirements2);
DECLARE_FUNCTION(vkGetImageSparseMemoryRequirements2);
DECLARE_FUNCTION(vkTrimCommandPool);
DECLARE_FUNCTION(vkGetDeviceQueue2);
DECLARE_FUNCTION(vkCreateSamplerYcbcrConversion);
DECLARE_FUNCTION(vkDestroySamplerYcbcrConversion);
DECLARE_FUNCTION(vkCreateDescriptorUpdateTemplate);
DECLARE_FUNCTION(vkDestroyDescriptorUpdateTemplate);
DECLARE_FUNCTION(vkUpdateDescriptorSetWithTemplate);
DECLARE_FUNCTION(vkGetDescriptorSetLayoutSupport);

DECLARE_FUNCTION(vkCmdSetDeviceMask);
DECLARE_FUNCTION(vkCmdDispatchBase);


// Vulkan 1.2 device functions
DECLARE_FUNCTION(vkCreateRenderPass2);
DECLARE_FUNCTION(vkResetQueryPool);
DECLARE_FUNCTION(vkGetSemaphoreCounterValue);
DECLARE_FUNCTION(vkWaitSemaphores);
DECLARE_FUNCTION(vkSignalSemaphore);
DECLARE_FUNCTION(vkGetBufferDeviceAddress);
DECLARE_FUNCTION(vkGetBufferOpaqueCaptureAddress);
DECLARE_FUNCTION(vkGetDeviceMemoryOpaqueCaptureAddress);

DECLARE_FUNCTION(vkCmdDrawIndirectCount);
DECLARE_FUNCTION(vkCmdDrawIndexedIndirectCount);
DECLARE_FUNCTION(vkCmdBeginRenderPass2);
DECLARE_FUNCTION(vkCmdNextSubpass2);
DECLARE_FUNCTION(vkCmdEndRenderPass2);


namespace Kodiak
{

void LoadCoreFunctionPointers()
{
	// Load vkGetInstanceProcAddr, so we can use it to load the rest of the instance functions
	LOAD_FUNCTION(vkGetInstanceProcAddr);

	// Load the remaining instance functions that don't require a live instance handle
	LOAD_FUNCTION(vkEnumerateInstanceVersion);
	LOAD_FUNCTION(vkEnumerateInstanceExtensionProperties);
	LOAD_FUNCTION(vkEnumerateInstanceLayerProperties);
	LOAD_FUNCTION(vkCreateInstance);
}


void LoadCoreInstanceFunctionPointers(VkInstance instance)
{
	// Vulkan 1.0 instance functions
	LOAD_INSTANCE_FUNCTION(vkGetDeviceProcAddr);
	LOAD_INSTANCE_FUNCTION(vkDestroyInstance);
	LOAD_INSTANCE_FUNCTION(vkEnumeratePhysicalDevices);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceFeatures);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceFormatProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
	LOAD_INSTANCE_FUNCTION(vkCreateDevice);

	// Vulkan 1.1 instance functions
	LOAD_INSTANCE_FUNCTION(vkEnumeratePhysicalDeviceGroups);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceFeatures2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceFormatProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceMemoryProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties2);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceExternalBufferProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceExternalFenceProperties);
	LOAD_INSTANCE_FUNCTION(vkGetPhysicalDeviceExternalSemaphoreProperties);
}


void LoadCoreDeviceFunctionPointers(VkDevice device)
{
	// Vulkan 1.0 device functions
	LOAD_DEVICE_FUNCTION(vkDestroyDevice);
	LOAD_DEVICE_FUNCTION(vkGetDeviceQueue);
	LOAD_DEVICE_FUNCTION(vkDeviceWaitIdle);
	LOAD_DEVICE_FUNCTION(vkAllocateMemory);
	LOAD_DEVICE_FUNCTION(vkFreeMemory);
	LOAD_DEVICE_FUNCTION(vkMapMemory);
	LOAD_DEVICE_FUNCTION(vkUnmapMemory);
	LOAD_DEVICE_FUNCTION(vkFlushMappedMemoryRanges);
	LOAD_DEVICE_FUNCTION(vkInvalidateMappedMemoryRanges);
	LOAD_DEVICE_FUNCTION(vkGetDeviceMemoryCommitment);
	LOAD_DEVICE_FUNCTION(vkBindBufferMemory);
	LOAD_DEVICE_FUNCTION(vkBindImageMemory);
	LOAD_DEVICE_FUNCTION(vkGetBufferMemoryRequirements);
	LOAD_DEVICE_FUNCTION(vkGetImageMemoryRequirements);
	LOAD_DEVICE_FUNCTION(vkGetImageSparseMemoryRequirements);
	LOAD_DEVICE_FUNCTION(vkCreateFence);
	LOAD_DEVICE_FUNCTION(vkDestroyFence);
	LOAD_DEVICE_FUNCTION(vkResetFences);
	LOAD_DEVICE_FUNCTION(vkGetFenceStatus);
	LOAD_DEVICE_FUNCTION(vkWaitForFences);
	LOAD_DEVICE_FUNCTION(vkCreateSemaphore);
	LOAD_DEVICE_FUNCTION(vkDestroySemaphore);
	LOAD_DEVICE_FUNCTION(vkCreateEvent);
	LOAD_DEVICE_FUNCTION(vkDestroyEvent);
	LOAD_DEVICE_FUNCTION(vkGetEventStatus);
	LOAD_DEVICE_FUNCTION(vkSetEvent);
	LOAD_DEVICE_FUNCTION(vkResetEvent);
	LOAD_DEVICE_FUNCTION(vkCreateQueryPool);
	LOAD_DEVICE_FUNCTION(vkDestroyQueryPool);
	LOAD_DEVICE_FUNCTION(vkGetQueryPoolResults);
	LOAD_DEVICE_FUNCTION(vkCreateBuffer);
	LOAD_DEVICE_FUNCTION(vkDestroyBuffer);
	LOAD_DEVICE_FUNCTION(vkCreateBufferView);
	LOAD_DEVICE_FUNCTION(vkDestroyBufferView);
	LOAD_DEVICE_FUNCTION(vkCreateImage);
	LOAD_DEVICE_FUNCTION(vkDestroyImage);
	LOAD_DEVICE_FUNCTION(vkGetImageSubresourceLayout);
	LOAD_DEVICE_FUNCTION(vkCreateImageView);
	LOAD_DEVICE_FUNCTION(vkDestroyImageView);
	LOAD_DEVICE_FUNCTION(vkCreateShaderModule);
	LOAD_DEVICE_FUNCTION(vkDestroyShaderModule);
	LOAD_DEVICE_FUNCTION(vkCreatePipelineCache);
	LOAD_DEVICE_FUNCTION(vkDestroyPipelineCache);
	LOAD_DEVICE_FUNCTION(vkGetPipelineCacheData);
	LOAD_DEVICE_FUNCTION(vkMergePipelineCaches);
	LOAD_DEVICE_FUNCTION(vkCreateGraphicsPipelines);
	LOAD_DEVICE_FUNCTION(vkCreateComputePipelines);
	LOAD_DEVICE_FUNCTION(vkDestroyPipeline);
	LOAD_DEVICE_FUNCTION(vkCreatePipelineLayout);
	LOAD_DEVICE_FUNCTION(vkDestroyPipelineLayout);
	LOAD_DEVICE_FUNCTION(vkCreateSampler);
	LOAD_DEVICE_FUNCTION(vkDestroySampler);
	LOAD_DEVICE_FUNCTION(vkCreateDescriptorSetLayout);
	LOAD_DEVICE_FUNCTION(vkDestroyDescriptorSetLayout);
	LOAD_DEVICE_FUNCTION(vkCreateDescriptorPool);
	LOAD_DEVICE_FUNCTION(vkDestroyDescriptorPool);
	LOAD_DEVICE_FUNCTION(vkResetDescriptorPool);
	LOAD_DEVICE_FUNCTION(vkAllocateDescriptorSets);
	LOAD_DEVICE_FUNCTION(vkFreeDescriptorSets);
	LOAD_DEVICE_FUNCTION(vkUpdateDescriptorSets);
	LOAD_DEVICE_FUNCTION(vkCreateFramebuffer);
	LOAD_DEVICE_FUNCTION(vkDestroyFramebuffer);
	LOAD_DEVICE_FUNCTION(vkCreateRenderPass);
	LOAD_DEVICE_FUNCTION(vkDestroyRenderPass);
	LOAD_DEVICE_FUNCTION(vkGetRenderAreaGranularity);
	LOAD_DEVICE_FUNCTION(vkCreateCommandPool);
	LOAD_DEVICE_FUNCTION(vkDestroyCommandPool);
	LOAD_DEVICE_FUNCTION(vkResetCommandPool);
	LOAD_DEVICE_FUNCTION(vkAllocateCommandBuffers);
	LOAD_DEVICE_FUNCTION(vkFreeCommandBuffers);

	LOAD_DEVICE_FUNCTION(vkQueueSubmit);
	LOAD_DEVICE_FUNCTION(vkQueueWaitIdle);
	LOAD_DEVICE_FUNCTION(vkQueueBindSparse);

	LOAD_DEVICE_FUNCTION(vkBeginCommandBuffer);
	LOAD_DEVICE_FUNCTION(vkEndCommandBuffer);
	LOAD_DEVICE_FUNCTION(vkResetCommandBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdBindPipeline);
	LOAD_DEVICE_FUNCTION(vkCmdSetViewport);
	LOAD_DEVICE_FUNCTION(vkCmdSetScissor);
	LOAD_DEVICE_FUNCTION(vkCmdSetLineWidth);
	LOAD_DEVICE_FUNCTION(vkCmdSetDepthBias);
	LOAD_DEVICE_FUNCTION(vkCmdSetBlendConstants);
	LOAD_DEVICE_FUNCTION(vkCmdSetDepthBounds);
	LOAD_DEVICE_FUNCTION(vkCmdSetStencilCompareMask);
	LOAD_DEVICE_FUNCTION(vkCmdSetStencilWriteMask);
	LOAD_DEVICE_FUNCTION(vkCmdSetStencilReference);
	LOAD_DEVICE_FUNCTION(vkCmdBindDescriptorSets);
	LOAD_DEVICE_FUNCTION(vkCmdBindIndexBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdBindVertexBuffers);
	LOAD_DEVICE_FUNCTION(vkCmdDraw);
	LOAD_DEVICE_FUNCTION(vkCmdDrawIndexed);
	LOAD_DEVICE_FUNCTION(vkCmdDrawIndirect);
	LOAD_DEVICE_FUNCTION(vkCmdDrawIndexedIndirect);
	LOAD_DEVICE_FUNCTION(vkCmdDispatch);
	LOAD_DEVICE_FUNCTION(vkCmdDispatchIndirect);
	LOAD_DEVICE_FUNCTION(vkCmdCopyBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdCopyImage);
	LOAD_DEVICE_FUNCTION(vkCmdBlitImage);
	LOAD_DEVICE_FUNCTION(vkCmdCopyBufferToImage);
	LOAD_DEVICE_FUNCTION(vkCmdCopyImageToBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdUpdateBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdFillBuffer);
	LOAD_DEVICE_FUNCTION(vkCmdClearColorImage);
	LOAD_DEVICE_FUNCTION(vkCmdClearDepthStencilImage);
	LOAD_DEVICE_FUNCTION(vkCmdClearAttachments);
	LOAD_DEVICE_FUNCTION(vkCmdResolveImage);
	LOAD_DEVICE_FUNCTION(vkCmdSetEvent);
	LOAD_DEVICE_FUNCTION(vkCmdResetEvent);
	LOAD_DEVICE_FUNCTION(vkCmdWaitEvents);
	LOAD_DEVICE_FUNCTION(vkCmdPipelineBarrier);
	LOAD_DEVICE_FUNCTION(vkCmdBeginQuery);
	LOAD_DEVICE_FUNCTION(vkCmdEndQuery);
	LOAD_DEVICE_FUNCTION(vkCmdResetQueryPool);
	LOAD_DEVICE_FUNCTION(vkCmdWriteTimestamp);
	LOAD_DEVICE_FUNCTION(vkCmdCopyQueryPoolResults);
	LOAD_DEVICE_FUNCTION(vkCmdPushConstants);
	LOAD_DEVICE_FUNCTION(vkCmdBeginRenderPass);
	LOAD_DEVICE_FUNCTION(vkCmdNextSubpass);
	LOAD_DEVICE_FUNCTION(vkCmdEndRenderPass);
	LOAD_DEVICE_FUNCTION(vkCmdExecuteCommands);

	// Vulkan 1.1 device functions
	LOAD_DEVICE_FUNCTION(vkBindBufferMemory2);
	LOAD_DEVICE_FUNCTION(vkBindImageMemory2);
	LOAD_DEVICE_FUNCTION(vkGetDeviceGroupPeerMemoryFeatures);
	LOAD_DEVICE_FUNCTION(vkGetImageMemoryRequirements2);
	LOAD_DEVICE_FUNCTION(vkGetBufferMemoryRequirements2);
	LOAD_DEVICE_FUNCTION(vkGetImageSparseMemoryRequirements2);
	LOAD_DEVICE_FUNCTION(vkTrimCommandPool);
	LOAD_DEVICE_FUNCTION(vkGetDeviceQueue2);
	LOAD_DEVICE_FUNCTION(vkCreateSamplerYcbcrConversion);
	LOAD_DEVICE_FUNCTION(vkDestroySamplerYcbcrConversion);
	LOAD_DEVICE_FUNCTION(vkCreateDescriptorUpdateTemplate);
	LOAD_DEVICE_FUNCTION(vkDestroyDescriptorUpdateTemplate);
	LOAD_DEVICE_FUNCTION(vkUpdateDescriptorSetWithTemplate);
	LOAD_DEVICE_FUNCTION(vkGetDescriptorSetLayoutSupport);

	LOAD_DEVICE_FUNCTION(vkCmdSetDeviceMask);
	LOAD_DEVICE_FUNCTION(vkCmdDispatchBase);


	// Vulkan 1.2 device functions
	LOAD_DEVICE_FUNCTION(vkCreateRenderPass2);
	LOAD_DEVICE_FUNCTION(vkResetQueryPool);
	LOAD_DEVICE_FUNCTION(vkGetSemaphoreCounterValue);
	LOAD_DEVICE_FUNCTION(vkWaitSemaphores);
	LOAD_DEVICE_FUNCTION(vkSignalSemaphore);
	LOAD_DEVICE_FUNCTION(vkGetBufferDeviceAddress);
	LOAD_DEVICE_FUNCTION(vkGetBufferOpaqueCaptureAddress);
	LOAD_DEVICE_FUNCTION(vkGetDeviceMemoryOpaqueCaptureAddress);

	LOAD_DEVICE_FUNCTION(vkCmdDrawIndirectCount);
	LOAD_DEVICE_FUNCTION(vkCmdDrawIndexedIndirectCount);
	LOAD_DEVICE_FUNCTION(vkCmdBeginRenderPass2);
	LOAD_DEVICE_FUNCTION(vkCmdNextSubpass2);
	LOAD_DEVICE_FUNCTION(vkCmdEndRenderPass2);
}

} // namespace Kodiak


#undef DECLARE_FUNCTION
#undef LOAD_FUNCTION
#undef LOAD_INSTANCE_FUNCTION
#undef LOAD_DEVICE_FUNCTION