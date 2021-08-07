#pragma once
#include "Weapon.h"

#define FIRE_HEIGHT 28
#define FIRE_WIDTH 70
#define FIRE_AREA 600
#define FIRE_SPEED 15

//L = 0, R = 1;

class WeaponFire : public Weapon
{
private:
	int xOriginal;
public:
	WeaponFire(int a_x, int a_dir, int	a_posY)
	{
		width = FIRE_WIDTH;
		height = FIRE_HEIGHT;
		xArea = FIRE_AREA;
		speed = FIRE_SPEED;
		posX = a_x;
		posY = a_posY;
		if (a_dir == 0)
		{
			formX = 6;
		}
		else if (a_dir == 1)
		{
			formX = 7;
		}

		dir = a_dir;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Fire.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 128, 0));
	}

	WeaponFire()
	{
		width = FIRE_WIDTH;
		height = FIRE_HEIGHT;
		xArea = FIRE_AREA;
		speed = FIRE_SPEED;
		posX = 0;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Fire.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB( 0, 128, 0));
	}
	~WeaponFire()
	{

	}

	void MakeAnimation() override
	{
		posY = posY - 3;
		if (dir == 0)
		{
			MoveLeft();
			if (formX <= 0)
			{
				formX = 6;
			}
			else
				formX--;
		}
		else if (dir == 1)
		{
			MoveRight();
			if (formX >= 13)
			{
				formX = 7;
			}
			else
				formX++;
		}
		CheckDistance(xOriginal);
	}

};