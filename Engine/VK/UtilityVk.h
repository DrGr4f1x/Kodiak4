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

std::vector<VkLayerProperties> EnumerateInstanceLayers()
{
	std::vector<VkLayerProperties> properties;
	uint32_t numLayers = 0;

	ThrowIfFailed(vkEnumerateInstanceLayerProperties(&numLayers, nullptr));

	if (numLayers > 0)
	{
		properties.resize(numLayers);
		ThrowIfFailed(vkEnumerateInstanceLayerProperties(&numLayers, properties.data()));
	}

	return properties;
}


std::vector<VkExtensionProperties> EnumerateInstanceExtensions(const char* pLayerName = nullptr)
{
	std::vector<VkExtensionProperties> properties;
	uint32_t numExtensions = 0;

	ThrowIfFailed(vkEnumerateInstanceExtensionProperties(pLayerName, &numExtensions, nullptr));

	if (numExtensions > 0)
	{
		properties.resize(numExtensions);
		ThrowIfFailed(vkEnumerateInstanceExtensionProperties(pLayerName, &numExtensions, properties.data()));
	}

	return properties;
}

} // namespace Kodiak