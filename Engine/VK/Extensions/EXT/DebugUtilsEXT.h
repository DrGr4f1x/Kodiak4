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

namespace Kodiak
{

class DebugUtilsEXT : public IExtension
{
public:
	DebugUtilsEXT(ExtensionManager* manager);

	const char* GetName() const final { return VK_EXT_DEBUG_UTILS_EXTENSION_NAME; }

	void Enable(DeviceFeatures& features, DeviceProperties& properties) final;
	void Initialize(std::shared_ptr<DeviceRef>& deviceRef) final;
};

} // namespace Kodiak