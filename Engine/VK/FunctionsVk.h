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
VkResult FlushMappedMemoryRanges(VkDevice device, uint32_t memoryRangeCount, const VkMappedMemoryRange* pMemoryRanges);
VkResult InvalidateMappedMemoryRanges(
	VkDevice device,
	uint32_t memoryRangeCount,
	const VkMappedMemoryRange* pMemoryRanges);
void GetDeviceMemoryCommitment(VkDevice device,	VkDeviceMemory memory, VkDeviceSize* pCommittedMemoryInBytes);
VkResult BindBufferMemory(VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset);
VkResult BindImageMemory(VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset);
void GetBufferMemoryRequirements(VkDevice device, VkBuffer buffer, VkMemoryRequirements* pMemoryRequirements);
void GetImageMemoryRequirements(VkDevice device, VkImage image, VkMemoryRequirements* pMemoryRequirements);
void GetImageSparseMemoryRequirements(
	VkDevice device,
	VkImage image,
	uint32_t* pSparseMemoryRequirementCount,
	VkSparseImageMemoryRequirements* pSparseMemoryRequirements);
VkResult CreateFence(
	VkDevice device,
	const VkFenceCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkFence* pFence);
void DestroyFence(VkDevice device, VkFence fence, const VkAllocationCallbacks* pAllocator);
VkResult ResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences);
VkResult GetFenceStatus(VkDevice device, VkFence fence);
VkResult WaitForFences(
	VkDevice device,
	uint32_t fenceCount,
	const VkFence* pFences,
	VkBool32 waitAll,
	uint64_t timeout);
VkResult CreateSemaphore(
	VkDevice device,
	const VkSemaphoreCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkSemaphore* pSemaphore);
void DestroySemaphore(VkDevice device, VkSemaphore semaphore, const VkAllocationCallbacks* pAllocator);
VkResult CreateEvent(
	VkDevice device,
	const VkEventCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkEvent* pEvent);
void DestroyEvent(VkDevice device, VkEvent event, const VkAllocationCallbacks* pAllocator);
VkResult GetEventStatus(VkDevice device, VkEvent event);
VkResult SetEvent(VkDevice device, VkEvent event);
VkResult ResetEvent(VkDevice device, VkEvent event);
VkResult CreateQueryPool(
	VkDevice device,
	const VkQueryPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkQueryPool* pQueryPool);
void DestroyQueryPool(VkDevice device, VkQueryPool queryPool, const VkAllocationCallbacks* pAllocator);
VkResult GetQueryPoolResults(
	VkDevice device,
	VkQueryPool queryPool,
	uint32_t firstQuery,
	uint32_t queryCount,
	size_t dataSize,
	void* pData,
	VkDeviceSize stride,
	VkQueryResultFlags flags);
VkResult CreateBuffer(
	VkDevice device,
	const VkBufferCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkBuffer* pBuffer);
void DestroyBuffer(VkDevice device, VkBuffer buffer, const VkAllocationCallbacks* pAllocator);
VkResult CreateBufferView(VkDevice device,
	const VkBufferViewCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkBufferView* pView);
void DestroyBufferView(VkDevice device, VkBufferView bufferView, const VkAllocationCallbacks* pAllocator);
VkResult CreateImage(
	VkDevice device,
	const VkImageCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkImage* pImage);
void DestroyImage(VkDevice device, VkImage image, const VkAllocationCallbacks* pAllocator);
void GetImageSubresourceLayout(
	VkDevice device,
	VkImage image,
	const VkImageSubresource* pSubresource,
	VkSubresourceLayout* pLayout);
VkResult CreateImageView(
	VkDevice device,
	const VkImageViewCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkImageView* pView);
void DestroyImageView(VkDevice device, VkImageView imageView, const VkAllocationCallbacks* pAllocator);
VkResult CreateShaderModule(
	VkDevice device,
	const VkShaderModuleCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkShaderModule* pShaderModule);
void DestroyShaderModule(VkDevice device, VkShaderModule shaderModule, const VkAllocationCallbacks* pAllocator);
VkResult CreatePipelineCache(
	VkDevice device,
	const VkPipelineCacheCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkPipelineCache* pPipelineCache);
void DestroyPipelineCache(VkDevice device, VkPipelineCache pipelineCache, const VkAllocationCallbacks* pAllocator);
VkResult GetPipelineCacheData(VkDevice device, VkPipelineCache pipelineCache, size_t* pDataSize, void* pData);
VkResult MergePipelineCaches(
	VkDevice device,
	VkPipelineCache dstCache,
	uint32_t srcCacheCount,
	const VkPipelineCache* pSrcCaches);
VkResult CreateGraphicsPipelines(
	VkDevice device,
	VkPipelineCache pipelineCache,
	uint32_t createInfoCount,
	const VkGraphicsPipelineCreateInfo* pCreateInfos,
	const VkAllocationCallbacks* pAllocator,
	VkPipeline* pPipelines);
VkResult CreateComputePipelines(
	VkDevice device,
	VkPipelineCache pipelineCache,
	uint32_t createInfoCount,
	const VkComputePipelineCreateInfo* pCreateInfos,
	const VkAllocationCallbacks* pAllocator,
	VkPipeline* pPipelines);
void DestroyPipeline(VkDevice device, VkPipeline pipeline, const VkAllocationCallbacks* pAllocator);
VkResult CreatePipelineLayout(
	VkDevice device,
	const VkPipelineLayoutCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkPipelineLayout* pPipelineLayout);
void DestroyPipelineLayout(VkDevice device, VkPipelineLayout pipelineLayout, const VkAllocationCallbacks* pAllocator);
VkResult CreateSampler(
	VkDevice device,
	const VkSamplerCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkSampler* pSampler);
void DestroySampler(VkDevice device, VkSampler sampler, const VkAllocationCallbacks* pAllocator);
VkResult CreateDescriptorSetLayout(
	VkDevice device,
	const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDescriptorSetLayout* pSetLayout);
void DestroyDescriptorSetLayout(
	VkDevice device,
	VkDescriptorSetLayout descriptorSetLayout,
	const VkAllocationCallbacks* pAllocator);
VkResult CreateDescriptorPool(
	VkDevice device,
	const VkDescriptorPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDescriptorPool* pDescriptorPool);
void DestroyDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, const VkAllocationCallbacks* pAllocator);
VkResult ResetDescriptorPool(VkDevice device, VkDescriptorPool descriptorPool, VkDescriptorPoolResetFlags flags);
VkResult AllocateDescriptorSets(
	VkDevice device,
	const VkDescriptorSetAllocateInfo* pAllocateInfo,
	VkDescriptorSet* pDescriptorSets);
VkResult FreeDescriptorSets(
	VkDevice device,
	VkDescriptorPool descriptorPool,
	uint32_t descriptorSetCount,
	const VkDescriptorSet* pDescriptorSets);
void UpdateDescriptorSets(
	VkDevice device,
	uint32_t descriptorWriteCount,
	const VkWriteDescriptorSet* pDescriptorWrites,
	uint32_t descriptorCopyCount,
	const VkCopyDescriptorSet* pDescriptorCopies);
VkResult CreateFramebuffer(
	VkDevice device,
	const VkFramebufferCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkFramebuffer* pFramebuffer);
void DestroyFramebuffer(
	VkDevice device,
	VkFramebuffer framebuffer,
	const VkAllocationCallbacks* pAllocator);
VkResult CreateRenderPass(
	VkDevice device,
	const VkRenderPassCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkRenderPass* pRenderPass);
void DestroyRenderPass(VkDevice device, VkRenderPass renderPass, const VkAllocationCallbacks* pAllocator);
void GetRenderAreaGranularity(VkDevice device, VkRenderPass renderPass,	VkExtent2D* pGranularity);
VkResult CreateCommandPool(
	VkDevice device,
	const VkCommandPoolCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkCommandPool* pCommandPool);
void DestroyCommandPool(VkDevice device, VkCommandPool commandPool,	const VkAllocationCallbacks* pAllocator);
VkResult ResetCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolResetFlags flags);
VkResult AllocateCommandBuffers(
	VkDevice device,
	const VkCommandBufferAllocateInfo* pAllocateInfo, 
	VkCommandBuffer* pCommandBuffers);
void FreeCommandBuffers(
	VkDevice device,
	VkCommandPool commandPool,
	uint32_t commandBufferCount,
	const VkCommandBuffer* pCommandBuffers);


VkResult QueueSubmit(
	VkQueue queue,
	uint32_t submitCount,
	const VkSubmitInfo* pSubmits,
	VkFence fence);
VkResult QueueWaitIdle(VkQueue queue);
VkResult QueueBindSparse(
	VkQueue queue,
	uint32_t bindInfoCount,
	const VkBindSparseInfo* pBindInfo,
	VkFence fence);


VkResult BeginCommandBuffer(VkCommandBuffer commandBuffer, const VkCommandBufferBeginInfo* pBeginInfo);
VkResult EndCommandBuffer(VkCommandBuffer commandBuffer);
VkResult ResetCommandBuffer(VkCommandBuffer commandBuffer, VkCommandBufferResetFlags flags);
void CmdBindPipeline(VkCommandBuffer commandBuffer,	VkPipelineBindPoint pipelineBindPoint, VkPipeline pipeline);
void CmdSetViewport(
	VkCommandBuffer commandBuffer,
	uint32_t firstViewport,
	uint32_t viewportCount, 
	const VkViewport* pViewports);
void CmdSetScissor(
	VkCommandBuffer commandBuffer,
	uint32_t firstScissor,
	uint32_t scissorCount,
	const VkRect2D* pScissors);
void CmdSetLineWidth(VkCommandBuffer commandBuffer, float lineWidth);
void CmdSetDepthBias(
	VkCommandBuffer commandBuffer,
	float depthBiasConstantFactor,
	float depthBiasClamp,
	float depthBiasSlopeFactor);
void CmdSetBlendConstants(VkCommandBuffer commandBuffer, const float blendConstants[4]);
void CmdSetDepthBounds(VkCommandBuffer commandBuffer, float minDepthBounds, float maxDepthBounds);
void CmdSetStencilCompareMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t compareMask);
void CmdSetStencilWriteMask(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t writeMask);
void CmdSetStencilReference(VkCommandBuffer commandBuffer, VkStencilFaceFlags faceMask, uint32_t reference);
void CmdBindDescriptorSets(
	VkCommandBuffer commandBuffer,
	VkPipelineBindPoint pipelineBindPoint,
	VkPipelineLayout layout,
	uint32_t firstSet,
	uint32_t descriptorSetCount,
	const VkDescriptorSet* pDescriptorSets,
	uint32_t dynamicOffsetCount,
	const uint32_t* pDynamicOffsets);
void CmdBindIndexBuffer(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkIndexType indexType);
void CmdBindVertexBuffers(
	VkCommandBuffer commandBuffer,
	uint32_t firstBinding,
	uint32_t bindingCount,
	const VkBuffer* pBuffers,
	const VkDeviceSize* pOffsets);
void CmdDraw(
	VkCommandBuffer commandBuffer,
	uint32_t vertexCount,
	uint32_t instanceCount,
	uint32_t firstVertex,
	uint32_t firstInstance);
void CmdDrawIndexed(
	VkCommandBuffer commandBuffer,
	uint32_t indexCount,
	uint32_t instanceCount,
	uint32_t firstIndex,
	int32_t vertexOffset,
	uint32_t firstInstance);
void CmdDrawIndirect(
	VkCommandBuffer commandBuffer,
	VkBuffer buffer,
	VkDeviceSize offset,
	uint32_t drawCount,
	uint32_t stride);
void CmdDrawIndexedIndirect(
	VkCommandBuffer commandBuffer,
	VkBuffer buffer,
	VkDeviceSize offset,
	uint32_t drawCount,
	uint32_t stride);
void CmdDispatch(VkCommandBuffer commandBuffer, uint32_t groupCountX, uint32_t groupCountY, uint32_t groupCountZ);
void CmdDispatchIndirect(VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset);
void CmdCopyBuffer(
	VkCommandBuffer commandBuffer,
	VkBuffer srcBuffer,
	VkBuffer dstBuffer,
	uint32_t regionCount,
	const VkBufferCopy* pRegions);
void CmdCopyImage(
	VkCommandBuffer commandBuffer,
	VkImage srcImage,
	VkImageLayout srcImageLayout,
	VkImage dstImage,
	VkImageLayout dstImageLayout,
	uint32_t regionCount,
	const VkImageCopy* pRegions);
void CmdBlitImage(
	VkCommandBuffer commandBuffer,
	VkImage srcImage,
	VkImageLayout srcImageLayout,
	VkImage dstImage,
	VkImageLayout dstImageLayout,
	uint32_t regionCount,
	const VkImageBlit* pRegions,
	VkFilter filter);
void CmdCopyBufferToImage(
	VkCommandBuffer commandBuffer,
	VkBuffer srcBuffer,
	VkImage dstImage,
	VkImageLayout dstImageLayout,
	uint32_t regionCount,
	const VkBufferImageCopy* pRegions);
void CmdCopyImageToBuffer(
	VkCommandBuffer commandBuffer,
	VkImage srcImage,
	VkImageLayout srcImageLayout,
	VkBuffer dstBuffer,
	uint32_t regionCount,
	const VkBufferImageCopy* pRegions);
void CmdUpdateBuffer(
	VkCommandBuffer commandBuffer,
	VkBuffer dstBuffer,
	VkDeviceSize dstOffset,
	VkDeviceSize dataSize,
	const void* pData);
void CmdFillBuffer(
	VkCommandBuffer commandBuffer,
	VkBuffer dstBuffer,
	VkDeviceSize dstOffset,
	VkDeviceSize size,
	uint32_t data);
void CmdClearColorImage(
	VkCommandBuffer commandBuffer,
	VkImage image,
	VkImageLayout imageLayout,
	const VkClearColorValue* pColor,
	uint32_t rangeCount,
	const VkImageSubresourceRange* pRanges);
void CmdClearDepthStencilImage(
	VkCommandBuffer commandBuffer,
	VkImage image,
	VkImageLayout imageLayout,
	const VkClearDepthStencilValue* pDepthStencil,
	uint32_t rangeCount,
	const VkImageSubresourceRange* pRanges);
void CmdClearAttachments(
	VkCommandBuffer commandBuffer,
	uint32_t attachmentCount,
	const VkClearAttachment* pAttachments,
	uint32_t rectCount,
	const VkClearRect* pRects);
void CmdResolveImage(
	VkCommandBuffer commandBuffer,
	VkImage srcImage,
	VkImageLayout srcImageLayout,
	VkImage dstImage,
	VkImageLayout dstImageLayout,
	uint32_t regionCount,
	const VkImageResolve* pRegions);
void CmdSetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void CmdResetEvent(VkCommandBuffer commandBuffer, VkEvent event, VkPipelineStageFlags stageMask);
void CmdWaitEvents(
	VkCommandBuffer commandBuffer,
	uint32_t eventCount,
	const VkEvent* pEvents,
	VkPipelineStageFlags srcStageMask,
	VkPipelineStageFlags dstStageMask,
	uint32_t memoryBarrierCount,
	const VkMemoryBarrier* pMemoryBarriers,
	uint32_t bufferMemoryBarrierCount,
	const VkBufferMemoryBarrier* pBufferMemoryBarriers,
	uint32_t imageMemoryBarrierCount,
	const VkImageMemoryBarrier* pImageMemoryBarriers);
void CmdPipelineBarrier(
	VkCommandBuffer commandBuffer,
	VkPipelineStageFlags srcStageMask,
	VkPipelineStageFlags dstStageMask,
	VkDependencyFlags dependencyFlags,
	uint32_t memoryBarrierCount,
	const VkMemoryBarrier* pMemoryBarriers,
	uint32_t bufferMemoryBarrierCount,
	const VkBufferMemoryBarrier* pBufferMemoryBarriers,
	uint32_t imageMemoryBarrierCount,
	const VkImageMemoryBarrier* pImageMemoryBarriers);
void CmdBeginQuery(
	VkCommandBuffer commandBuffer,
	VkQueryPool queryPool,
	uint32_t query,
	VkQueryControlFlags flags);
void CmdEndQuery(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t query);
void CmdResetQueryPool(VkCommandBuffer commandBuffer, VkQueryPool queryPool, uint32_t firstQuery, uint32_t queryCount);
void CmdWriteTimestamp(
	VkCommandBuffer commandBuffer,
	VkPipelineStageFlagBits pipelineStage,
	VkQueryPool queryPool,
	uint32_t query);
void CmdCopyQueryPoolResults(
	VkCommandBuffer commandBuffer,
	VkQueryPool queryPool,
	uint32_t firstQuery,
	uint32_t queryCount,
	VkBuffer dstBuffer,
	VkDeviceSize dstOffset,
	VkDeviceSize stride,
	VkQueryResultFlags flags);
void CmdPushConstants(
	VkCommandBuffer commandBuffer,
	VkPipelineLayout layout,
	VkShaderStageFlags stageFlags,
	uint32_t offset,
	uint32_t size,
	const void* pValues);
void CmdBeginRenderPass(
	VkCommandBuffer commandBuffer,
	const VkRenderPassBeginInfo* pRenderPassBegin,
	VkSubpassContents contents);
void CmdNextSubpass(VkCommandBuffer commandBuffer, VkSubpassContents contents);
void CmdEndRenderPass(VkCommandBuffer commandBuffer);
void CmdExecuteCommands(
	VkCommandBuffer commandBuffer, 
	uint32_t commandBufferCount,
	const VkCommandBuffer* pCommandBuffers);


// Vulkan 1.1 device functions
VkResult BindBufferMemory2(VkDevice device,	uint32_t bindInfoCount,	const VkBindBufferMemoryInfo* pBindInfos);
VkResult BindImageMemory2(VkDevice device, uint32_t bindInfoCount, const VkBindImageMemoryInfo* pBindInfos);
void GetDeviceGroupPeerMemoryFeatures(
	VkDevice device,
	uint32_t heapIndex,
	uint32_t localDeviceIndex,
	uint32_t remoteDeviceIndex,
	VkPeerMemoryFeatureFlags* pPeerMemoryFeatures);
void GetImageMemoryRequirements2(
	VkDevice device,
	const VkImageMemoryRequirementsInfo2* pInfo,
	VkMemoryRequirements2* pMemoryRequirements);
void GetBufferMemoryRequirements2(
	VkDevice device,
	const VkBufferMemoryRequirementsInfo2* pInfo,
	VkMemoryRequirements2* pMemoryRequirements);
void GetImageSparseMemoryRequirements2(
	VkDevice device,
	const VkImageSparseMemoryRequirementsInfo2* pInfo,
	uint32_t* pSparseMemoryRequirementCount,
	VkSparseImageMemoryRequirements2* pSparseMemoryRequirements);
void TrimCommandPool(VkDevice device, VkCommandPool commandPool, VkCommandPoolTrimFlags flags);
void GetDeviceQueue2(VkDevice device, const VkDeviceQueueInfo2* pQueueInfo, VkQueue* pQueue);
VkResult CreateSamplerYcbcrConversion(
	VkDevice device,
	const VkSamplerYcbcrConversionCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkSamplerYcbcrConversion* pYcbcrConversion);
void DestroySamplerYcbcrConversion(
	VkDevice device,
	VkSamplerYcbcrConversion ycbcrConversion,
	const VkAllocationCallbacks* pAllocator);
VkResult CreateDescriptorUpdateTemplate(
	VkDevice device,
	const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
	const VkAllocationCallbacks* pAllocator,
	VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate);
void DestroyDescriptorUpdateTemplate(
	VkDevice device,
	VkDescriptorUpdateTemplate descriptorUpdateTemplate,
	const VkAllocationCallbacks* pAllocator);
void UpdateDescriptorSetWithTemplate(
	VkDevice device,
	VkDescriptorSet descriptorSet,
	VkDescriptorUpdateTemplate descriptorUpdateTemplate,
	const void* pData);
void GetDescriptorSetLayoutSupport(
	VkDevice device,
	const VkDescriptorSetLayoutCreateInfo* pCreateInfo,
	VkDescriptorSetLayoutSupport* pSupport);


void CmdSetDeviceMask(VkCommandBuffer commandBuffer, uint32_t deviceMask);
void CmdDispatchBase(
	VkCommandBuffer commandBuffer,
	uint32_t baseGroupX,
	uint32_t baseGroupY,
	uint32_t baseGroupZ,
	uint32_t groupCountX,
	uint32_t groupCountY,
	uint32_t groupCountZ);


} // namespace VK