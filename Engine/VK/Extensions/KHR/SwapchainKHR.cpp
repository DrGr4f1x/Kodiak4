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

#include "SwapchainKHR.h"

#include "VK\ExtensionManagerVk.h"


using namespace Kodiak;
using namespace std;


SwapchainKHR::SwapchainKHR(ExtensionManager* manager)
{
	manager->RegisterExtension(this);
}


void SwapchainKHR::Enable(DeviceFeatures& features, DeviceProperties& properties)
{
	m_isEnabled = true;
}


void SwapchainKHR::Initialize(shared_ptr<DeviceRef>& deviceRef)
{
	VkDevice device = *deviceRef;

	extern PFN_vkAcquireNextImageKHR vkAcquireNextImage;
	vkAcquireNextImage = (PFN_vkAcquireNextImageKHR)vkGetDeviceProcAddr(device, "vkAcquireNextImageKHR");

	extern PFN_vkAcquireNextImage2KHR vkAcquireNextImage2;
	vkAcquireNextImage2 = (PFN_vkAcquireNextImage2KHR)vkGetDeviceProcAddr(device, "vkAcquireNextImage2KHR");

	extern PFN_vkCreateSwapchainKHR vkCreateSwapchain;
	vkCreateSwapchain = (PFN_vkCreateSwapchainKHR)vkGetDeviceProcAddr(device, "vkCreateSwapchainKHR");

	extern PFN_vkDestroySwapchainKHR vkDestroySwapchain;
	vkDestroySwapchain = (PFN_vkDestroySwapchainKHR)vkGetDeviceProcAddr(device, "vkDestroySwapchainKHR");

	extern PFN_vkGetSwapchainImagesKHR vkGetSwapchainImages;
	vkGetSwapchainImages = (PFN_vkGetSwapchainImagesKHR)vkGetDeviceProcAddr(device, "vkGetSwapchainImagesKHR");

	extern PFN_vkQueuePresentKHR vkQueuePresent;
	vkQueuePresent = (PFN_vkQueuePresentKHR)vkGetDeviceProcAddr(device, "vkQueuePresentKHR");
}