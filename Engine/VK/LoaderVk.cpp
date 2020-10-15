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

#include "FunctionPointersVk.h"


using namespace std;


#define LOAD_FUNCTION(name) \
fp_##name = (PFN_##name)vkGetInstanceProcAddr(VK_NULL_HANDLE, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)

#define LOAD_INSTANCE_FUNCTION(name) \
fp_##name = (PFN_##name)VkFunc::GetInstanceProcAddr(instance, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)

#define LOAD_DEVICE_FUNCTION(name) \
fp_##name = (PFN_##name)VkFunc::GetDeviceProcAddr(device, #name); \
VALIDATE_FUNCTION_POINTER(fp_##name)


namespace Kodiak
{

void LoadBaseFunctionPointers()
{
	// Load vkGetInstanceProcAddr, so we can use it to load the rest of the instance functions
	LOAD_FUNCTION(vkGetInstanceProcAddr);

	// Load the remaining instance functions that don't require a live instance handle
	LOAD_FUNCTION(vkEnumerateInstanceVersion);
	LOAD_FUNCTION(vkEnumerateInstanceExtensionProperties);
	LOAD_FUNCTION(vkEnumerateInstanceLayerProperties);
	LOAD_FUNCTION(vkCreateInstance);
}


void LoadInstanceFunctionPointers(VkInstance instance, uint32_t apiVersion)
{
	assert(apiVersion >= VK_API_VERSION_1_0);

	// Vulkan 1.0 instance functions
	if (apiVersion >= VK_API_VERSION_1_0)
	{
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
	}

	// Vulkan 1.1 instance functions
	if (apiVersion >= VK_API_VERSION_1_1)
	{
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

	// Vulkan version 1.2 (no instance functions)
}


void LoadDeviceFunctionPointers(VkDevice device, uint32_t apiVersion)
{
	assert(apiVersion >= VK_API_VERSION_1_0);

	// Vulkan 1.0 device functions
	if (apiVersion >= VK_API_VERSION_1_0)
	{
		// VkDevice functions
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

		// VkQueue functions
		LOAD_DEVICE_FUNCTION(vkQueueSubmit);
		LOAD_DEVICE_FUNCTION(vkQueueWaitIdle);
		LOAD_DEVICE_FUNCTION(vkQueueBindSparse);

		// VkCommandBuffer functions
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
	}

	// Vulkan 1.1 device functions
	if (apiVersion >= VK_API_VERSION_1_1)
	{
		// VkDevice functions
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

		// VkCommandBuffer functions
		LOAD_DEVICE_FUNCTION(vkCmdSetDeviceMask);
		LOAD_DEVICE_FUNCTION(vkCmdDispatchBase);
	}


	// Vulkan 1.2 device functions
	if (apiVersion >= VK_API_VERSION_1_2)
	{
		// VkDevice functions
		LOAD_DEVICE_FUNCTION(vkCreateRenderPass2);
		LOAD_DEVICE_FUNCTION(vkResetQueryPool);
		LOAD_DEVICE_FUNCTION(vkGetSemaphoreCounterValue);
		LOAD_DEVICE_FUNCTION(vkWaitSemaphores);
		LOAD_DEVICE_FUNCTION(vkSignalSemaphore);
		LOAD_DEVICE_FUNCTION(vkGetBufferDeviceAddress);
		LOAD_DEVICE_FUNCTION(vkGetBufferOpaqueCaptureAddress);
		LOAD_DEVICE_FUNCTION(vkGetDeviceMemoryOpaqueCaptureAddress);

		// VkCommandBuffer functions
		LOAD_DEVICE_FUNCTION(vkCmdDrawIndirectCount);
		LOAD_DEVICE_FUNCTION(vkCmdDrawIndexedIndirectCount);
		LOAD_DEVICE_FUNCTION(vkCmdBeginRenderPass2);
		LOAD_DEVICE_FUNCTION(vkCmdNextSubpass2);
		LOAD_DEVICE_FUNCTION(vkCmdEndRenderPass2);
	}
}

} // namespace Kodiak


#undef DECLARE_FUNCTION
#undef LOAD_FUNCTION
#undef LOAD_INSTANCE_FUNCTION
#undef LOAD_DEVICE_FUNCTION