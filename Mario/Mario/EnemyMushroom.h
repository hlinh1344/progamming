#pragma once

#include "Enemy.h"



#define MUSHROOM_HEIGHT 43
#define MUSHROOM_WIDTH 44
#define MUSHROOM_AREA 200
#define MUSHROOM_SPEED 1

class EnemyMushroom : public Enemy
{
private:
	bool isGoToRight;
public:

	EnemyMushroom(int a_x)
	{
		width = MUSHROOM_WIDTH;
		height = MUSHROOM_HEIGHT;
		speed = MUSHROOM_SPEED;
		xArea = MUSHROOM_AREA;
		posX = a_x;
		posY = 422;
		formX = 0;
		xOriginal = posX;
		isGoToRight = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Mushroom.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
		value = 3;
	}

	EnemyMushroom()
	{
		width = MUSHROOM_WIDTH;
		height = MUSHROOM_HEIGHT;
		speed = MUSHROOM_SPEED;
		xArea = MUSHROOM_AREA;
		posX = 0;
		posY = 422;
		formX = 0;
		xOriginal = posX;
		isGoToRight = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Mushroom.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
		value = 3;
	}
	~EnemyMushroom()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <= 3))
			return true;
		return false;
	}

	bool IsGoRight()override
	{
		if ((formX >= 4) && (formX <= 7))
			return true;
		return false;
	}


	void MakeAnimation() override
	{
		clock++;
		if (isGoToRight)
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX == 0)
					formX = 1;
				else
					formX = 0;
			}


			EnemyMushroom::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				isGoToRight = false;
			}
		}
		else if (!isGoToRight)
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX == 0)
					formX = 1;
				else
					formX = 0;
			}


			EnemyMushroom::MoveLeft();

			if (posX <= xOriginal)
			{
				isGoToRight = true;
			}
		}
		
	}

};