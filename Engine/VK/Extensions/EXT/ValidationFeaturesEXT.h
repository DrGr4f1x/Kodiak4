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

class ValidationFeaturesEXT : public IExtension
{
public:
	ValidationFeaturesEXT(ExtensionManager* manager);

	const char* GetName() const final { return VK_EXT_DEBUG_UTILS_EXTENSION_NAME; }

	void Enable(DeviceFeatures& features, DeviceProperties& properties) final;

private:
	VkValidationFeaturesEXT m_validationFeatures;
};

} // namespace Kodiak
