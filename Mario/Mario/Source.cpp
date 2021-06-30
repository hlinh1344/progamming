#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#include <WindowsX.h>
#include "Character.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 575

void OnCreate(HWND hwnd);
void OnPaint(HWND hwnd);
void OnKeyDown(HWND hwnd, WPARAM wParam);
void OnKeyUp(HWND hwnd, WPARAM wParam);
void OnClose(HWND hwnd);
Character Mario;

int globalRunning = 1;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"Sample Window Class";
	WNDCLASS wc = { };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	RegisterClass(&wc);
	// Create the window.
	HWND hwnd = CreateWindowEx
	(
		0,
		CLASS_NAME,
		L"Mario Game",
		//Disable window resizing
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);


	if (hwnd == NULL)
	{
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	MSG msg = { };
	float framePerSecond = 60.0;
	float frameInterval = 1000.0 / framePerSecond;
	while (globalRunning)
	{
		while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//Sleep(frameInterval);
	}
	return msg.wParam;
}


HBITMAP hBitmap = NULL;
HINSTANCE hInst = NULL;



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_CLOSE:
		OnClose(hwnd);
		return 0;
	case WM_PAINT:
		OnPaint(hwnd);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		OnKeyDown(hwnd, wParam);
		return 0;
	case WM_KEYUP:
		OnKeyUp(hwnd, wParam);
		return 0;
	case WM_CREATE:
		OnCreate(hwnd);
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

void OnCreate(HWND hwnd)
{

}

void OnKeyDown(HWND hwnd, WPARAM wParam)
{
	
	switch (wParam)
	{
	case VK_ESCAPE:
		OnClose(hwnd);
		break;
	case VK_LEFT:
		Mario.moveLeft();
		break;
	case VK_RIGHT:
		Mario.moveRight();
		break;
	case VK_UP:
		Mario.moveUp();
		break;
	case VK_DOWN:
		Mario.moveDown();
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnKeyUp(HWND hwnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		Mario.setFormX(6);
		break;
	case VK_RIGHT:
		Mario.setFormX(7);
		break;
	case VK_UP:
		Mario.incresePosY(40);
		if(Mario.isGoRight())
			Mario.setFormX(7);
		else
			Mario.setFormX(6);
		break;
	case VK_DOWN:
		if (Mario.isGoRight())
			Mario.setFormX(7);
		else
			Mario.setFormX(6);
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnPaint(HWND hwnd)
{
	//if (Mario.getPosX() < 330)
	//	Mario.setFormY(0);
	//else if (Mario.getPosX() > 660)
	//	Mario.setFormY(2);
	//else
	//	Mario.setFormY(1);
	Mario.setFormY(2);
	Mario.draw(hwnd);
}

void OnClose(HWND hwnd)
{
	if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
	{
		globalRunning = 0;
		DestroyWindow(hwnd);
	}
}