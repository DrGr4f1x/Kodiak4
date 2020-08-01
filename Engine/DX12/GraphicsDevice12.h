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
};

} // namespace Kodiak