#pragma once
#include "Weapon.h"

//45x44
#define KUNAI_HEIGHT 17
#define KUNAI_WIDTH 80
#define KUNAI_AREA 350
#define KUNAI_SPEED 20

//posx = 100;
//posY = 421;

class WeaponKunai : public Weapon
{
private:
	int xOriginal;
public:
	WeaponKunai(int a_x, int a_dir, int	a_posY)
	{
		width = KUNAI_WIDTH;
		height = KUNAI_HEIGHT;
		xArea = KUNAI_AREA;
		speed = KUNAI_SPEED;
		posX = a_x;
		posY = a_posY;
		formX = a_dir;
		dir = a_dir;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Kunai.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	WeaponKunai()
	{
		width = KUNAI_WIDTH;
		height = KUNAI_HEIGHT;
		xArea = KUNAI_AREA;
		speed = KUNAI_SPEED;
		posX = 0;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Kunai.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~WeaponKunai()
	{

	}

	void MakeAnimation() override
	{
		if (dir == 0)
		{
			MoveLeft();
		}
		else if (dir == 1)
		{
			MoveRight();
		}
		CheckDistance(xOriginal);
	}

};