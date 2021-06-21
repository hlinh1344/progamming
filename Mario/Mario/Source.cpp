#ifndef UNICODE
#define UNICODE
#endif 
#include <windows.h>
#include <WindowsX.h>


void OnCreate(HWND hwnd);
void OnPaint(HWND hwnd);
void OnKeyDown(HWND hwnd, WPARAM wParam);
void OnClose(HWND hwnd);


int x = 300;
int y = 400;
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
		CW_USEDEFAULT,
		CW_USEDEFAULT,
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
	hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void OnKeyDown(HWND hwnd, WPARAM wParam)
{
	switch (wParam)
	{
	case VK_ESCAPE:
		OnClose(hwnd);
		break;
	case VK_LEFT:
		x -= 10;
		break;
	case VK_RIGHT:
		x += 10;
		break;
	case VK_UP:
		y -= 10;
		break;
	case VK_DOWN:
		y += 10;
		break;
	}
	InvalidateRect(hwnd, NULL, FALSE);
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	BITMAP          bitmap;
	HDC             hdcMem;
	HGDIOBJ         oldBitmap;
	RECT rc1, rc2;
	HPEN hpenOld = static_cast<HPEN>(SelectObject(hdc, GetStockObject(DC_PEN)));
	HBRUSH hbrushOld = CreateSolidBrush(RGB(50, 150, 50));

	FillRect(hdc, &ps.rcPaint, hbrushOld);
	GetWindowRect(hwnd, &rc1);
	GetClientRect(hwnd, &rc1);

	rc1.left = 0;
	rc1.right = 1900;
	rc1.top = 470;
	rc1.bottom = 475;

	rc2.left = 200;
	rc2.right = 205;
	rc2.top = 400;
	rc2.bottom = 475;

	Rectangle(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);
	Rectangle(hdc, 200, 400, 205, 475);
	Ellipse(hdc, 500, 300, 600, 350);
	SelectObject(hdc, hpenOld);
	SelectObject(hdc, hbrushOld);
	hbrushOld = CreateSolidBrush(RGB(255, 155, 50));
	FillRect(hdc, &rc1, hbrushOld);
	hbrushOld = CreateSolidBrush(RGB(250, 55, 50));
	FillRect(hdc, &rc2, hbrushOld);
	//load bitmap
	//length = 67
	//hight = 75
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hBitmap);
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	BitBlt(hdc, x, y, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);

	EndPaint(hwnd, &ps);
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