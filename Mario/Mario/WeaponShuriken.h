#pragma once
#include "Weapon.h"

#define SHURIKEN_HEIGHT 40
#define SHURIKEN_WIDTH 45
#define SHURIKEN_AREA 300
#define SHURIKEN_SPEED 10

//L = 0, R = 1;

class WeaponShuriken : public Weapon
{
private:
	int xOriginal;
public:
	WeaponShuriken(int a_x, int a_dir, int	a_posY)
	{
		width = SHURIKEN_WIDTH;
		height = SHURIKEN_HEIGHT;
		xArea = SHURIKEN_AREA;
		speed = SHURIKEN_SPEED;
		posX = a_x;
		posY = a_posY;
		if (a_dir == 0)
		{
			formX = 3;
		}
		else if (a_dir == 1)
		{
			formX = 4;
		}
		dir = a_dir;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Shuriken.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	WeaponShuriken()
	{
		width = SHURIKEN_WIDTH;
		height = SHURIKEN_HEIGHT;
		xArea = SHURIKEN_AREA;
		speed = SHURIKEN_SPEED;
		posX = 0;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Shuriken.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~WeaponShuriken()
	{

	}

	void MakeAnimation() override
	{
		posY = posY + 2;
		if (dir == 0)
		{
			MoveLeft();
			if (formX <= 0)
			{
				formX = 2;
			}
			else
				formX--;
		}
		else if (dir == 1)
		{
			MoveRight();
			if (formX >= 5)
			{
				formX = 3;
			}
			else
				formX++;
		}
		CheckDistance(xOriginal);
	}

};