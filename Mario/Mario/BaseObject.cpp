#include "BaseObject.h"

BaseObject::BaseObject()
{
	hdcMem = NULL;
	oldBitmap = NULL;
	hbrushOld = NULL;
	hInst = NULL;
	hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
}

BaseObject::~BaseObject()
{

}

void BaseObject::draw(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	//hbrushOld = CreateSolidBrush(RGB(20, 95, 155));
	//FillRect(hdc, &ps.rcPaint, hbrushOld);

	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmMask);
	GetObject(hbmMask, sizeof(bitmap), &bitmap);

	BitBlt
	(
		hdc,
		0,
		400,
		62.5,
		93,
		hdcMem,
		0,
		0,
		SRCAND
	);
	oldBitmap = SelectObject(hdcMem, hBitmap);
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		0,
		400,
		62.5,
		93,
		hdcMem,
		0,
		0,
		SRCPAINT
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
	EndPaint(hwnd, &ps);
}

HBITMAP BaseObject::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
{
	HDC hdcMem, hdcMem2;
	HBITMAP hbmMask;
	BITMAP bm;
	GetObject(hbmColour, sizeof(BITMAP), &bm);
	hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);
	hdcMem = CreateCompatibleDC(0);
	hdcMem2 = CreateCompatibleDC(0);
	SelectBitmap(hdcMem, hbmColour);
	SelectBitmap(hdcMem2, hbmMask);
	SetBkColor(hdcMem, crTransparent);
	BitBlt(hdcMem2, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
	BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCINVERT);
	DeleteDC(hdcMem);
	DeleteDC(hdcMem2);
	return hbmMask;
}