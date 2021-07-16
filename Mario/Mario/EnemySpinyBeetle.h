#pragma once
#include "Map.h"
#include "BaseObject.h"
//42x42
#define SPINY_HEIGHT 42
#define SPINY_WIDTH 42
#define SPINY_AREA 100
#define SPINY_SPEED 3
//posx= 300
//posY = 422
class EnemySpinyBeetle : public BaseObject
{
private:
	int originalLocation;
public:

	EnemySpinyBeetle(int a_x)
	{
		posX = a_x;
		posY = 422;
		formX = 2;
		formY = 0;
		originalLocation = a_x;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemySpinyBeetle()
	{
		posX = 0;
		posY = 422;
		formX = 2;
		formY = 0;
		originalLocation = 0;
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
			posX - BaseObject::mapSlider,
			posY,
			SPINY_WIDTH,
			SPINY_HEIGHT,
			hdcMem,
			SPINY_WIDTH * formX,
			SPINY_HEIGHT * formY,
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX - BaseObject::mapSlider,
			posY,
			SPINY_WIDTH,
			SPINY_HEIGHT,
			hdcMem,
			SPINY_WIDTH * formX,
			SPINY_HEIGHT * formY,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

	void moveLeft() override
	{
		posX = posX - SPINY_SPEED;
	}

	void moveRight() override
	{
		posX = posX + SPINY_SPEED;
	}

	bool isGoLeft() override
	{
		if ((formX == 0) || (formX == 1))
			return true;
		return false;
	}

	bool isGoRight()override
	{
		if ((formX == 2) || (formX == 3))
			return true;
		return false;
	}

	void makeAnimation() override
	{
		if (!isDead)
		{
			if (EnemySpinyBeetle::isGoRight())
			{
				if (formX >= 3)
					formX = 2;
				else
					formX = formX + 1;

				EnemySpinyBeetle::moveRight();

				if (posX >= originalLocation + SPINY_AREA)
				{
					formX = 1;
				}
			}
			else if (EnemySpinyBeetle::isGoLeft())
			{
				if (formX <= 0)
					formX = 1;
				else
					formX = formX - 1;

				EnemySpinyBeetle::moveLeft();

				if (posX <= originalLocation)
				{
					formX = 2;
				}
			}
		}
	}
};