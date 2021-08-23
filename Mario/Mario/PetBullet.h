#pragma once
#include "Weapon.h"


#define PET_BULLET_HEIGHT 50
#define PET_BULLET_WIDTH 55
#define PET_BULLET_AREA 700
#define PET_BULLET_SPEED 15

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
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"PetBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	PetBullet(int a_posX, int a_posY)
	{
		clock = 0;
		width = PET_BULLET_WIDTH;
		height = PET_BULLET_HEIGHT;
		xArea = PET_BULLET_AREA;
		speed = PET_BULLET_SPEED;
		posX = a_posX;
		posY = a_posY;
		formX = 0;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"PetBullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 120, 104));
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
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 120, 104));
	}
	~PetBullet()
	{

	}


	void MakeAnimation() override
	{
		clock++;
		MoveRight();
		if (clock >= 2)
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
		}

		CheckDistance(xOriginal);
	}
};