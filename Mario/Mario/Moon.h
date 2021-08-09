#pragma once
#include "Weapon.h"


#define MOON_HEIGHT 81
#define MOON_WIDTH 82
#define MOON_AREA 500
#define MOON_SPEED 10

//L = 0, R = 1;

class Moon : public Weapon
{
private:
	bool isFalling;
public:
	Moon(int a_posY)
	{
		width = MOON_WIDTH;
		height = MOON_HEIGHT;
		xArea = MOON_AREA;
		speed = MOON_SPEED;
		posX = 3500;
		posY = a_posY;
		formX = 7;
		dir = 0;
		isFalling = true;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Moon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	Moon(int a_posX, int a_posY)
	{
		width = MOON_WIDTH;
		height = MOON_HEIGHT;
		xArea = MOON_AREA;
		speed = MOON_SPEED;
		posX = a_posX;
		posY = a_posY;
		formX = 7;
		dir = 0;
		isFalling = true;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Moon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}
	Moon()
	{
		width = MOON_WIDTH;
		height = MOON_HEIGHT;
		xArea = MOON_AREA;
		speed = MOON_SPEED;
		posX = 3600;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Moon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}
	~Moon()
	{

	}


	void MakeAnimation()
	{
		if (dir == 0)
		{
			MoveLeft();
			if (formX <= 0)
			{
				formX = 8;
			}
			else
				formX--;
		}

		if (isFalling)
		{
			posY = posY + 20;
			if (posY >= yOriginal + 70)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - 20;
			if (posY <= yOriginal - 70)
			{
				isFalling = true;
			}
		}
		CheckDistance(xOriginal);
	}
};