#pragma once
#include <windows.h>
#include <WindowsX.h>

class BaseObject
{
private:
	HBITMAP hBitmap, hbmMask, hBitmap2;
	HINSTANCE hInst;
	HDC hdcMem;
	HGDIOBJ oldBitmap;
	BITMAP bitmap;
	HBRUSH hbrushOld;
public:
	BaseObject();
	~BaseObject();
	void draw(HWND hwnd);
	HBITMAP CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent);
};

