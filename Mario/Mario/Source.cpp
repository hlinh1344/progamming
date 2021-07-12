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
	float framePerSecond = 60.0;
	float frameInterval = 1000.0 / framePerSecond;
	while (globalRunning)
	{
		while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		gamePlay.run();

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
		gamePlay.moveMarioLeft();
		break;
	case VK_RIGHT:
		gamePlay.moveMarioRight();
		break;
	case VK_UP:
		gamePlay.moveMarioUp();
		break;
	case VK_DOWN:
		gamePlay.moveMarioDown();
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnKeyUp(HWND hwnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		gamePlay.keyUpMarioLeft();
		break;
	case VK_RIGHT:
		gamePlay.keyUpMarioRight();
		break;
	case VK_UP:
		gamePlay.keyUpMarioUp();
		break;
	case VK_DOWN:
		gamePlay.keyUpMarioDown();
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnPaint(HWND hwnd)
{
	//Mario.setFormY(2);
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	gamePlay.draw(hwnd, hdc);
	//map.draw(hwnd, hdc);
	//Mario.draw(hwnd, hdc);
	//e1.draw(hwnd, hdc);
	//e2.draw(hwnd, hdc);
	//e3.draw(hwnd, hdc);
	//e4.draw(hwnd, hdc);
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