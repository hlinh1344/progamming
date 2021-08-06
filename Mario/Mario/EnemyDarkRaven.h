#pragma once
#include "Enemy.h"

#define DARK_RAVEN_HEIGHT 55
#define DARK_RAVEN_WIDTH 45
#define DARK_RAVEN_AREA 1000
#define DARK_RAVEN_SPEED 5
#define DARK_RAVEN_FLY_AREA 200

class EnemyDarkRaven : public Enemy
{
private:
	bool isFalling;
public:
	EnemyDarkRaven(int a_x)
	{
		width =  DARK_RAVEN_WIDTH;
		height =  DARK_RAVEN_HEIGHT;
		speed =  DARK_RAVEN_SPEED;
		xArea =  DARK_RAVEN_AREA;
		yArea =  DARK_RAVEN_FLY_AREA;
		posX = a_x;
		posY = 50;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkRaven.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));

	}

	EnemyDarkRaven()
	{
		width = DARK_RAVEN_WIDTH;
		height = DARK_RAVEN_HEIGHT;
		speed = DARK_RAVEN_SPEED;
		xArea = DARK_RAVEN_AREA;
		yArea = DARK_RAVEN_FLY_AREA;
		posX = 0;
		posY = 50;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Girl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~EnemyDarkRaven()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <= 5))
			return true;
		return false;
	}

	bool IsGoRight() override
	{
		if ((formX >= 6) && (formX <= 11))
			return true;
		return false;
	}

	void MakeAnimation() override
	{
		clock++;
		if (EnemyDarkRaven::IsGoRight())
		{
			if (clock >= 8)
			{
				clock = 0;
				if (formX >= 11)
					formX = 6;
				else
					formX = formX + 1;
			}


			EnemyDarkRaven::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				formX = 5;
			}
		}

		else if (EnemyDarkRaven::IsGoLeft())
		{
			if (clock >= 8)
			{
				clock = 0;
				if (formX <= 0)
					formX = 5;
				else
					formX = formX - 1;
			}


			EnemyDarkRaven::MoveLeft();

			if (posX <= xOriginal)
			{
				formX = 6;
			}
		}
		//-----------
		if (isFalling)
		{
			posY = posY + 3;
			if (posY >= yOriginal + yArea)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - 3;
			if (posY <= yOriginal)
			{
				isFalling = true;
			}
		}
	}

};