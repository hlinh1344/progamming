#pragma once
#include "LiveObject.h"


#define PET_HEIGHT 48
#define PET_WIDTH 40


//chang name
class Pet : public LiveObject
{
private:
	bool isFalling;
	int count;
	int dir;
	int distance;
	int clock2;
	bool attack;
	//L = 0; R = 1
public:
	Pet(int a_x)
	{
		attack = false;
		clock2 = 0;
		width = PET_WIDTH;
		height = PET_HEIGHT;
		posX = a_x;
		posY = 290;
		formX = 12;
		isFalling = true;
		distance = 20;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Pet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	Pet()
	{
		attack = false;
		clock2 = 0;
		width = PET_WIDTH;
		height = PET_HEIGHT;
		posX = 20;
		posY = 290;
		formX = 12;
		isFalling = true;
		distance = 20;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Pet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	~Pet()
	{

	}

	void MakeAnimation(int a_posX, int a_posY, int a_dir)
	{
		clock++;
		posY = a_posY - 50;
		dir = a_dir;
		if (abs(posX - a_posX) >= distance)
		{
			if ((dir == 1) && (posX< a_posX))
			{
				posX = posX + 5;
			}
			else if ((dir == 0) && (posX > (a_posX + 105)))
			{
				posX = posX - 5;
			}
		}
		
	
		if (clock >= 8)
		{
			clock = 0;
			clock2++;
			if (dir == 1)
			{
				if (clock2 >= 79)
				{
					clock2 = 0;
					formX = 16;
				}
				else if ((formX == 15) || (formX == 23))
				{
					formX = 12;
				}
				else
				{
					formX++;
				}
			}
			else if (dir == 0)
			{
				if ((formX == 8) || (formX == 0))
				{
					formX = 11;
				}
				else
				{
					formX--;
				}
			}
			if (formX == 22)
			{
				attack = true;
			}
		}
	}

	bool CheckToAttack()
	{
		if ((formX == 23) && (attack == true))
		{
			attack = false;
			return true;
		}
		return false;
	}

	

};