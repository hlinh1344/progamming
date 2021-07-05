#pragma once
#include "BaseObject.h"
//44x43
#define ENEMY_HEIGHT 43
#define ENEMY_WIDTH 44

class EnemyMushroom : public BaseObject
{
private:
	int enemyForm;
	clock_t start = clock();
public:
	EnemyMushroom()
	{
		posX = 1600;
		posY = 422;
		enemyForm  = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~EnemyMushroom()
	{

	}

	void draw(HWND hwnd, HDC hdc) override 
	{
		{
			hdcMem = CreateCompatibleDC(hdc);
			oldBitmap = SelectObject(hdcMem, hbmMask);
			GetObject(hbmMask, sizeof(bitmap), &bitmap);
			BitBlt
			(
				hdc,
				posX ,
				posY,
				ENEMY_WIDTH,
				ENEMY_HEIGHT,
				hdcMem,
				ENEMY_WIDTH * enemyForm,
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
				ENEMY_WIDTH * enemyForm,
				0,
				SRCPAINT
			);
			if (enemyForm == 1)
				enemyForm = 0;
			else
				enemyForm = 1;
			SelectObject(hdcMem, oldBitmap);
			DeleteDC(hdcMem);
		}		
	}
};