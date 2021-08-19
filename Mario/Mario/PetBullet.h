#pragma once
#include "Weapon.h"


#define PET_BULLET_HEIGHT 50
#define PET_BULLET_WIDTH 40
#define PET_BULLET_AREA 600
#define PET_BULLET_SPEED 10

//L = 0, R = 1;

class PetBullet : public Weapon
{
private:
	int clock;
public:
	PetBullet(int a_posY)
	{
		clock = 0;
		width = PET_BULLET_WIDTH;
		height = PET_BULLET_HEIGHT;
		xArea = PET_BULLET_AREA;
		speed = PET_BULLET_SPEED;
		posX = 3500;
		posY = a_posY;
		formX = 0;
		dir = 0;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"PetBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	PetBullet(int a_posX, int a_posY)
	{
		width = PET_BULLET_WIDTH;
		height = PET_BULLET_HEIGHT;
		xArea = PET_BULLET_AREA;
		speed = PET_BULLET_SPEED;
		posX = a_posX;
		posY = a_posY;
		formX = 0;
		dir = 0;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"PetBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}
	PetBullet()
	{
		width = PET_BULLET_WIDTH;
		height = PET_BULLET_HEIGHT;
		xArea = PET_BULLET_AREA;
		speed = PET_BULLET_SPEED;
		posX = 200;
		posY = 421;
		formX = 0;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"PetBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}
	~PetBullet()
	{

	}


	void MakeAnimation()
	{
		clock++;
		posX++;
		if (clock >= 5)
		{
			clock = 0;
			if (formX == 3)
			{
				formX = 0;
			}
			else
			{
				formX++;
			}
			//--------
		}

		CheckDistance(xOriginal);
	}
};