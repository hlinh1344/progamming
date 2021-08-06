#pragma once
#include "Enemy.h"
#include "Map.h"

#define DARK_DRAGON_HEIGHT 108
#define DARK_DRAGON_WIDTH 120
#define DARK_DRAGON_AREA 1200
#define DARK_DRAGON_SPEED 5

class EnemyDarkDragon : public Enemy
{
private:

public:
	EnemyDarkDragon(int a_x)
	{
		width = DARK_DRAGON_WIDTH;
		height = DARK_DRAGON_HEIGHT;
		speed = DARK_DRAGON_SPEED;
		posX = a_x;
		posY = 357;
		formX = 3;
		originalLocation = a_x;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkDragon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));

	}

	EnemyDarkDragon()
	{
		width = DARK_DRAGON_WIDTH;
		height = DARK_DRAGON_HEIGHT;
		speed = DARK_DRAGON_SPEED;
		posX = 0;
		posY = 357;
		formX = 3;
		originalLocation = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"DarkDragon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~EnemyDarkDragon()
	{

	}

	bool IsGoLeft() override
	{
		if ((formX >= 0) && (formX <=3))
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
		if (EnemyDarkDragon::IsGoRight())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX >= 7)
					formX = 4;
				else
					formX = formX + 1;
			}


			EnemyDarkDragon::MoveRight();

			if (posX >= originalLocation + DARK_DRAGON_AREA)
			{
				formX = 3;
			}
		}

		else if (EnemyDarkDragon::IsGoLeft())
		{
			if (clock >= 10)
			{
				clock = 0;
				if (formX <= 0)
					formX = 3;
				else
					formX = formX - 1;
			}


			EnemyDarkDragon::MoveLeft();

			if (posX <= originalLocation)
			{
				formX = 4;
			}
		}
	}


};