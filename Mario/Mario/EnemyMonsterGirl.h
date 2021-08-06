#pragma once
#include "Enemy.h"

#define MONSTER_GIRL_HEIGHT 65
#define MONSTER_GIRL_WIDTH 70
#define MONSTER_GIRL_AREA 1200
#define MONSTER_GIRL_SPEED 8


class EnemyMonsterGirl : public Enemy
{
private:
	bool isFalling;
public:
	EnemyMonsterGirl(int a_x)
	{
		width = MONSTER_GIRL_WIDTH;
		height = MONSTER_GIRL_HEIGHT;
		speed = MONSTER_GIRL_SPEED;
		posX = a_x;
		posY = 50;
		//CHANGE FORM
		formX = 4;
		originalLocation = a_x;;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"MonsterGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));

	}

	EnemyMonsterGirl()
	{
		width = MONSTER_GIRL_WIDTH;
		height = MONSTER_GIRL_HEIGHT;
		speed = MONSTER_GIRL_SPEED;
		posX = 0;
		posY = 50;
		//CHANGE FORM
		formX = 4;
		originalLocation = 0;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"MonsterGirl.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~EnemyMonsterGirl()
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

	void MakeAnimation() override
	{
		clock++;
		if (EnemyMonsterGirl::IsGoRight())
		{
			if (clock >= 16)
			{
				clock = 0;
				if (formX >= 5)
					formX = 3;
				else
					formX = formX + 1;
			}


			EnemyMonsterGirl::MoveRight();

			if (posX >= originalLocation + MONSTER_GIRL_AREA)
			{
				formX = 2;
			}
		}

		else if (EnemyMonsterGirl::IsGoLeft())
		{
			if (clock >= 16)
			{
				clock = 0;
				if (formX <= 0)
					formX = 2;
				else
					formX = formX - 1;
			}


			EnemyMonsterGirl::MoveLeft();

			if (posX <= originalLocation)
			{
				formX = 4;
			}
		}


		if (isFalling)
		{
			posY = posY +2;
			if (posY >= 300)
			{
				isFalling = false;
			}
		}
		else if (!isFalling)
		{
			posY = posY -2;
			if (posY <= 50)
			{
				isFalling = true;
			}
		}
	}
};