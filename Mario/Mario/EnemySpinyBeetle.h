#pragma once
#include "BaseObject.h"
//42x42
#define ENEMY_HEIGHT 42
#define ENEMY_WIDTH 42

class EnemySpinyBeetle : public BaseObject
{
private:

public:
	EnemySpinyBeetle()
	{
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~EnemySpinyBeetle()
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
			300,
			422,
			ENEMY_WIDTH,
			ENEMY_HEIGHT,
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
			300,
			422,
			ENEMY_WIDTH,
			ENEMY_HEIGHT,
			hdcMem,
			0,
			0,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

};