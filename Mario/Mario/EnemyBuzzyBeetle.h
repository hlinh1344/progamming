#pragma once
#include "BaseObject.h"
#include "Map.h"
//45x44
#define BUZZY_HEIGHT 45
#define BUZZY_WIDTH 44
#define BUZZY_AREA 300
#define BUZZY_SPEED 3
//posx = 100;
//posY = 421;

class EnemyBuzzyBeetle : public BaseObject
{
private:
	int originalLocation;
public:
	EnemyBuzzyBeetle(int a_x)
	{
		posX = a_x;
		posY = 421;
		formX = 3;
		formY = 0;
		originalLocation = a_x;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemyBuzzyBeetle()
	{
		posX = 0;
		posY = 421;
		formX = 3;
		formY = 0;
		originalLocation = 0;
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
			BUZZY_WIDTH * formX,
			BUZZY_HEIGHT * formY,
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
			BUZZY_WIDTH * formX,
			BUZZY_HEIGHT * formY,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

	void moveLeft() override
	{
		posX = posX - BUZZY_SPEED;
	}

	void moveRight() override
	{
		posX = posX + BUZZY_SPEED;
	}

	bool isGoLeft() override
	{
		if ((formX == 0) && (formX == 1))
			return true;
		return false;
	}

	bool isGoRight( )override
	{
		if ((formX == 3) && (formX == 4))
			return true;
		return false;
	}

	void makeAnimation() override
	{
		if (!isDead)
		{
			if (EnemyBuzzyBeetle::isGoRight())
			{
				if (formX == 3)
					formX = 4;
				else
					formX = 3;

				EnemyBuzzyBeetle::moveRight();

				if (posX >= originalLocation + BUZZY_AREA)
				{
					//EnemyBuzzyBeetle::moveLeft();
					formX = 1;
				}
			}

			else if (EnemyBuzzyBeetle::isGoLeft())
			{
				if (formX == 0)
					formX = 1;
				else
					formX = 0;

				EnemyBuzzyBeetle::moveLeft();

				if (posX <= originalLocation)
				{
					//EnemyBuzzyBeetle::moveRight();
					formX = 3;
				}
			}

			
			//if (posX <= originalLocation)
			//{
			//	EnemyBuzzyBeetle::moveRight();
			//	formX = 3;
			//}
			//else if (posX >= originalLocation + BUZZY_AREA)
			//{
			//	EnemyBuzzyBeetle::moveLeft();
			//	formX = 1;
			//}
		}
	}

};