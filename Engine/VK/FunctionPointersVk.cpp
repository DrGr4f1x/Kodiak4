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

#include "FunctionPointersVk.h"


#define DEFINE_FUNCTION(name) \
PFN_##name fp_##name = nullptr

// Base instance functions (can be loaded with NULL VkInstance handle)
DEFINE_FUNCTION(vkGetInstanceProcAddr);
DEFINE_FUNCTION(vkEnumerateInstanceVersion);
DEFINE_FUNCTION(vkEnumerateInstanceExtensionProperties);
DEFINE_FUNCTION(vkEnumerateInstanceLayerProperties);
DEFINE_FUNCTION(vkCreateInstance);


// Vulkan 1.0 instance functions
DEFINE_FUNCTION(vkGetDeviceProcAddr);
DEFINE_FUNCTION(vkDestroyInstance);
DEFINE_FUNCTION(vkEnumeratePhysicalDevices);
DEFINE_FUNCTION(vkGetPhysicalDeviceFeatures);
DEFINE_FUNCTION(vkGetPhysicalDeviceFormatProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceMemoryProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties);
DEFINE_FUNCTION(vkCreateDevice);

// Vulkan 1.1 instance functions
DEFINE_FUNCTION(vkEnumeratePhysicalDeviceGroups);
DEFINE_FUNCTION(vkGetPhysicalDeviceFeatures2);
DEFINE_FUNCTION(vkGetPhysicalDeviceProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceFormatProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceImageFormatProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceQueueFamilyProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceMemoryProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceSparseImageFormatProperties2);
DEFINE_FUNCTION(vkGetPhysicalDeviceExternalBufferProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceExternalFenceProperties);
DEFINE_FUNCTION(vkGetPhysicalDeviceExternalSemaphoreProperties);

// Vulkan 1.0 device functions
DEFINE_FUNCTION(vkDestroyDevice);
DEFINE_FUNCTION(vkGetDeviceQueue);
DEFINE_FUNCTION(vkDeviceWaitIdle);
DEFINE_FUNCTION(vkAllocateMemory);
DEFINE_FUNCTION(vkFreeMemory);
DEFINE_FUNCTION(vkMapMemory);
DEFINE_FUNCTION(vkUnmapMemory);
DEFINE_FUNCTION(vkFlushMappedMemoryRanges);
DEFINE_FUNCTION(vkInvalidateMappedMemoryRanges);
DEFINE_FUNCTION(vkGetDeviceMemoryCommitment);
DEFINE_FUNCTION(vkBindBufferMemory);
DEFINE_FUNCTION(vkBindImageMemory);
DEFINE_FUNCTION(vkGetBufferMemoryRequirements);
DEFINE_FUNCTION(vkGetImageMemoryRequirements);
DEFINE_FUNCTION(vkGetImageSparseMemoryRequirements);
DEFINE_FUNCTION(vkCreateFence);
DEFINE_FUNCTION(vkDestroyFence);
DEFINE_FUNCTION(vkResetFences);
DEFINE_FUNCTION(vkGetFenceStatus);
DEFINE_FUNCTION(vkWaitForFences);
DEFINE_FUNCTION(vkCreateSemaphore);
DEFINE_FUNCTION(vkDestroySemaphore);
DEFINE_FUNCTION(vkCreateEvent);
DEFINE_FUNCTION(vkDestroyEvent);
DEFINE_FUNCTION(vkGetEventStatus);
DEFINE_FUNCTION(vkSetEvent);
DEFINE_FUNCTION(vkResetEvent);
DEFINE_FUNCTION(vkCreateQueryPool);
DEFINE_FUNCTION(vkDestroyQueryPool);
DEFINE_FUNCTION(vkGetQueryPoolResults);
DEFINE_FUNCTION(vkCreateBuffer);
DEFINE_FUNCTION(vkDestroyBuffer);
DEFINE_FUNCTION(vkCreateBufferView);
DEFINE_FUNCTION(vkDestroyBufferView);
DEFINE_FUNCTION(vkCreateImage);
DEFINE_FUNCTION(vkDestroyImage);
DEFINE_FUNCTION(vkGetImageSubresourceLayout);
DEFINE_FUNCTION(vkCreateImageView);
DEFINE_FUNCTION(vkDestroyImageView);
DEFINE_FUNCTION(vkCreateShaderModule);
DEFINE_FUNCTION(vkDestroyShaderModule);
DEFINE_FUNCTION(vkCreatePipelineCache);
DEFINE_FUNCTION(vkDestroyPipelineCache);
DEFINE_FUNCTION(vkGetPipelineCacheData);
DEFINE_FUNCTION(vkMergePipelineCaches);
DEFINE_FUNCTION(vkCreateGraphicsPipelines);
DEFINE_FUNCTION(vkCreateComputePipelines);
DEFINE_FUNCTION(vkDestroyPipeline);
DEFINE_FUNCTION(vkCreatePipelineLayout);
DEFINE_FUNCTION(vkDestroyPipelineLayout);
DEFINE_FUNCTION(vkCreateSampler);
DEFINE_FUNCTION(vkDestroySampler);
DEFINE_FUNCTION(vkCreateDescriptorSetLayout);
DEFINE_FUNCTION(vkDestroyDescriptorSetLayout);
DEFINE_FUNCTION(vkCreateDescriptorPool);
DEFINE_FUNCTION(vkDestroyDescriptorPool);
DEFINE_FUNCTION(vkResetDescriptorPool);
DEFINE_FUNCTION(vkAllocateDescriptorSets);
DEFINE_FUNCTION(vkFreeDescriptorSets);
DEFINE_FUNCTION(vkUpdateDescriptorSets);
DEFINE_FUNCTION(vkCreateFramebuffer);
DEFINE_FUNCTION(vkDestroyFramebuffer);
DEFINE_FUNCTION(vkCreateRenderPass);
DEFINE_FUNCTION(vkDestroyRenderPass);
DEFINE_FUNCTION(vkGetRenderAreaGranularity);
DEFINE_FUNCTION(vkCreateCommandPool);
DEFINE_FUNCTION(vkDestroyCommandPool);
DEFINE_FUNCTION(vkResetCommandPool);
DEFINE_FUNCTION(vkAllocateCommandBuffers);
DEFINE_FUNCTION(vkFreeCommandBuffers);

DEFINE_FUNCTION(vkQueueSubmit);
DEFINE_FUNCTION(vkQueueWaitIdle);
DEFINE_FUNCTION(vkQueueBindSparse);

DEFINE_FUNCTION(vkBeginCommandBuffer);
DEFINE_FUNCTION(vkEndCommandBuffer);
DEFINE_FUNCTION(vkResetCommandBuffer);
DEFINE_FUNCTION(vkCmdBindPipeline);
DEFINE_FUNCTION(vkCmdSetViewport);
DEFINE_FUNCTION(vkCmdSetScissor);
DEFINE_FUNCTION(vkCmdSetLineWidth);
DEFINE_FUNCTION(vkCmdSetDepthBias);
DEFINE_FUNCTION(vkCmdSetBlendConstants);
DEFINE_FUNCTION(vkCmdSetDepthBounds);
DEFINE_FUNCTION(vkCmdSetStencilCompareMask);
DEFINE_FUNCTION(vkCmdSetStencilWriteMask);
DEFINE_FUNCTION(vkCmdSetStencilReference);
DEFINE_FUNCTION(vkCmdBindDescriptorSets);
DEFINE_FUNCTION(vkCmdBindIndexBuffer);
DEFINE_FUNCTION(vkCmdBindVertexBuffers);
DEFINE_FUNCTION(vkCmdDraw);
DEFINE_FUNCTION(vkCmdDrawIndexed);
DEFINE_FUNCTION(vkCmdDrawIndirect);
DEFINE_FUNCTION(vkCmdDrawIndexedIndirect);
DEFINE_FUNCTION(vkCmdDispatch);
DEFINE_FUNCTION(vkCmdDispatchIndirect);
DEFINE_FUNCTION(vkCmdCopyBuffer);
DEFINE_FUNCTION(vkCmdCopyImage);
DEFINE_FUNCTION(vkCmdBlitImage);
DEFINE_FUNCTION(vkCmdCopyBufferToImage);
DEFINE_FUNCTION(vkCmdCopyImageToBuffer);
DEFINE_FUNCTION(vkCmdUpdateBuffer);
DEFINE_FUNCTION(vkCmdFillBuffer);
DEFINE_FUNCTION(vkCmdClearColorImage);
DEFINE_FUNCTION(vkCmdClearDepthStencilImage);
DEFINE_FUNCTION(vkCmdClearAttachments);
DEFINE_FUNCTION(vkCmdResolveImage);
DEFINE_FUNCTION(vkCmdSetEvent);
DEFINE_FUNCTION(vkCmdResetEvent);
DEFINE_FUNCTION(vkCmdWaitEvents);
DEFINE_FUNCTION(vkCmdPipelineBarrier);
DEFINE_FUNCTION(vkCmdBeginQuery);
DEFINE_FUNCTION(vkCmdEndQuery);
DEFINE_FUNCTION(vkCmdResetQueryPool);
DEFINE_FUNCTION(vkCmdWriteTimestamp);
DEFINE_FUNCTION(vkCmdCopyQueryPoolResults);
DEFINE_FUNCTION(vkCmdPushConstants);
DEFINE_FUNCTION(vkCmdBeginRenderPass);
DEFINE_FUNCTION(vkCmdNextSubpass);
DEFINE_FUNCTION(vkCmdEndRenderPass);
DEFINE_FUNCTION(vkCmdExecuteCommands);


// Vulkan 1.1 device functions
DEFINE_FUNCTION(vkBindBufferMemory2);
DEFINE_FUNCTION(vkBindImageMemory2);
DEFINE_FUNCTION(vkGetDeviceGroupPeerMemoryFeatures);
DEFINE_FUNCTION(vkGetImageMemoryRequirements2);
DEFINE_FUNCTION(vkGetBufferMemoryRequirements2);
DEFINE_FUNCTION(vkGetImageSparseMemoryRequirements2);
DEFINE_FUNCTION(vkTrimCommandPool);
DEFINE_FUNCTION(vkGetDeviceQueue2);
DEFINE_FUNCTION(vkCreateSamplerYcbcrConversion);
DEFINE_FUNCTION(vkDestroySamplerYcbcrConversion);
DEFINE_FUNCTION(vkCreateDescriptorUpdateTemplate);
DEFINE_FUNCTION(vkDestroyDescriptorUpdateTemplate);
DEFINE_FUNCTION(vkUpdateDescriptorSetWithTemplate);
DEFINE_FUNCTION(vkGetDescriptorSetLayoutSupport);

DEFINE_FUNCTION(vkCmdSetDeviceMask);
DEFINE_FUNCTION(vkCmdDispatchBase);


// Vulkan 1.2 device functions
DEFINE_FUNCTION(vkCreateRenderPass2);
DEFINE_FUNCTION(vkResetQueryPool);
DEFINE_FUNCTION(vkGetSemaphoreCounterValue);
DEFINE_FUNCTION(vkWaitSemaphores);
DEFINE_FUNCTION(vkSignalSemaphore);
DEFINE_FUNCTION(vkGetBufferDeviceAddress);
DEFINE_FUNCTION(vkGetBufferOpaqueCaptureAddress);
DEFINE_FUNCTION(vkGetDeviceMemoryOpaqueCaptureAddress);

DEFINE_FUNCTION(vkCmdDrawIndirectCount);
DEFINE_FUNCTION(vkCmdDrawIndexedIndirectCount);
DEFINE_FUNCTION(vkCmdBeginRenderPass2);
DEFINE_FUNCTION(vkCmdNextSubpass2);
DEFINE_FUNCTION(vkCmdEndRenderPass2);

#undef DEFINE_FUNCTION