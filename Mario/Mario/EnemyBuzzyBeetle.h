#pragma once
#include "Enemy.h"


#define BUZZY_HEIGHT 45
#define BUZZY_WIDTH 44
#define BUZZY_AREA 300
#define BUZZY_SPEED 2

class EnemyBuzzyBeetle : public Enemy
{
private:

public:
	EnemyBuzzyBeetle(int a_x)
	{
		width = BUZZY_WIDTH;
		height = BUZZY_HEIGHT;
		speed = BUZZY_SPEED;
		xArea = BUZZY_AREA;
		posX = a_x;
		posY = 421;
		formX = 3;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BuzzyBeetle.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));

	}

	EnemyBuzzyBeetle()
	{
		width = BUZZY_WIDTH;
		height = BUZZY_HEIGHT;
		speed = BUZZY_SPEED;
		xArea = BUZZY_AREA;
		posX = 0;
		posY = 421;
		formX = 3;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BuzzyBeetle.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}

	~EnemyBuzzyBeetle()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX == 0) || (formX == 1))
			return true;
		return false;
	}

	bool IsGoRight() override
	{
		if ((formX == 3) || (formX == 4))
			return true;
		return false;
	}

	void MakeAnimation() override
	{
		clock++;
		if (EnemyBuzzyBeetle::IsGoRight())
		{
			if (clock >= 20)
			{
				clock = 0;
				if (formX >= 4)
					formX = 3;
				else
					formX = formX + 1;
			}


			EnemyBuzzyBeetle::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				formX = 1;
			}
		}

		else if (EnemyBuzzyBeetle::IsGoLeft())
		{
			if (clock >= 20)
			{
				clock = 0;
				if (formX <= 0)
					formX = 1;
				else
					formX = formX - 1;
			}


			EnemyBuzzyBeetle::MoveLeft();

			if (posX <= xOriginal)
			{
				formX = 3;
			}
		}
	}

};