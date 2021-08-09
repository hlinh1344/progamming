#pragma once
#include "Weapon.h"

#define THUNDER_HEIGHT 58
#define THUNDER_WIDTH 78
#define THUNDER_AREA 800
#define THUNDER_SPEED 15

//L = 0, R = 1;

class WeaponThunder : public Weapon
{
private:
	bool isFalling;
public:
	WeaponThunder(int a_x, int a_dir, int	a_posY)
	{
		width = THUNDER_WIDTH;
		height = THUNDER_HEIGHT;
		xArea = THUNDER_AREA;
		speed = THUNDER_SPEED;
		posX = a_x;

		posY = a_posY;
		if (a_dir == 0)
		{
			formX = 8;
		}
		else if (a_dir == 1)
		{
			formX = 9;
		}
		dir = a_dir;
		isFalling = true;
		xOriginal = posX;
		yOriginal = posY;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Thunder.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 128, 0));
	}

	WeaponThunder()
	{
		width = THUNDER_WIDTH;
		height = THUNDER_HEIGHT;
		xArea = THUNDER_AREA;
		speed = THUNDER_SPEED;
		posX = 0;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Thunder.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 128, 0));
	}
	~WeaponThunder()
	{

	}


	void MakeAnimation() override
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
		else if (dir == 1)
		{
			MoveRight();
			if (formX >= 17)
			{
				formX = 9;
			}
			else
				formX++;
		}

		if (isFalling)
		{
			posY = posY + 5;
			if (posY >= yOriginal + 70)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - 5;
			if (posY <= yOriginal - 70)
			{
				isFalling = true;
			}
		}
		CheckDistance(xOriginal);
	}

};