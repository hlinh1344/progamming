#pragma once
#include "Weapon.h"
#include "Map.h"

//45x44
#define BLUE_SWORD_HEIGHT 29
#define BLUE_SWORD_WIDTH 151
#define BLUE_SWORD_AREA 0
#define BLUE_SWORD_SPEED 0

//posx = 100;
//posY = 421;

class WeaponBlueSword : public Weapon
{
private:
	int xOriginal;
public:
	WeaponBlueSword(int a_x, int a_dir, int	a_posY)
	{
		width = BLUE_SWORD_WIDTH;
		height = BLUE_SWORD_HEIGHT;
		xArea = BLUE_SWORD_AREA;
		speed = BLUE_SWORD_SPEED;
		posX = a_x;
		posY = a_posY;
		formX = a_dir;
		dir = a_dir;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BlueSword.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	WeaponBlueSword()
	{
		width = BLUE_SWORD_WIDTH;
		height = BLUE_SWORD_HEIGHT;
		xArea = BLUE_SWORD_AREA;
		speed = BLUE_SWORD_SPEED;
		posX = 0;
		posY = 421;
		formX = 1;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BlueSword.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~WeaponBlueSword()
	{

	}



	bool IsGoLeft() override
	{
		if (formX == 0)
			return true;
		return false;
	}

	bool IsGoRight()override
	{
		if (formX == 1)
			return true;
		return false;
	}

};