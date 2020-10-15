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

class InstanceProperties
{
public:
	void Initialize();

	void EnableRequiredLayers();

	bool IsLayerAvailable(const char* name) const;
	bool IsExtensionAvailable(const char* name) const;

	uint32_t GetApiVersion() const { return m_apiVersion; }
	const std::vector<VkLayerProperties>& GetLayerProperties() const { return m_instanceLayerProperties; }
	const std::vector<VkExtensionProperties>& GetExtensionProperties() const { return m_instanceExtensionProperties; }
	const std::vector<const char*>& GetEnabledLayerNames() const { return m_enabledLayerNames; }
	const std::vector<const char*>& GetEnabledExtensionNames() const { return m_enabledExtensionNames; }

private:
	std::vector<VkLayerProperties> m_instanceLayerProperties;
	std::vector<VkExtensionProperties> m_instanceExtensionProperties;

	std::vector<const char*> m_enabledLayerNames;
	std::vector<const char*> m_enabledExtensionNames;

	uint32_t m_apiVersion{ 0 };
};

} // namespace Kodiak