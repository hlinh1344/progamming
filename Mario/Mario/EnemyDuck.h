#pragma once
#include "BaseObject.h"
#include "Map.h"
//60x45
#define DUCK_HEIGHT 60
#define DUCK_WIDTH 45
#define DUCK_AREA 150
#define DUCK_SPEED 2.5
//pos x = 200
//pos y = 406

class EnemyDuck : public BaseObject
{
private:
	int originalLocation;
public:

	EnemyDuck(int a_x)
	{
		posX = a_x;
		posY = 406;
		formX = 4;
		formY = 0;
		originalLocation = a_x;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}

	EnemyDuck()
	{
		posX = 0;
		posY = 406;
		formX = 4;
		formY = 0;
		originalLocation = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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
			posX - BaseObject::mapSlider,
			posY,
			DUCK_WIDTH,
			DUCK_HEIGHT,
			hdcMem,
			DUCK_WIDTH * formX,
			DUCK_HEIGHT * formY,
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX - BaseObject::mapSlider,
			posY,
			DUCK_WIDTH,
			DUCK_HEIGHT,
			hdcMem,
			DUCK_WIDTH * formX,
			DUCK_HEIGHT * formY,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

	void moveLeft() override
	{
		posX = posX - DUCK_SPEED;
	}

	void moveRight() override
	{
		posX = posX + DUCK_SPEED;
	}

	bool isGoLeft() override
	{
		if ((formX >= 0) && (formX <= 3))
			return true;
		return false;
	}

	bool isGoRight()override
	{
		if ((formX >= 4) && (formX <= 7))
			return true;
		return false;
	}

	void makeAnimation() override
	{
		if (!isDead)
		{
			if (EnemyDuck::isGoRight())
			{
				if (formX >= 7)
					formX = 4;
				else
					formX = formX + 1;

				EnemyDuck::moveRight();

				if (posX >= originalLocation + DUCK_AREA)
				{
					formX = 3;
				}
			}
			else if (EnemyDuck::isGoLeft())
			{
				if (formX <= 0)
					formX = 3;
				else
					formX = formX - 1;

				EnemyDuck::moveLeft();

				if (posX <= originalLocation)
				{
					formX = 4;
				}
			}
		}
	}

};