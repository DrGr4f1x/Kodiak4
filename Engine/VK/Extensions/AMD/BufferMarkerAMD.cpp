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

#include "BufferMarkerAMD.h"

#include "VK\ExtensionManagerVk.h"


using namespace Kodiak;
using namespace std;


BufferMarkerAMD::BufferMarkerAMD(ExtensionManager* manager)
{
	manager->RegisterExtension(this);
}


void BufferMarkerAMD::Enable(DeviceFeatures& features, DeviceProperties& properties)
{
	m_isEnabled = true;
}