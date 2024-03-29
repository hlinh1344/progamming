#pragma once
#include "Enemy.h"


#define BIRD_HEIGHT 65
#define BIRD_WIDTH 64
#define BIRD_AREA 1000
#define BIRD_SPEED 3
#define BIRD_FLY_AREA 150


class EnemyBird : public Enemy
{
private:
	bool isFalling;
public:
	EnemyBird(int a_x)
	{
		width = BIRD_WIDTH;
		height = BIRD_HEIGHT;
		speed = BIRD_SPEED;
		xArea = BIRD_AREA;
		yArea = BIRD_FLY_AREA;
		posX = a_x;
		posY = 150;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Bird.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 6;
	}

	EnemyBird()
	{
		width = BIRD_WIDTH;
		height = BIRD_HEIGHT;
		speed = BIRD_SPEED;
		xArea = BIRD_AREA;
		yArea = BIRD_FLY_AREA;
		posX = 0;
		posY = 150;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Bird.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 6;
	}

	~EnemyBird()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <= 3))
			return true;
		return false;
	}

	bool IsGoRight() override
	{
		if ((formX >= 4) && (formX <= 7))
			return true;
		return false;
	}

	void MakeAnimation() override
	{
		clock++;
		if (EnemyBird::IsGoRight())
		{
			if (clock >= 13)
			{
				clock = 0;
				if (formX >= 7)
					formX = 4;
				else
					formX = formX + 1;
			}


			EnemyBird::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				formX = 3;
			}
		}

		else if (EnemyBird::IsGoLeft())
		{
			if (clock >= 13)
			{
				clock = 0;
				if (formX <= 0)
					formX = 3;
				else
					formX = formX - 1;
			}

			EnemyBird::MoveLeft();

			if (posX <= xOriginal)
			{
				formX = 4;
			}
		}


		//----------------
		if (isFalling)
		{
			posY = posY++;
			if (posY >= yOriginal + yArea)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY--;
			if (posY <= yOriginal)
			{
				isFalling = true;
			}
		}

	}

};