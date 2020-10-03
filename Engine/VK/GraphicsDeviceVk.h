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

#include "ExtensionManagerVk.h"


namespace Kodiak
{

struct DeviceProperties
{
	DeviceProperties();

	VkPhysicalDeviceProperties2 deviceProperties2;			// Base Vulkan 1.0 properties
	VkPhysicalDeviceVulkan11Properties deviceProperties1_1; // Vulkan 1.1 properties
	VkPhysicalDeviceVulkan12Properties deviceProperties1_2; // Vulkan 1.2 properties
	void** ppNext{ nullptr };

	void ResetPNextChain();
};


struct DeviceFeatures
{
	DeviceFeatures();

	VkPhysicalDeviceFeatures2			deviceFeatures2;	// Base Vulkan 1.0 features
	VkPhysicalDeviceVulkan11Features	deviceFeatures1_1;	// Vulkan 1.1 features
	VkPhysicalDeviceVulkan12Features	deviceFeatures1_2;	// Vulkan 1.2 features
	void** ppNext{ nullptr };

	std::vector<VkExtensionProperties>	extensions;			// List of supported extensions

	void ResetPNextChain();
};


class GraphicsDevice
{
public:
	GraphicsDevice();

	void Initialize(
		const std::string& appName, 
		HINSTANCE hinst, 
		HWND hwnd, 
		uint32_t width, 
		uint32_t height, 
		Format colorFormat, 
		Format depthFormat);
	void Finalize();

private:
	void CreateInstance();
	void SelectPhysicalDevice();
	void GetPhysicalDeviceFeatures();
	void EnableApplicationFeatures();
	void InitializeDebugMarkup();
	void InitializeValidation();

	void EnableFeatures(bool required);

private:
	// Application members
	std::string m_appName;

	HINSTANCE m_hinst{ 0 };
	HWND m_hwnd{ 0 };

	uint32_t m_width{ 0 };
	uint32_t m_height{ 0 };
	bool m_vsync{ false };
	Format m_colorFormat{ Format::Unknown };
	Format m_depthFormat{ Format::Unknown };

	// Vulkan members
	std::shared_ptr<InstanceRef> m_instance;
	std::shared_ptr<PhysicalDeviceRef> m_physicalDevice;

	// Device features and properties
	DeviceFeatures m_supportedFeatures;
	DeviceFeatures m_enabledFeatures;
	DeviceProperties m_deviceProperties;
	ExtensionManager m_extensions;

	VkPhysicalDeviceMemoryProperties m_memoryProperties{};
	std::vector<VkQueueFamilyProperties> m_queueFamilies;

#if ENABLE_VULKAN_VALIDATION
	std::shared_ptr<DebugUtilsMessengerRef> m_debugUtilsMessenger;
#endif
};

} // namespace Kodiak