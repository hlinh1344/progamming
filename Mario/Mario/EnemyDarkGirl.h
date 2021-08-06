#pragma once
#include "Enemy.h"


#define DARK_GIRL_HEIGHT 65
#define DARK_GIRL_WIDTH 70
#define DARK_GIRL_AREA 350
#define DARK_GIRL_SPEED 7

//chang name
class EnemyDarkGirl : public Enemy
{
private:
	bool isFalling;
public:
	EnemyDarkGirl(int a_x)
	{
		width = DARK_GIRL_WIDTH;
		height = DARK_GIRL_HEIGHT;
		speed = DARK_GIRL_SPEED;
		posX = a_x;
		posY = 50;
		formX = 3;
		originalLocation = a_x;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));

	}

	EnemyDarkGirl()
	{
		width = DARK_GIRL_WIDTH;
		height = DARK_GIRL_HEIGHT;
		speed = DARK_GIRL_SPEED;
		posX = 0;
		posY = 50;
		formX = 4;
		originalLocation = 0;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~EnemyDarkGirl()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <= 2))
			return true;
		return false;
	}

	bool IsGoRight() override
	{
		if ((formX >= 3) && (formX <= 5))
			return true;
		return false;
	}
	void SetDeath(bool a_isDead) override
	{
		isDead = a_isDead;
	}




	void MakeAnimation() override
	{
		clock++;
		if (isFalling)
		{
			posY = posY + speed;
			//formX--;
			if (clock >= 3)
			{
				clock = 0;
				if (formX <= 0)
					formX = 2;
				else
					formX--;
			}


			if (posY >= 20 + DARK_GIRL_AREA)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY - speed;

			//formX++;
			if (clock >= 3)
			{
				clock = 0;
				if (formX >= 5)
					formX = 3;
				else
					formX++;
			}


			if (posY <= 20)
			{
				isFalling = true;
			}
		}
	}

};