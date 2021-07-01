#pragma once
#include "BaseObject.h"
//44x20
#define ENEMY_WIDTH 44
#define ENEMY_HEIGHT 43
class EnemyMushroom : public BaseObject
{
private:
	int enemyForm;
public:
	EnemyMushroom()
	{
		posX = 1100;
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
		
		if (isDead == false && (posX >= 800 && posX <= 900 + 1000 ))
		{
			hdcMem = CreateCompatibleDC(hdc);
			oldBitmap = SelectObject(hdcMem, hbmMask);
			GetObject(hbmMask, sizeof(bitmap), &bitmap);
			BitBlt
			(
				hdc,
				posX,
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
				posX,
				posY,
				ENEMY_WIDTH,
				ENEMY_HEIGHT,
				hdcMem,
				ENEMY_WIDTH * enemyForm,
				0,
				SRCPAINT
			);
			if (enemyForm == 0)
				enemyForm = 1;
			else
				enemyForm = 0;
			SelectObject(hdcMem, oldBitmap);
			DeleteDC(hdcMem);
		}

		
		
	}

};