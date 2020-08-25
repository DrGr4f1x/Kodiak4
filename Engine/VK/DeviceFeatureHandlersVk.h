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

class FeatureProxy
{
public:
	FeatureProxy(const DeviceFeatures& supportedFeatures, DeviceFeatures& enabledFeatures, DeviceProperties& properties, ExtensionManager& extensionManager)
		: supportedDeviceFeatures(supportedFeatures)
		, enabledDeviceFeatures(enabledFeatures)
		, deviceProperties(properties)
		, extensionManager(extensionManager)
		, supportedFeatures(supportedDeviceFeatures.deviceFeatures2.features)
		, supportedFeatures1_1(supportedDeviceFeatures.deviceFeatures1_1)
		, supportedFeatures1_2(supportedDeviceFeatures.deviceFeatures1_2)
		, enabledFeatures(enabledDeviceFeatures.deviceFeatures2.features)
		, enabledFeatures1_1(enabledDeviceFeatures.deviceFeatures1_1)
		, enabledFeatures1_2(enabledDeviceFeatures.deviceFeatures1_2)
		, properties(deviceProperties.deviceProperties2.properties)
		, properties1_1(deviceProperties.deviceProperties1_1)
		, properties1_2(deviceProperties.deviceProperties1_2)
	{}

	// References to the feature and properties structures from the device
	const DeviceFeatures& supportedDeviceFeatures;
	DeviceFeatures& enabledDeviceFeatures;
	DeviceProperties& deviceProperties;
	ExtensionManager& extensionManager;

	// These are references to fields on the structures above, as a convenience
	const VkPhysicalDeviceFeatures& supportedFeatures;
	const VkPhysicalDeviceVulkan11Features& supportedFeatures1_1;
	const VkPhysicalDeviceVulkan12Features& supportedFeatures1_2;
	
	VkPhysicalDeviceFeatures& enabledFeatures;
	VkPhysicalDeviceVulkan11Features& enabledFeatures1_1;
	VkPhysicalDeviceVulkan12Features& enabledFeatures1_2;

	VkPhysicalDeviceProperties& properties;
	VkPhysicalDeviceVulkan11Properties& properties1_1;
	VkPhysicalDeviceVulkan12Properties& properties1_2;
};


// Core Vulkan 1.0 features

inline bool EnableRobustBufferAccess(FeatureProxy& proxy)
{
	proxy.enabledFeatures.robustBufferAccess = proxy.supportedFeatures.robustBufferAccess;
	return proxy.enabledFeatures.robustBufferAccess;
}


inline bool EnableFullDrawIndexUint32(FeatureProxy& proxy)
{
	proxy.enabledFeatures.fullDrawIndexUint32 = proxy.supportedFeatures.fullDrawIndexUint32;
	return proxy.enabledFeatures.fullDrawIndexUint32;
}


inline bool EnableTextureCubeArray(FeatureProxy& proxy)
{
	proxy.enabledFeatures.imageCubeArray = proxy.supportedFeatures.imageCubeArray;
	return proxy.enabledFeatures.imageCubeArray;
}


inline bool EnableIndependentBlend(FeatureProxy& proxy)
{
	proxy.enabledFeatures.independentBlend = proxy.supportedFeatures.independentBlend;
	return proxy.enabledFeatures.independentBlend;
}


inline bool EnableGeometryShader(FeatureProxy& proxy)
{
	proxy.enabledFeatures.geometryShader = proxy.supportedFeatures.geometryShader;
	return proxy.enabledFeatures.geometryShader;
}


inline bool EnableTessellationShader(FeatureProxy& proxy)
{
	proxy.enabledFeatures.tessellationShader = proxy.supportedFeatures.tessellationShader;
	return proxy.enabledFeatures.tessellationShader;
}


inline bool EnableSampleRateShading(FeatureProxy& proxy)
{
	proxy.enabledFeatures.sampleRateShading = proxy.supportedFeatures.sampleRateShading;
	return proxy.enabledFeatures.sampleRateShading;
}


inline bool EnableDualSrcBlend(FeatureProxy& proxy)
{
	proxy.enabledFeatures.dualSrcBlend = proxy.supportedFeatures.dualSrcBlend;
	return proxy.enabledFeatures.dualSrcBlend;
}


inline bool EnableLogicOp(FeatureProxy& proxy)
{
	proxy.enabledFeatures.logicOp = proxy.supportedFeatures.logicOp;
	return proxy.enabledFeatures.logicOp;
}


inline bool EnableMultiDrawIndirect(FeatureProxy& proxy)
{
	proxy.enabledFeatures.multiDrawIndirect = proxy.supportedFeatures.multiDrawIndirect;
	return proxy.enabledFeatures.multiDrawIndirect;
}


inline bool EnableDrawIndirectFirstInstance(FeatureProxy& proxy)
{
	proxy.enabledFeatures.drawIndirectFirstInstance = proxy.supportedFeatures.drawIndirectFirstInstance;
	return proxy.enabledFeatures.drawIndirectFirstInstance;
}


inline bool EnableDepthClamp(FeatureProxy& proxy)
{
	proxy.enabledFeatures.depthClamp = proxy.supportedFeatures.depthClamp;
	return proxy.enabledFeatures.depthClamp;
}


inline bool EnableDepthBiasClamp(FeatureProxy& proxy)
{
	proxy.enabledFeatures.depthBiasClamp = proxy.supportedFeatures.depthBiasClamp;
	return proxy.enabledFeatures.depthBiasClamp;
}


inline bool EnableFillModeNonSolid(FeatureProxy& proxy)
{
	proxy.enabledFeatures.fillModeNonSolid = proxy.supportedFeatures.fillModeNonSolid;
	return proxy.enabledFeatures.fillModeNonSolid;
}


inline bool EnableDepthBounds(FeatureProxy& proxy)
{
	proxy.enabledFeatures.depthBounds = proxy.supportedFeatures.depthBounds;
	return proxy.enabledFeatures.depthBounds;
}


inline bool EnableWideLines(FeatureProxy& proxy)
{
	proxy.enabledFeatures.wideLines = proxy.supportedFeatures.wideLines;
	return proxy.enabledFeatures.wideLines;
}


inline bool EnableLargePoints(FeatureProxy& proxy)
{
	proxy.enabledFeatures.largePoints = proxy.supportedFeatures.largePoints;
	return proxy.enabledFeatures.largePoints;
}


inline bool EnableAlphaToOne(FeatureProxy& proxy)
{
	proxy.enabledFeatures.alphaToOne = proxy.supportedFeatures.alphaToOne;
	return proxy.enabledFeatures.alphaToOne;
}


inline bool EnableMultiViewport(FeatureProxy& proxy)
{
	proxy.enabledFeatures.multiViewport = proxy.supportedFeatures.multiViewport;
	return proxy.enabledFeatures.multiViewport;
}


inline bool EnableSamplerAnisotropy(FeatureProxy& proxy)
{
	proxy.enabledFeatures.samplerAnisotropy = proxy.supportedFeatures.samplerAnisotropy;
	return proxy.enabledFeatures.samplerAnisotropy;
}


inline bool EnableTextureCompressionETC2(FeatureProxy& proxy)
{
	proxy.enabledFeatures.textureCompressionETC2 = proxy.supportedFeatures.textureCompressionETC2;
	return proxy.enabledFeatures.textureCompressionETC2;
}


inline bool EnableTextureCompressionASTC_LDR(FeatureProxy& proxy)
{
	proxy.enabledFeatures.textureCompressionASTC_LDR = proxy.supportedFeatures.textureCompressionASTC_LDR;
	return proxy.enabledFeatures.textureCompressionASTC_LDR;
}


inline bool EnableTextureCompressionBC(FeatureProxy& proxy)
{
	proxy.enabledFeatures.textureCompressionBC = proxy.supportedFeatures.textureCompressionBC;
	return proxy.enabledFeatures.textureCompressionBC;
}


inline bool EnableOcclusionQueryPrecise(FeatureProxy& proxy)
{
	proxy.enabledFeatures.occlusionQueryPrecise = proxy.supportedFeatures.occlusionQueryPrecise;
	return proxy.enabledFeatures.occlusionQueryPrecise;
}


inline bool EnablePipelineStatisticsQuery(FeatureProxy& proxy)
{
	proxy.enabledFeatures.pipelineStatisticsQuery = proxy.supportedFeatures.pipelineStatisticsQuery;
	return proxy.enabledFeatures.pipelineStatisticsQuery;
}


inline bool EnableVertexPipelineStoresAndAtomics(FeatureProxy& proxy)
{
	proxy.enabledFeatures.vertexPipelineStoresAndAtomics = proxy.supportedFeatures.vertexPipelineStoresAndAtomics;
	return proxy.enabledFeatures.vertexPipelineStoresAndAtomics;
}


inline bool EnablePixelShaderStoresAndAtomics(FeatureProxy& proxy)
{
	proxy.enabledFeatures.fragmentStoresAndAtomics = proxy.supportedFeatures.fragmentStoresAndAtomics;
	return proxy.enabledFeatures.fragmentStoresAndAtomics;
}


inline bool EnableShaderTessellationAndGeometryPointSize(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderTessellationAndGeometryPointSize = proxy.supportedFeatures.shaderTessellationAndGeometryPointSize;
	return proxy.enabledFeatures.shaderTessellationAndGeometryPointSize;
}


inline bool EnableShaderTextureGatherExtended(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderImageGatherExtended = proxy.supportedFeatures.shaderImageGatherExtended;
	return proxy.enabledFeatures.shaderImageGatherExtended;
}


inline bool EnableShaderUAVExtendedFormats(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderStorageImageExtendedFormats = proxy.supportedFeatures.shaderStorageImageExtendedFormats;
	return proxy.enabledFeatures.shaderStorageImageExtendedFormats;
}


inline bool EnableShaderClipDistance(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderClipDistance = proxy.supportedFeatures.shaderClipDistance;
	return proxy.enabledFeatures.shaderClipDistance;
}


inline bool EnableShaderCullDistance(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderCullDistance = proxy.supportedFeatures.shaderCullDistance;
	return proxy.enabledFeatures.shaderCullDistance;
}


inline bool EnableShaderFloat64(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderFloat64 = proxy.supportedFeatures.shaderFloat64;
	return proxy.enabledFeatures.shaderFloat64;
}


inline bool EnableShaderFloat16(FeatureProxy& proxy)
{
	proxy.enabledFeatures1_2.shaderFloat16 = proxy.supportedFeatures1_2.shaderFloat16;
	return proxy.enabledFeatures1_2.shaderFloat16;
}


inline bool EnableShaderInt64(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderInt64 = proxy.supportedFeatures.shaderInt64;
	return proxy.enabledFeatures.shaderInt64;
}


inline bool EnableShaderInt16(FeatureProxy& proxy)
{
	proxy.enabledFeatures.shaderInt16 = proxy.supportedFeatures.shaderInt16;
	return proxy.enabledFeatures.shaderInt16;
}


inline bool EnableShaderInt8(FeatureProxy& proxy)
{
	proxy.enabledFeatures1_2.shaderInt8 = proxy.supportedFeatures1_2.shaderInt8;
	return proxy.enabledFeatures1_2.shaderInt8;
}

// Vulkan 1.1 features

// Vulkan 1.2 features

// Vulkan extensions

inline bool EnableBufferMarkerAMD(FeatureProxy& proxy)
{
	if (proxy.extensionManager.bufferMarkerAMD.IsAvailable())
	{
		proxy.extensionManager.bufferMarkerAMD.Enable(proxy.enabledDeviceFeatures, proxy.deviceProperties);
		return proxy.extensionManager.bufferMarkerAMD.IsEnabled();
	}
	return false;
}

} // namespace Kodiak