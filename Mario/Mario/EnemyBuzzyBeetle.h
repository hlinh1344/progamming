#pragma once
#include "BaseObject.h"
#include "Map.h"
//45x44
#define BUZZY_HEIGHT 45
#define BUZZY_WIDTH 44
//posx = 100;
//posY = 421;

class EnemyBuzzyBeetle : public BaseObject
{
private:

public:
	EnemyBuzzyBeetle(int a_x)
	{
		posX = a_x;
		posY = 421;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemyBuzzyBeetle()
	{
		posX = 0;
		posY = 421;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~EnemyBuzzyBeetle()
	{

	}
	void draw(HWND hwnd, HDC hdc) override
	{
		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hbmMask);
		GetObject(hbmMask, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX - BaseObject::mapSlider,
			posY,
			BUZZY_WIDTH,
			BUZZY_HEIGHT,
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
			posX - BaseObject::mapSlider,
			posY,
			BUZZY_WIDTH,
			BUZZY_HEIGHT,
			hdcMem,
			0,
			0,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

};