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

#include "VK\Extensions\IExtensionVk.h"

// AMD
#include "VK\Extensions\AMD\BufferMarkerAMD.h"

// EXT
#include "VK\Extensions\EXT\DebugUtilsEXT.h"
#include "VK\Extensions\EXT\ValidationFeaturesEXT.h"

// KHR
#include "VK\Extensions\KHR\SwapchainKHR.h"


namespace Kodiak
{

class ExtensionManager
{
	std::vector<IExtension*> m_extensionList;
	std::unordered_map<std::string, IExtension*> m_extensionNameMap;

public:
	void SetExtensionAvailability(const std::vector<VkExtensionProperties>& extensions);
	void RegisterExtension(IExtension* extension);
	std::vector<const char*> GetEnabledExtensionNames() const;
	bool EnableExtension(const std::string& extensionName, DeviceFeatures& features, DeviceProperties& properties);
	void InitializeExtensions(std::shared_ptr<DeviceRef>& deviceRef);

	// AMD
	BufferMarkerAMD bufferMarkerAMD{ this };

	// EXT
	DebugUtilsEXT debugUtilsEXT{ this };
	ValidationFeaturesEXT validationFeaturesEXT{ this };

	// KHR
	SwapchainKHR swapchainKHR{ this };
};

} // namespace Kodiak
