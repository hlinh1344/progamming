#pragma once

#include "Enemy.h"

#define SPINY_HEIGHT 42
#define SPINY_WIDTH 42
#define SPINY_AREA 290
#define SPINY_SPEED 2

class EnemySpinyBeetle : public Enemy
{
private:

public:

	EnemySpinyBeetle(int a_x)
	{
		width = SPINY_WIDTH;
		height = SPINY_HEIGHT;
		speed = SPINY_SPEED;
		posX = a_x;
		posY = 422;
		formX = 2;
		originalLocation = a_x;
		hBitmap = (HBITMAP)LoadImage(hInst, L"SpinyBeetle.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemySpinyBeetle()
	{
		width = SPINY_WIDTH;
		height = SPINY_HEIGHT;
		speed = SPINY_SPEED;
		posX = 0;
		posY = 422;
		formX = 2;
		originalLocation = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"SpinyBeetle.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}
	~EnemySpinyBeetle()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX == 0) || (formX == 1))
			return true;
		return false;
	}

	bool IsGoRight()override
	{
		if ((formX == 2) || (formX == 3))
			return true;
		return false;
	}


	void MakeAnimation() override
	{
		clock++;
		if (EnemySpinyBeetle::IsGoRight())
		{
			if (clock >= 18)
			{
				clock = 0;
				if (formX >= 3)
					formX = 2;
				else
					formX = formX + 1;
			}


			EnemySpinyBeetle::MoveRight();

			if (posX >= originalLocation + SPINY_AREA)
			{
				formX = 1;
			}
		}
		else if (EnemySpinyBeetle::IsGoLeft())
		{
			if (clock >= 18)
			{
				clock = 0;
				if (formX <= 0)
					formX = 1;
				else
					formX = formX - 1;
			}


			EnemySpinyBeetle::MoveLeft();

			if (posX <= originalLocation)
			{
				formX = 2;
			}
		}
	}

};