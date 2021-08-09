#pragma once
#include "Enemy.h"


#define SLIME_HEIGHT 120
#define SLIME_WIDTH 115
#define SLIME_AREA 1200
#define SLIME_SPEED 3

class EnemySlime : public Enemy
{
private:

public:
	EnemySlime(int a_x)
	{
		width = SLIME_WIDTH;
		height = SLIME_HEIGHT;
		speed = SLIME_SPEED;
		xArea = SLIME_AREA;
		posX = a_x;
		posY = 353;
		formX = 9;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Slime.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 0));
		value = 4;
	}

	EnemySlime()
	{
		width = SLIME_WIDTH;
		height = SLIME_HEIGHT;
		speed = SLIME_SPEED;
		xArea = SLIME_AREA;
		posX = 0;
		posY = 353;
		formX = 9;
		xOriginal = posX;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Slime.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 0));
		value = 4;
	}

	~EnemySlime()
	{

	}
	
	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <= 8))
			return true;
		return false;
	}

	bool IsGoRight() override
	{
		if ((formX >= 9) && (formX <= 17))
			return true;
		return false;
	}

	void MakeAnimation() override
	{
		clock++;
		if (EnemySlime::IsGoRight())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX >= 17)
					formX = 9;
				else
					formX = formX + 1;
			}


			EnemySlime::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				formX = 8;
			}
		}

		else if (EnemySlime::IsGoLeft())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX <= 0)
					formX = 8;
				else
					formX = formX - 1;
			}


			EnemySlime::MoveLeft();

			if (posX <= xOriginal)
			{
				formX = 9;
			}
		}
	}

};