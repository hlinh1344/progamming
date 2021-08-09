#pragma once
#include "Enemy.h"


#define DARK_GIRL_HEIGHT 65
#define DARK_GIRL_WIDTH 70
#define DARK_GIRL_FLY_AREA 350
#define DARK_GIRL_SPEED 7

//chang name
class EnemyDarkGirl : public Enemy
{
private:
	bool isFalling;
public:
	EnemyDarkGirl(int a_x)
	{
		width = DARK_GIRL_WIDTH;
		height = DARK_GIRL_HEIGHT;
		speed = DARK_GIRL_SPEED;
		yArea = DARK_GIRL_FLY_AREA;
		posX = a_x;
		posY = 20;
		formX = 3;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 7;
	}

	EnemyDarkGirl()
	{
		width = DARK_GIRL_WIDTH;
		height = DARK_GIRL_HEIGHT;
		speed = DARK_GIRL_SPEED;
		yArea = DARK_GIRL_FLY_AREA;
		posX = 0;
		posY = 20;
		formX = 4;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 7;
	}

	~EnemyDarkGirl()
	{

	}

	void MakeAnimation() override
	{
		clock++;
		if (isFalling)
		{
			posY = posY + speed;
			//formX--;
			if (clock >= 3)
			{
				clock = 0;
				if (formX <= 0)
					formX = 2;
				else
					formX--;
			}


			if (posY >= yOriginal + yArea)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - speed;

			//formX++;
			if (clock >= 3)
			{
				clock = 0;
				if (formX >= 5)
					formX = 3;
				else
					formX++;
			}


			if (posY <= yOriginal)
			{
				isFalling = true;
			}
		}
	}

};