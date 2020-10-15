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

#include "InstancePropertiesVk.h"

#include "UtilityVk.h"


using namespace std;
using namespace Kodiak;


void InstanceProperties::Initialize()
{
	VkFunc::EnumerateInstanceVersion(&m_apiVersion);

	m_instanceLayerProperties = EnumerateInstanceLayers();
	m_instanceExtensionProperties = EnumerateInstanceExtensions();
}


void InstanceProperties::EnableRequiredLayers()
{
	vector<const char*> requiredLayerNames =
	{
#if ENABLE_VULKAN_VALIDATION
			"VK_LAYER_KHRONOS_validation"
#endif
	};

	for (const auto layerName : requiredLayerNames)
	{
		assert_msg(IsLayerAvailable(layerName), "Required layer %s is not available", layerName);

		m_enabledLayerNames.push_back(layerName);
	}
}


bool InstanceProperties::IsLayerAvailable(const char* name) const
{
	return find_if(
		m_instanceLayerProperties.begin(),
		m_instanceLayerProperties.end(),
		[name](const VkLayerProperties& layerProps) -> bool {
		return strcmp(layerProps.layerName, name) == 0;
	}) != m_instanceLayerProperties.end();
}


bool InstanceProperties::IsExtensionAvailable(const char* name) const
{
	return find_if(
		m_instanceExtensionProperties.begin(),
		m_instanceExtensionProperties.end(),
		[name](const VkExtensionProperties& extProps) -> bool {
		return strcmp(extProps.extensionName, name) == 0;
	}) != m_instanceExtensionProperties.end();
}