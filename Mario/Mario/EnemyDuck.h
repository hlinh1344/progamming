#pragma once
#include "BaseObject.h"
//60x45
#define ENEMY_HEIGHT 60
#define ENEMY_WIDTH 45

//pos x = 200
//pos y = 202

class EnemyBuzzyBeetle : public BaseObject
{
private:

public:

	EnemyBuzzyBeetle(int a_x, int a_y)
	{
		posX = a_x;
		posY = a_y;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}

	EnemyBuzzyBeetle()
	{
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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