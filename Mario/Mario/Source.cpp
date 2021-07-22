#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#include <WindowsX.h>
#include <vector>

#include "Character.h"
#include "BaseObject.h"
#include "EnemyMushroom.h"
#include "EnemyDuck.h"
#include "EnemyBuzzyBeetle.h"
#include "EnemySpinyBeetle.h"
#include "Map.h"
#include "GamePlay.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 575

void OnCreate(HWND hwnd);
void OnPaint(HWND hwnd);
void OnKeyDown(HWND hwnd, WPARAM wParam);
void OnKeyUp(HWND hwnd, WPARAM wParam);
void OnClose(HWND hwnd);

GamePlay gamePlay;


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
	HWND hwnd = CreateWindowEx
	(
		0,
		CLASS_NAME,
		L"Mario Game",
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
	float framePerSecond = 25.0;
	float frameInterval = 1000.0 / framePerSecond;
	while (globalRunning)
	{
		while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		gamePlay.Run();
		InvalidateRect(hwnd, NULL, FALSE);
		Sleep(frameInterval);
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
		gamePlay.MoveMarioLeft();
		break;
	case VK_RIGHT:
		gamePlay.MoveMarioRight();
		break;
	case VK_UP:
		gamePlay.MoveMarioUp();
		break;
	case VK_DOWN:
		gamePlay.MoveMarioDown();
		break;
	case VK_SPACE:
		gamePlay.Attack();
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnKeyUp(HWND hwnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		gamePlay.KeyUpMarioLeft();
		break;
	case VK_RIGHT:
		gamePlay.KeyUpMarioRight();
		break;
	case VK_UP:
		gamePlay.KeyUpMarioUp();
		InvalidateRect(hwnd, NULL, FALSE);
		break;
	case VK_DOWN:
		gamePlay.KeyUpMarioDown();
		break;
	case VK_SPACE:
		gamePlay.KeyUpSpace();
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnPaint(HWND hwnd)
{
	//Mario.SetFormY(2);
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	gamePlay.Draw(hwnd, hdc);
	//map.Draw(hwnd, hdc);
	//Mario.Draw(hwnd, hdc);
	//e1.Draw(hwnd, hdc);
	//e2.Draw(hwnd, hdc);
	//e3.Draw(hwnd, hdc);
	//e4.Draw(hwnd, hdc);
	EndPaint(hwnd, &ps);

}

void OnClose(HWND hwnd)
{
	if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
	{
		globalRunning = 0;
		DestroyWindow(hwnd);
	}
}