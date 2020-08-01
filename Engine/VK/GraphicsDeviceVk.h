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

namespace Kodiak
{

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
};

} // namespace Kodiak