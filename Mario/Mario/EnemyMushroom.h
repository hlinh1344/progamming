#pragma once
#include "BaseObject.h"
#include <ctime>
#include <chrono>
#include <time.h>
#include <iomanip>
//44x43
#define ENEMY_HEIGHT 43
#define ENEMY_WIDTH 44

class EnemyMushroom : public BaseObject
{
private:
	int enemyForm;
	time_t currentTime = time(NULL);   // get time now
	tm now;
public:

	EnemyMushroom(int a_x, int a_y)
	{
		posX = a_x;
		posY = a_y;
		enemyForm = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
		localtime_s(&now, &currentTime);
	}

	EnemyMushroom()
	{
		posX = 2200;
		posY = 422;
		enemyForm  = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
		localtime_s(&now, &currentTime);
	}
	~EnemyMushroom()
	{

	}

	void draw(HWND hwnd, HDC hdc) override 
	{
		//time_t currentTime2 = time(NULL);   // get time now
		//tm now2;
		//localtime_s(&now2, &currentTime2);
		//double  diff = (-1) * (double)difftime(currentTime, mktime(&now2));

		//if (diff >= 0.5)
		//{
		//	if (enemyForm == 1)
		//		enemyForm = 0;
		//	else
		//		enemyForm = 1;
		//	currentTime = currentTime2;
		//	localtime_s(&now, &currentTime);
		//}

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
					posX,
					posY,
					ENEMY_WIDTH,
					ENEMY_HEIGHT,
					hdcMem,
					ENEMY_WIDTH * enemyForm,
					0,
					SRCPAINT
				);
			SelectObject(hdcMem, oldBitmap);
			DeleteDC(hdcMem);
		}		
	}
};