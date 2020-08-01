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

#include "Input.h"


namespace Kodiak
{

class Application
{
public:
	Application();
	Application(const std::string& name);
	Application(const std::string& name, uint32_t width, uint32_t height);

	void Run();

	// Override these methods in derived classes
	virtual void Configure();
	virtual void Startup() {}
	virtual void Shutdown() {}

	const std::string& GetDefaultShaderPath();

protected:
	const std::string m_name;

	uint32_t m_displayWidth{ 1280 };
	uint32_t m_displayHeight{ 720 };

	HINSTANCE	m_hinst{ 0 };
	HWND		m_hwnd{ 0 };

	// Application state
	bool m_isRunning{ false };
	float m_frameTimer{ 0.0f };

	// Application devices
	std::unique_ptr<InputDevice> m_inputDevice;

private:
	void CreateAppWindow();
	void Initialize();
	void Finalize();
	bool Tick();

	void InitializeSystems();
	void FinalizeSystems();
};

} // namespace Kodiak