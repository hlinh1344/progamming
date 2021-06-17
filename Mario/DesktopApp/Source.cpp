#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "resource.h"

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
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        900,
        550,
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
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}


    //WndProc 
HBITMAP hBitmap = NULL;
HINSTANCE hInst = NULL;
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    BITMAP          bitmap;
    HDC             hdcMem;
    HGDIOBJ         oldBitmap;
    RECT rc1;
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CREATE:
        hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        //hBitmap = LoadBitmapW(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
        break;
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:

            break;

        case VK_RIGHT:

            break;

        case VK_UP:

            break;

        case VK_DOWN:

            break;
        }
        case WM_PAINT:

        {
            hdc = BeginPaint(hwnd, &ps);
            HPEN hpenOld = static_cast<HPEN>(SelectObject(hdc, GetStockObject(DC_PEN)));
            HBRUSH hbrushOld = CreateSolidBrush(RGB(50, 150, 50));
            FillRect(hdc, &ps.rcPaint, hbrushOld);
            GetClientRect(hwnd, &rc1);
            rc1.left = 100;
            rc1.right = 175;
            rc1.top = 10;
            rc1.bottom = 85;
            Rectangle(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);
            SelectObject(hdc, hpenOld);
            SelectObject(hdc, hbrushOld);
            hbrushOld = CreateSolidBrush(RGB(150, 255, 50));
            FillRect(hdc, &rc1, hbrushOld);

            //load bitmap
            hdcMem = CreateCompatibleDC(hdc);
            oldBitmap = SelectObject(hdcMem, hBitmap);
            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 10, 10, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
            SelectObject(hdcMem, oldBitmap);
            DeleteDC(hdcMem);

            EndPaint(hwnd, &ps);
        }
        return 0;


        case WM_CLOSE:
            if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
            {
                DestroyWindow(hwnd);
            }
            return 0;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        return 0;
}
