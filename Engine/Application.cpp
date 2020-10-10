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

#include "Application.h"

#include "Filesystem.h"

#pragma comment(lib, "runtimeobject.lib")


using namespace Kodiak;
using namespace std;


// Forward declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


Application::Application()
	: m_name("Unnamed")
{}


Application::Application(const string& name)
	: m_name(name)
{}


Application::Application(const string& name, uint32_t width, uint32_t height)
	: m_name(name)
	, m_displayWidth(width)
	, m_displayHeight(height)
{}


void Application::Run()
{
	// TODO: Move this after Configure in Initialize (so that the app can specify the resolution in Configure)
	CreateAppWindow();

	Initialize();

	ShowWindow(m_hwnd, SW_SHOWDEFAULT);

	LOG_NOTICE << "Beginning main loop";

	do
	{
		MSG msg = {};
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	} while (Tick());	// Returns false to quit loop

	LOG_NOTICE << "Terminating main loop" << endl;

	Finalize();
}


void Application::Configure()
{
	// Setup file system
	auto& filesystem = Filesystem::GetInstance();

	filesystem.SetDefaultRootPath();
	filesystem.AddSearchPath("Data\\" + GetDefaultShaderPath());
	filesystem.AddSearchPath("..\\Data");
	filesystem.AddSearchPath("..\\Data\\" + GetDefaultShaderPath());
	filesystem.AddSearchPath("..\\Data\\Textures");
	filesystem.AddSearchPath("..\\Data\\Models");
}


const string& Application::GetDefaultShaderPath()
{
	return s_defaultShaderPath;
}


void Application::CreateAppWindow()
{
	Microsoft::WRL::Wrappers::RoInitializeWrapper InitializeWinRT(RO_INIT_MULTITHREADED);
	assert_succeeded(InitializeWinRT);

	m_hinst = GetModuleHandle(0);

	string appNameWithAPI = s_apiPrefixString + " " + m_name;

	// Register class
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hinst;
	wcex.hIcon = LoadIcon(m_hinst, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = appNameWithAPI.c_str();
	wcex.hIconSm = LoadIcon(m_hinst, IDI_APPLICATION);
	assert_msg(0 != RegisterClassEx(&wcex), "Unable to register a window");

	// Create window
	RECT rc = { 0, 0, (LONG)m_displayWidth, (LONG)m_displayHeight };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	m_hwnd = CreateWindow(
		appNameWithAPI.c_str(), 
		appNameWithAPI.c_str(), 
		WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, 
		CW_USEDEFAULT,
		rc.right - rc.left, 
		rc.bottom - rc.top, 
		nullptr, 
		nullptr, 
		m_hinst, 
		nullptr);

	assert(m_hwnd != 0);

	LOG_NOTICE << appNameWithAPI << endl;
}


void Application::Initialize()
{
	LOG_NOTICE << "Initializing application" << endl;

	// Run application-specific configuration (before the graphics device is created)
	Configure();

	// Initialize logging.  This is done after Configure so that, if the application sets the root
	// directory to a non-default path, the Logs directory is created relative to the actual application
	// root.
	// Note that any logs added before the logging system is started will simply sit in the log queue
	// and will be processed when the log handling thread starts.
	InitializeLogging();

	// Initialize systems, such as the graphics and input devices
	InitializeSystems();

	// Run application-specific startup logic.  The graphics device exists at this point, so it is safe
	// to create rendering resources such as textures and shaders.
	Startup();

	m_isRunning = true;

	LOG_NOTICE << "  Initialization complete" << endl;
}


void Application::Finalize()
{
	LOG_NOTICE << "Finalizing application";

	// Run application-specific shutdown logic.
	Shutdown();
	
	// Finalize systems, such as the graphics and input devices
	FinalizeSystems();

	LOG_NOTICE << "  Finalization complete";

	// Finalize logging last, so that logging is available to the application-specific Shutdown routine, 
	// and so that the graphics device and other systems can log out messages during finalization.
	FinalizeLogging();
}


bool Application::Tick()
{
	if (!m_isRunning)
	{
		return false;
	}

	auto timeStart = chrono::high_resolution_clock::now();

	m_inputDevice->Update(m_frameTimer);

	// Close on Escape key
	if (m_inputDevice->IsFirstPressed(DigitalInput::kKey_escape))
	{
		return false;
	}

	auto timeEnd = chrono::high_resolution_clock::now();
	auto timeDiff = chrono::duration<double, std::milli>(timeEnd - timeStart).count();
	m_frameTimer = static_cast<float>(timeDiff) / 1000.0f;

	return true;
}


void Application::InitializeSystems()
{
	// Initialize the graphics device
	m_graphicsDevice = make_unique<GraphicsDevice>();
	m_graphicsDevice->Initialize(
		m_name, 
		m_hinst, 
		m_hwnd, 
		m_displayWidth, 
		m_displayHeight, 
		Format::R8G8B8A8_UNorm, 
		Format::D32_Float_S8_UInt);

	// Initialize the input device
	m_inputDevice = make_unique<InputDevice>();
	m_inputDevice->Initialize(m_hwnd);

	// Initialize the UI overlay
}


void Application::FinalizeSystems()
{
	// Destroy the UI overlay

	// Finalize the input device
	m_inputDevice->Finalize();

	// Destroy the graphics device
	m_graphicsDevice->Finalize();
}


//--------------------------------------------------------------------------------------
// Called every time the application receives a message
//--------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_MOUSEMOVE:
	{
		//if (g_application)
		//{
			//g_application->OnMouseMove(LOWORD(lParam), HIWORD(lParam));
		//}
		break;
	}

	case WM_SIZE:
		//Graphics::Resize(LOWORD(lParam), HIWORD(lParam));
		break;

	case WM_CLOSE:
		//GetApplication()->Stop(); // TODO - Can we detect device removed in Vulkan?  This is hacky...
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}