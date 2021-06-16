#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HBITMAP hBitmap = NULL;
HINSTANCE hInst = NULL;
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[] = L"Sample Window Class";

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
    // Create the window.

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Mario Game",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop.
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;

    case WM_CREATE:
        hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        break;

    case WM_PAINT:
       
        {
            // Set up the device context for drawing.
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            BITMAP          bitmap;
            HDC             hdcMem;
            HGDIOBJ         oldBitmap;

            HPEN hpenOld = static_cast<HPEN>(SelectObject(hdc, GetStockObject(DC_PEN)));
            HBRUSH hbrushOld = static_cast<HBRUSH>(SelectObject(hdc, GetStockObject(NULL_BRUSH)));
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 20));
            RECT rc1;
            GetClientRect(hwnd, &rc1);
            rc1.right = 94;
            rc1.bottom = 102;
            InflateRect(&rc1, -5, -5);
            SetDCPenColor(hdc, RGB(255, 0, 0));    // red
            Rectangle(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);
            SelectObject(hdc, hpenOld);
            SelectObject(hdc, hbrushOld);
            //load bitmap
            hdcMem = CreateCompatibleDC(hdc);
            oldBitmap = SelectObject(hdcMem, hBitmap);
            GetObject(hBitmap, sizeof(bitmap), &bitmap);
            BitBlt(hdc, 13, 13, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
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
        // Else: User canceled. Do nothing.
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}