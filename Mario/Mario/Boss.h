#pragma once
#include "Enemy.h"


#define BOSS_HEIGHT 125
#define BOSS_WIDTH 115
#define BOSS_FLY_AREA 350
#define BOSS_SPEED 5

//chang name
class Boss : public Enemy
{
private:
	bool isFalling;
	int count;
	int life;
public:
	Boss(int a_x)
	{
		width = BOSS_WIDTH;
		height = BOSS_HEIGHT;
		speed = BOSS_SPEED;
		yArea = BOSS_FLY_AREA;
		posX = a_x;
		posY = 10;
		formX = 3;
		xOriginal = posX;
		yOriginal = posY;
		life = 20;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Boss.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	Boss()
	{
		width = BOSS_WIDTH;
		height = BOSS_HEIGHT;
		speed = BOSS_SPEED;
		yArea = BOSS_FLY_AREA;
		posX = 800;
		posY = 50;
		formX = 3;
		xOriginal = posX;
		yOriginal = posY;
		life = 20;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Boss.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	~Boss()
	{

	}

	void MakeAnimation() override
	{
		clock++;
		if (isFalling)
		{
			posY = posY + speed;

			if (clock >= 5)
			{
				clock = 0;
				if (formX <= 0)
					formX = 3;
				else
					formX--;
			}


			if (posY >= yOriginal + yArea)
			{
				isFalling = false;
				formY = 1;
			}
		}
		else if (!isFalling)
		{
			posY = posY - speed;
			if (clock >= 5)
			{
				clock = 0;
				if (formX <= 0)
					formX = 3;
				else
					formX--;
			}

			if (posY <= yOriginal)
			{
				isFalling = true;
				formY = 0;
			}

		}
	}

	void SetDeath(bool a_isDead) override
	{
		life--;
		if (life < 0)
		{
			isDead = true;
		}
	}

	bool CheckToAttack()
	{
		count++;
		if ((formX == 0) && (formY == 1) && count >= 5)
		{
			count = 0;
			return true;
		}
			
		return false;
	}

};