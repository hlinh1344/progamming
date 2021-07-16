#pragma once
#include <ctime>
#include <chrono>
#include <time.h>
#include <iomanip>
#include "BaseObject.h"
#include "Map.h"

//44x43
#define MUSHROOM_HEIGHT 43
#define MUSHROOM_WIDTH 44
#define MUSHROOM_AREA 120
#define MUSHROOM_SPEED 2
class EnemyMushroom : public BaseObject
{
private:
	int originalLocation;
	bool isGoToRight;
public:

	EnemyMushroom(int a_x)
	{
		posX = a_x;
		posY = 422;
		formX = 0;
		formY = 0;
		originalLocation = a_x;
		isGoToRight = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"mario_e1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}

	EnemyMushroom()
	{
		posX = 1000;
		posY = 422;
		formX = 0;
		formY = 0;
		originalLocation = 1000;
		isGoToRight = true;
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
					posX - BaseObject::mapSlider,
					posY,
					MUSHROOM_WIDTH,
					MUSHROOM_HEIGHT,
					hdcMem,
					MUSHROOM_WIDTH * formX,
					MUSHROOM_HEIGHT * formY,
					SRCAND
				);
				oldBitmap = SelectObject(hdcMem, hBitmap);
				GetObject(hBitmap, sizeof(bitmap), &bitmap);
				BitBlt
				(
					hdc,
					posX - BaseObject::mapSlider,
					posY,
					MUSHROOM_WIDTH,
					MUSHROOM_HEIGHT,
					hdcMem,
					MUSHROOM_WIDTH * formX,
					MUSHROOM_HEIGHT * formY,
					SRCPAINT
				);
			SelectObject(hdcMem, oldBitmap);
			DeleteDC(hdcMem);
		}		
	}

	void moveLeft() override
	{
		posX = posX - MUSHROOM_SPEED;
	}

	void moveRight() override
	{
		posX = posX + MUSHROOM_SPEED;
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
			if (isGoToRight)
			{
				if (formX == 0)
					formX = 1;
				else
					formX = 0;

				EnemyMushroom::moveRight();

				if (posX >= originalLocation + MUSHROOM_AREA)
				{
					isGoToRight = false;
				}
			}
			else if (!isGoToRight)
			{
				if (formX == 0)
					formX = 1;
				else
					formX = 0;

				EnemyMushroom::moveLeft();

				if (posX <= originalLocation)
				{
					isGoToRight = true;
				}
			}

			
			//if (posX < originalLocation + MUSHROOM_AREA)
			//{
			//	EnemyMushroom::moveRight();
			//}

			//if (posX > originalLocation)
			//{
			//	EnemyMushroom::moveLeft();
			//}
		}
	}


};