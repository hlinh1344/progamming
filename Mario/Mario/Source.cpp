#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#include <WindowsX.h>
#include "Character.h"

#define WINDOW_WIDTH 1000;
#define WINDOW_HEIGHT 600;

void OnCreate(HWND hwnd);
void OnPaint(HWND hwnd, Character &Mario);
void OnKeyDown(HWND hwnd, WPARAM wParam, Character &Mario);
void OnKeyUp(HWND hwnd, WPARAM wParam, Character &Mario);
void OnClose(HWND hwnd);


int posX = 0;
int posY = 400;
int characterX = 0;
int characterY = 0;
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
		1000,
		600,
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

	// Run the message loop.
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
		Sleep(frameInterval);
	}
	return msg.wParam;
}

//WndProc 
HBITMAP hBitmap = NULL;
HINSTANCE hInst = NULL;



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	Character Mario;
	switch (uMsg)
	{
	case WM_CLOSE:
		OnClose(hwnd);
		return 0;
	case WM_PAINT:
		OnPaint(hwnd, Mario);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		OnKeyDown(hwnd, wParam, Mario);
		return 0;
	case WM_KEYUP:
		OnKeyUp(hwnd, wParam, Mario);
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
	//hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void OnKeyDown(HWND hwnd, WPARAM wParam, Character &Mario)
{
	
	switch (wParam)
	{
	case VK_ESCAPE:
		OnClose(hwnd);
		break;
	case VK_LEFT:
		Mario.setPosX(Mario.getPosX() - 10);
		//posX -= 10;
		if (Mario.getPosX() <= 0)
		{
			Mario.setPosX(Mario.getPosX() + 10);
		}
		Mario.setFormY(1);

		if (Mario.getFormX() >=3)
		{
			Mario.setFormX(0);
		}
		else
		{
			Mario.setFormX(Mario.getFormX() + 1);
		}

		Mario.draw(hwnd);
		break;
	case VK_RIGHT:
		//posX += 10;
		Mario.setPosX(Mario.getPosX() + 10);

		//if (posX >= (1000 - 90))
		//{
		//	posX -= 10;
		//}
		if (Mario.getPosX() >= (1000 - 90))
		{
			Mario.setPosX(Mario.getPosX() - 10);
		}
		//characterY = 0;
		Mario.setFormY(0);

		//if (characterX >= 3)
		//{
		//	characterX = 0;
		//}
		//else
		//{
		//	characterX++;
		//}
		if (Mario.getFormX() >= 3)
		{
			Mario.setFormX(0);
		}
		else
		{
			Mario.setFormX(Mario.getFormX() + 1);
		}
		Mario.draw(hwnd);

		break;
	case VK_UP:
		posY -= 40;
		if (posY <= 350)
		{
			posY += 40;
		}
		characterX = 4;
		break;
	case VK_DOWN:
		characterX = 5;
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnKeyUp(HWND hwnd, WPARAM wParam, Character &Mario)
{
	switch (wParam)
	{
	case VK_LEFT:
		//characterX = 0;
		Mario.setFormX(0);
		Mario.draw(hwnd);

		break;
	case VK_RIGHT:
		//characterX = 0;
		Mario.setFormX(0);
		Mario.draw(hwnd);

		break;
	case VK_UP:
		posY += 40;
		characterX = 0;
		break;
	case VK_DOWN:
		characterX = 0;
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnPaint(HWND hwnd, Character &Mario)
{
	//PAINTSTRUCT ps;
	Mario.draw(hwnd);
	//EndPaint(hwnd, &ps);
}

void OnClose(HWND hwnd)
{
	if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
	{
		globalRunning = 0;
		DestroyWindow(hwnd);
	}
	// Else: User canceled. Do nothing.	
}