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

#include "ExtensionManagerVk.h"


using namespace Kodiak;
using namespace std;


void ExtensionManager::SetExtensionAvailability(const vector<VkExtensionProperties>& extensions)
{
	for (const auto& extensionProps : extensions)
	{
		auto extension = m_extensionNameMap.find(extensionProps.extensionName);
		if (extension != m_extensionNameMap.end())
		{
			extension->second->m_isAvailable = true;
		}
	}
}


void ExtensionManager::RegisterExtension(IExtension* extension)
{
	m_extensionList.push_back(extension);
	m_extensionNameMap.insert(make_pair(extension->GetName(), extension));
}


vector<const char*> ExtensionManager::GetEnabledExtensionNames() const
{
	vector<const char*> extensionNames;

	for (const auto extension : m_extensionList)
	{
		if (extension->IsEnabled())
		{
			extensionNames.push_back(extension->GetName());
		}
	}

	return extensionNames;
}


bool ExtensionManager::EnableExtension(const string& extensionName, DeviceFeatures& features, DeviceProperties& properties)
{
	auto nameExtensionPair = m_extensionNameMap.find(extensionName);
	if (nameExtensionPair != m_extensionNameMap.end())
	{
		auto extension = nameExtensionPair->second;

		if (extension->IsAvailable())
		{
			extension->Enable(features, properties);
			return extension->IsEnabled();
		}
	}

	return false;
}