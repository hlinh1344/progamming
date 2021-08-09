#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#include <WindowsX.h>
#include <vector>
#pragma comment(lib, "winmm.lib")

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
		L"Ninja Game",
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
	float framePerSecond = 120.0;
	float frameInterval = 1000.0 / framePerSecond;
	while (globalRunning)
	{

		while (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		gamePlay.Run();

		if (gamePlay.CheckClock() == true)
		{
			gamePlay.ResetClock();
			InvalidateRect(hwnd, NULL, FALSE);
		}
		
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
	if (gamePlay.InMenu() == false)
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			OnClose(hwnd);
			break;
		case VK_LEFT:
			gamePlay.MoveNinjaLeft();
			break;
		case VK_RIGHT:
			gamePlay.MoveNinjaRight();
			break;
		case VK_UP:
			gamePlay.MoveNinjaUp();
			break;
		case VK_DOWN:
			gamePlay.MoveNinjaDown();
			break;
		case VK_SPACE:
			gamePlay.Attack();
			break;
		default:
			break;
		}
	}
	else if (gamePlay.InMenu() == true)
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			OnClose(hwnd);
			break;
		case VK_UP:
			gamePlay.UpSelection();
			break;
		case VK_DOWN:
			gamePlay.DownSelection();
			break;
		case VK_RETURN:
		{
			int MenuSelection = gamePlay.Select();
			switch (MenuSelection)
			{
			case 1:
				PlaySound(L"Camp.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 2:
				PlaySound(L"SuperFighter.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 3:
				PlaySound(L"Christmas.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 4:
				PlaySound(L"PangLand.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 5:
				PlaySound(L"Patrit.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 6:
				PlaySound(L"Cake.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 7:
				PlaySound(L"Aqua.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			case 99:
				break;
			case -1:
			{
				globalRunning = 0;
				DestroyWindow(hwnd);
				break;
			}
			default:
				PlaySound(NULL, NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				break;
			}
		}
		break;
		default:
			break;
		}
	}
}

void OnKeyUp(HWND hwnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		gamePlay.KeyUpLeft();
		break;
	case VK_RIGHT:
		gamePlay.KeyUpRight();
		break;
	case VK_UP:
		gamePlay.KeyUpUp();
		break;
	case VK_DOWN:
		gamePlay.KeyUpDown();
		break;
	case VK_SPACE:
		gamePlay.KeyUpSpace();
		break;
	default:
		break;
	}

}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	gamePlay.Draw(hwnd, hdc);
	EndPaint(hwnd, &ps);
}

void OnClose(HWND hwnd)
{
	if (MessageBox(hwnd, L"Really quit?", L"Ninja Game:", MB_OKCANCEL) == IDOK)
	{
		globalRunning = 0;
		DestroyWindow(hwnd);
	}
}