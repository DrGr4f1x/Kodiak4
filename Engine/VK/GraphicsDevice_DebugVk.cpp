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

#include "GraphicsDeviceVk.h"


using namespace Kodiak;
using namespace std;


#if ENABLE_VULKAN_DEBUG_MARKUP
PFN_vkSetDebugUtilsObjectTagEXT vkSetDebugUtilsObjectTag{ nullptr };
PFN_vkSetDebugUtilsObjectNameEXT vkSetDebugUtilsObjectName{ nullptr };

PFN_vkCmdBeginDebugUtilsLabelEXT vkCmdBeginDebugUtilsLabel{ nullptr };
PFN_vkCmdEndDebugUtilsLabelEXT vkCmdEndDebugUtilsLabel{ nullptr };
PFN_vkCmdInsertDebugUtilsLabelEXT vkCmdInsertDebugUtilsLabel{ nullptr };

PFN_vkQueueBeginDebugUtilsLabelEXT vkQueueBeginDebugUtilsLabel{ nullptr };
PFN_vkQueueEndDebugUtilsLabelEXT vkQueueEndDebugUtilsLabel{ nullptr };
PFN_vkQueueInsertDebugUtilsLabelEXT vkQueueInsertDebugUtilsLabel{ nullptr };

static bool g_debugMarkupAvailable = false;
#endif

#if ENABLE_VULKAN_VALIDATION
PFN_vkCreateDebugUtilsMessengerEXT vkCreateDebugUtilsMessenger{ nullptr };
PFN_vkDestroyDebugUtilsMessengerEXT vkDestroyDebugUtilsMessenger{ nullptr };
PFN_vkSubmitDebugUtilsMessageEXT vkSubmitDebugUtilsMessage{ nullptr };

VkBool32 MessageCallback(
	VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
	VkDebugUtilsMessageTypeFlagsEXT messageType,
	const VkDebugUtilsMessengerCallbackDataEXT* callbackData)
{
	// TODO_DME - fill this in

	return VK_TRUE;
}
#endif


void GraphicsDevice::InitializeDebugMarkup()
{

}


void GraphicsDevice::InitializeValidation()
{
#if ENABLE_VULKAN_VALIDATION
	VkInstance instance = *m_instance;

	vkCreateDebugUtilsMessenger =
		reinterpret_cast<PFN_vkCreateDebugUtilsMessengerEXT>(vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT"));
	vkDestroyDebugUtilsMessenger =
		reinterpret_cast<PFN_vkDestroyDebugUtilsMessengerEXT>(vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessenger"));
	vkSubmitDebugUtilsMessage =
		reinterpret_cast<PFN_vkSubmitDebugUtilsMessageEXT>(vkGetInstanceProcAddr(instance, "vkSubmitDebugUtilsMessageEXT"));

	assert(vkCreateDebugUtilsMessenger);
	assert(vkDestroyDebugUtilsMessenger);
	assert(vkSubmitDebugUtilsMessage);

	// The report flags determine what type of messages for the layers will be displayed
	// For validating (debugging) an application the error and warning bits should suffice
	VkDebugUtilsMessageSeverityFlagsEXT debugMessageSeverityFlags =
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT |           // messageSeverity
		VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT;

	VkDebugUtilsMessageTypeFlagsEXT debugMessageTypeFlags =
		VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |             // messageType
		VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT;

	auto createInfo = DebugUtilsMessengerCreateInfo();
	createInfo.pfnUserCallback = (PFN_vkDebugUtilsMessengerCallbackEXT)MessageCallback;
	createInfo.messageSeverity = debugMessageSeverityFlags;
	createInfo.messageType = debugMessageTypeFlags;

	VkDebugUtilsMessengerEXT debugUtilsMessenger{ VK_NULL_HANDLE };
	ThrowIfFailed(vkCreateDebugUtilsMessenger(instance, &createInfo, nullptr, &debugUtilsMessenger));

	m_debugUtilsMessenger = DebugUtilsMessengerRef::Create(m_instance, debugUtilsMessenger);
#endif
}