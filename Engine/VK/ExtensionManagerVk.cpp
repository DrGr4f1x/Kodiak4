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