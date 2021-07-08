#pragma once
#include "BaseObject.h"
//45x44
#define ENEMY_HEIGHT 45
#define ENEMY_WIDTH 44
//posx = 100;
//posY = 421;

class EnemyDuck : public BaseObject
{
private:

public:
	EnemyDuck(int a_x, int a_y)
	{
		posX = a_x;
		posY = a_y;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemyDuck()
	{
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~EnemyDuck()
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
			posX - mapSlider,
			posY,
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
			posX - mapSlider,
			posY,
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