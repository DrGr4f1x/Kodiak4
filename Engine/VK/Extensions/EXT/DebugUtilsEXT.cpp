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

#include "DebugUtilsEXT.h"

#include "VK\ExtensionManagerVk.h"


using namespace Kodiak;
using namespace std;


DebugUtilsEXT::DebugUtilsEXT(ExtensionManager* manager)
{
	manager->RegisterExtension(this);
}


void DebugUtilsEXT::Enable(DeviceFeatures& features, DeviceProperties& properties)
{
	m_isEnabled = true;
}