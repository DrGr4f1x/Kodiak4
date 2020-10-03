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

#include "ValidationFeaturesEXT.h"

#include "VK\GraphicsDeviceVk.h"
#include "VK\ExtensionManagerVk.h"
#include "Vk\StructuresVk.h"


using namespace Kodiak;
using namespace std;


ValidationFeaturesEXT::ValidationFeaturesEXT(ExtensionManager* manager)
	: m_validationFeatures{ValidationFeatures()}
{
	manager->RegisterExtension(this);
}


void ValidationFeaturesEXT::Enable(DeviceFeatures& features, DeviceProperties& properties)
{
	// Setup enabled and disabled validation features here

	// Attach to pNext chain
	*features.ppNext = &m_validationFeatures;
	features.ppNext = const_cast<void**>(&m_validationFeatures.pNext);

	m_isEnabled = true;
}