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


void DebugUtilsEXT::Initialize(shared_ptr<DeviceRef>& deviceRef)
{
	VkDevice device = *deviceRef;

#if ENABLE_VULKAN_DEBUG_MARKUP || ENABLE_VULKAN_VALIDATION
	extern PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabel;
	vkCmdBeginDebugUtilsLabel = (PFN_vkCmdBeginDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkCmdBeginDebugUtilsLabelEXT");

	extern PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabel;
	vkCmdEndDebugUtilsLabel = (PFN_vkCmdEndDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkCmdEndDebugUtilsLabelEXT");

	extern PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabel;
	vkCmdInsertDebugUtilsLabel = (PFN_vkCmdInsertDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkCmdInsertDebugUtilsLabelEXT");

	extern PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabel;
	vkQueueBeginDebugUtilsLabel = (PFN_vkQueueBeginDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkQueueBeginDebugUtilsLabelEXT");

	extern PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabel;
	vkQueueEndDebugUtilsLabel = (PFN_vkQueueEndDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkQueueEndDebugUtilsLabelEXT");

	extern PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabel;
	vkQueueInsertDebugUtilsLabel = (PFN_vkQueueInsertDebugUtilsLabelEXT)vkGetDeviceProcAddr(device, "vkQueueInsertDebugUtilsLabelEXT");

	extern PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectName;
	vkSetDebugUtilsObjectName = (PFN_vkSetDebugUtilsObjectNameEXT)vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectNameEXT");

	extern PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTag;
	vkSetDebugUtilsObjectTag = (PFN_vkSetDebugUtilsObjectTagEXT)vkGetDeviceProcAddr(device, "vkSetDebugUtilsObjectTagEXT");
#endif

#if ENABLE_VULKAN_VALIDATION
	extern PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessenger;
	vkCreateDebugUtilsMessenger = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetDeviceProcAddr(device, "vkCreateDebugUtilsMessengerEXT");

	extern PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessenger;
	vkDestroyDebugUtilsMessenger = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetDeviceProcAddr(device, "vkDestroyDebugUtilsMessengerEXT");

	extern PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessage;
	vkSubmitDebugUtilsMessage = (PFN_vkSubmitDebugUtilsMessageEXT)vkGetDeviceProcAddr(device, "vkSubmitDebugUtilsMessageEXT");
#endif
}