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

namespace Kodiak
{

inline VkApplicationInfo ApplicationInfo()
{
	VkApplicationInfo applicationInfo{};
	applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	return applicationInfo;
}


inline VkInstanceCreateInfo InstanceCreateInfo()
{
	VkInstanceCreateInfo instanceCreateInfo{};
	instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	instanceCreateInfo.pNext = nullptr;
	return instanceCreateInfo;
}


inline VkPhysicalDeviceFeatures2 PhysicalDeviceFeatures2()
{
	VkPhysicalDeviceFeatures2 physicalDeviceFeatures2{};
	physicalDeviceFeatures2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
	physicalDeviceFeatures2.pNext = nullptr;
	return physicalDeviceFeatures2;
}


inline VkPhysicalDeviceVulkan11Features PhysicalDeviceVulkan11Features()
{
	VkPhysicalDeviceVulkan11Features physicalDeviceVulkan11Features{};
	physicalDeviceVulkan11Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES;
	physicalDeviceVulkan11Features.pNext = nullptr;
	return physicalDeviceVulkan11Features;
}


inline VkPhysicalDeviceVulkan12Features PhysicalDeviceVulkan12Features()
{
	VkPhysicalDeviceVulkan12Features physicalDeviceVulkan12Features{};
	physicalDeviceVulkan12Features.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES;
	physicalDeviceVulkan12Features.pNext = nullptr;
	return physicalDeviceVulkan12Features;
}


inline VkPhysicalDeviceProperties2 PhysicalDeviceProperties2()
{
	VkPhysicalDeviceProperties2 physicalDeviceProperties2{};
	physicalDeviceProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
	physicalDeviceProperties2.pNext = nullptr;
	return physicalDeviceProperties2;
}


inline VkPhysicalDeviceVulkan11Properties PhysicalDeviceVulkan11Properties()
{
	VkPhysicalDeviceVulkan11Properties physicalDeviceVulkan11Properties{};
	physicalDeviceVulkan11Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES;
	physicalDeviceVulkan11Properties.pNext = nullptr;
	return physicalDeviceVulkan11Properties;
}


inline VkPhysicalDeviceVulkan12Properties PhysicalDeviceVulkan12Properties()
{
	VkPhysicalDeviceVulkan12Properties physicalDeviceVulkan12Properties{};
	physicalDeviceVulkan12Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES;
	physicalDeviceVulkan12Properties.pNext = nullptr;
	return physicalDeviceVulkan12Properties;
}


inline VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT PhysicalDeviceBlendOperationAdvanced()
{
	VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT physicalDeviceBlendOperationAdvancedProperties{};
	physicalDeviceBlendOperationAdvancedProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT;
	physicalDeviceBlendOperationAdvancedProperties.pNext = nullptr;
	return physicalDeviceBlendOperationAdvancedProperties;
}


inline VkPhysicalDeviceConservativeRasterizationPropertiesEXT PhysicalDeviceConservativeRasterizationProperties()
{
	VkPhysicalDeviceConservativeRasterizationPropertiesEXT physicalDeviceConservativeRasterizationProperties{};
	physicalDeviceConservativeRasterizationProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT;
	physicalDeviceConservativeRasterizationProperties.pNext = nullptr;
	return physicalDeviceConservativeRasterizationProperties;
}


inline VkPhysicalDeviceCustomBorderColorPropertiesEXT PhysicalDeviceCustomBorderProperties()
{
	VkPhysicalDeviceCustomBorderColorPropertiesEXT physicalDeviceCustomBorderProperties{};
	physicalDeviceCustomBorderProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT;
	physicalDeviceCustomBorderProperties.pNext = nullptr;
	return physicalDeviceCustomBorderProperties;
}


inline VkPhysicalDeviceDiscardRectanglePropertiesEXT PhysicalDeviceDiscardRectangleProperties()
{
	VkPhysicalDeviceDiscardRectanglePropertiesEXT physicalDeviceDiscardRectangleProperties{};
	physicalDeviceDiscardRectangleProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT;
	physicalDeviceDiscardRectangleProperties.pNext = nullptr;
	return physicalDeviceDiscardRectangleProperties;
}


inline VkPhysicalDeviceExternalMemoryHostPropertiesEXT PhysicalDeviceExternalMemoryHostProperties()
{
	VkPhysicalDeviceExternalMemoryHostPropertiesEXT physicalDeviceExternalMemoryHostProperties{};
	physicalDeviceExternalMemoryHostProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT;
	physicalDeviceExternalMemoryHostProperties.pNext = nullptr;
	return physicalDeviceExternalMemoryHostProperties;
}


inline VkPhysicalDeviceFragmentDensityMapPropertiesEXT PhysicalDeviceFragmentDensityMapProperties()
{
	VkPhysicalDeviceFragmentDensityMapPropertiesEXT physicalDeviceFragmentDensityMapProperties{};
	physicalDeviceFragmentDensityMapProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT;
	physicalDeviceFragmentDensityMapProperties.pNext = nullptr;
	return physicalDeviceFragmentDensityMapProperties;
}


inline VkPhysicalDeviceInlineUniformBlockPropertiesEXT PhysicalDeviceInlineUniformBlockProperties()
{
	VkPhysicalDeviceInlineUniformBlockPropertiesEXT physicalDeviceInlineUniformBlockProperties{};
	physicalDeviceInlineUniformBlockProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT;
	physicalDeviceInlineUniformBlockProperties.pNext = nullptr;
	return physicalDeviceInlineUniformBlockProperties;
}


inline VkPhysicalDeviceLineRasterizationPropertiesEXT PhysicalDeviceLineRasterizationProperties()
{
	VkPhysicalDeviceLineRasterizationPropertiesEXT physicalDeviceLineRasterizationProperties{};
	physicalDeviceLineRasterizationProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT;
	physicalDeviceLineRasterizationProperties.pNext = nullptr;
	return physicalDeviceLineRasterizationProperties;
}


inline VkPhysicalDevicePCIBusInfoPropertiesEXT PhysicalDevicePCIBusInfoProperties()
{
	VkPhysicalDevicePCIBusInfoPropertiesEXT physicalDevicePCIBusInfoProperties{};
	physicalDevicePCIBusInfoProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT;
	physicalDevicePCIBusInfoProperties.pNext = nullptr;
	return physicalDevicePCIBusInfoProperties;
}


inline VkPhysicalDeviceRobustness2PropertiesEXT PhysicalDeviceRobustness2Properties()
{
	VkPhysicalDeviceRobustness2PropertiesEXT physicalDeviceRobustness2Properties{};
	physicalDeviceRobustness2Properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT;
	physicalDeviceRobustness2Properties.pNext = nullptr;
	return physicalDeviceRobustness2Properties;
}


inline VkPhysicalDeviceSampleLocationsPropertiesEXT PhysicalDeviceSampleLocationsProperties()
{
	VkPhysicalDeviceSampleLocationsPropertiesEXT physicalDeviceSampleLocationsProperties{};
	physicalDeviceSampleLocationsProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT;
	physicalDeviceSampleLocationsProperties.pNext = nullptr;
	return physicalDeviceSampleLocationsProperties;
}


inline VkPhysicalDeviceSubgroupSizeControlPropertiesEXT PhysicalDeviceSubgroupSizeControlProperties()
{
	VkPhysicalDeviceSubgroupSizeControlPropertiesEXT physicalDeviceSubgroupSizeControlProperties{};
	physicalDeviceSubgroupSizeControlProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT;
	physicalDeviceSubgroupSizeControlProperties.pNext = nullptr;
	return physicalDeviceSubgroupSizeControlProperties;
}


inline VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT PhysicalDeviceTexelBufferAlignmentProperties()
{
	VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT physicalDeviceTexelBufferAlignmentProperties{};
	physicalDeviceTexelBufferAlignmentProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT;
	physicalDeviceTexelBufferAlignmentProperties.pNext = nullptr;
	return physicalDeviceTexelBufferAlignmentProperties;
}


inline VkPhysicalDeviceTransformFeedbackPropertiesEXT PhysicalDeviceTransformFeedbackProperties()
{
	VkPhysicalDeviceTransformFeedbackPropertiesEXT physicalDeviceTransformFeedbackProperties{};
	physicalDeviceTransformFeedbackProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT;
	physicalDeviceTransformFeedbackProperties.pNext = nullptr;
	return physicalDeviceTransformFeedbackProperties;
}


inline VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT PhysicalDeviceVertexAttributeDivisorProperties()
{
	VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT physicalDeviceVertexAttributeDivisorProperties{};
	physicalDeviceVertexAttributeDivisorProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT;
	physicalDeviceVertexAttributeDivisorProperties.pNext = nullptr;
	return physicalDeviceVertexAttributeDivisorProperties;
}


inline VkPhysicalDevicePerformanceQueryPropertiesKHR PhysicalDevicePerformanceQueryProperties()
{
	VkPhysicalDevicePerformanceQueryPropertiesKHR physicalDevicePerformanceQueryProperties{};
	physicalDevicePerformanceQueryProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR;
	physicalDevicePerformanceQueryProperties.pNext = nullptr;
	return physicalDevicePerformanceQueryProperties;
}


inline VkPhysicalDevicePushDescriptorPropertiesKHR PhysicalDevicePushDescriptorProperties()
{
	VkPhysicalDevicePushDescriptorPropertiesKHR physicalDevicePushDescriptorProperties{};
	physicalDevicePushDescriptorProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR;
	physicalDevicePushDescriptorProperties.pNext = nullptr;
	return physicalDevicePushDescriptorProperties;
}


inline VkPhysicalDeviceShaderCorePropertiesAMD PhysicalDeviceShaderCoreProperties()
{
	VkPhysicalDeviceShaderCorePropertiesAMD physicalDeviceShaderCoreProperties{};
	physicalDeviceShaderCoreProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD;
	physicalDeviceShaderCoreProperties.pNext = nullptr;
	return physicalDeviceShaderCoreProperties;
}


inline VkPhysicalDeviceShaderCoreProperties2AMD PhysicalDeviceShaderCoreProperties2()
{
	VkPhysicalDeviceShaderCoreProperties2AMD physicalDeviceShaderCoreProperties2{};
	physicalDeviceShaderCoreProperties2.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD;
	physicalDeviceShaderCoreProperties2.pNext = nullptr;
	return physicalDeviceShaderCoreProperties2;
}


inline VkPhysicalDeviceCooperativeMatrixPropertiesNV PhysicalDeviceCooperativeMatrixProperties()
{
	VkPhysicalDeviceCooperativeMatrixPropertiesNV physicalDeviceCooperativeMatrixProperties{};
	physicalDeviceCooperativeMatrixProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV;
	physicalDeviceCooperativeMatrixProperties.pNext = nullptr;
	return physicalDeviceCooperativeMatrixProperties;
}


inline VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV PhysicalDeviceDeviceGeneratedCommandsProperties()
{
	VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV physicalDeviceDeviceGeneratedCommandsProperties{};
	physicalDeviceDeviceGeneratedCommandsProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV;
	physicalDeviceDeviceGeneratedCommandsProperties.pNext = nullptr;
	return physicalDeviceDeviceGeneratedCommandsProperties;
}


inline VkPhysicalDeviceMeshShaderPropertiesNV PhysicalDeviceMeshShaderProperties()
{
	VkPhysicalDeviceMeshShaderPropertiesNV physicalDeviceMeshShaderProperties{};
	physicalDeviceMeshShaderProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV;
	physicalDeviceMeshShaderProperties.pNext = nullptr;
	return physicalDeviceMeshShaderProperties;
}


inline VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX PhysicalDeviceMultiviewPerViewAttributesProperties()
{
	VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX physicalDeviceMultiviewPerViewAttributesProperties{};
	physicalDeviceMultiviewPerViewAttributesProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX;
	physicalDeviceMultiviewPerViewAttributesProperties.pNext = nullptr;
	return physicalDeviceMultiviewPerViewAttributesProperties;
}


inline VkPhysicalDeviceRayTracingPropertiesNV PhysicalDeviceRayTracingProperties()
{
	VkPhysicalDeviceRayTracingPropertiesNV physicalDeviceRayTracingProperties{};
	physicalDeviceRayTracingProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV;
	physicalDeviceRayTracingProperties.pNext = nullptr;
	return physicalDeviceRayTracingProperties;
}


inline VkPhysicalDeviceShaderSMBuiltinsPropertiesNV PhysicalDeviceShaderSMBuiltinsProperties()
{
	VkPhysicalDeviceShaderSMBuiltinsPropertiesNV physicalDeviceShaderSMBuiltinsProperties{};
	physicalDeviceShaderSMBuiltinsProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV;
	physicalDeviceShaderSMBuiltinsProperties.pNext = nullptr;
	return physicalDeviceShaderSMBuiltinsProperties;
}


inline VkPhysicalDeviceShadingRateImagePropertiesNV PhysicalDeviceShadingRateImageProperties()
{
	VkPhysicalDeviceShadingRateImagePropertiesNV physicalDeviceShadingRateImageProperties{};
	physicalDeviceShadingRateImageProperties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV;
	physicalDeviceShadingRateImageProperties.pNext = nullptr;
	return physicalDeviceShadingRateImageProperties;
}

} // namespace Kodiak