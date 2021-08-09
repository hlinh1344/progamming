#pragma once
#include "Enemy.h"

#define WHITE_GHOST_HEIGHT 100
#define WHITE_GHOST_WIDTH 100
#define WHITE_GHOST_AREA 850
#define WHITE_GHOST_SPEED 4
#define WHITE_GHOST_FLY_AREA 300

class EnemyWhiteGhost : public Enemy
{
private:
	bool isFalling;
public:
	EnemyWhiteGhost(int a_x)
	{
		width = WHITE_GHOST_WIDTH;
		height = WHITE_GHOST_HEIGHT;
		speed = WHITE_GHOST_SPEED;
		xArea = WHITE_GHOST_AREA;
		yArea = WHITE_GHOST_FLY_AREA;
		posX = a_x;
		posY = 100;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"WhiteGhost.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 5;
	}

	EnemyWhiteGhost()
	{
		width = WHITE_GHOST_WIDTH;
		height = WHITE_GHOST_HEIGHT;
		speed = WHITE_GHOST_SPEED;
		xArea = WHITE_GHOST_AREA;
		yArea = WHITE_GHOST_FLY_AREA;
		posX = 0;
		posY = 200;
		formX = 6;
		xOriginal = posX;
		yOriginal = posY;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"WhiteGhost.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		value = 5;
	}

	~EnemyWhiteGhost()
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
		if (EnemyWhiteGhost::IsGoRight())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX >= 11)
					formX = 6;
				else
					formX = formX + 1;
			}


			EnemyWhiteGhost::MoveRight();

			if (posX >= xOriginal + xArea)
			{
				formX = 5;
			}
		}

		else if (EnemyWhiteGhost::IsGoLeft())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX <= 0)
					formX = 5;
				else
					formX = formX - 1;
			}


			EnemyWhiteGhost::MoveLeft();

			if (posX <= xOriginal)
			{
				formX = 6;
			}
		}

		//----
		if (isFalling)
		{
			posY = posY +2;
			if (posY >= yOriginal + yArea)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - 2;
			if (posY <= yOriginal)
			{
				isFalling = true;
			}
		}
	}

};