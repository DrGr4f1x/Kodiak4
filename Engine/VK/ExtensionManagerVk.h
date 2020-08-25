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

#include "ExtensionsVk.h"

namespace Kodiak
{

class ExtensionManager
{
	std::vector<IExtension*> m_extensionList;
	std::unordered_map<std::string, IExtension*> m_extensionNameMap;

public:
	void SetExtensionAvailability(const std::vector<VkExtensionProperties>& extensions);
	void RegisterExtension(IExtension* extension);

	BufferMarkerAMD bufferMarkerAMD{ this };
};

} // namespace Kodiak
