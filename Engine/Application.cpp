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

	m_hwnd = CreateWindow(appNameWithAPI.c_str(), appNameWithAPI.c_str(), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, m_hinst, nullptr);

	assert(m_hwnd != 0);

	Initialize();

	ShowWindow(m_hwnd, SW_SHOWDEFAULT);

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


void Application::Initialize()
{
	Configure();

	Startup();

	m_isRunning = true;
}


void Application::Finalize()
{
	Shutdown();
}


bool Application::Tick()
{
	if (!m_isRunning)
		return false;

	return true;
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