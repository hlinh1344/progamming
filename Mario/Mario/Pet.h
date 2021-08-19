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
public:
	Pet(int a_x)
	{
		width = PET_WIDTH;
		height = PET_HEIGHT;
		posX = a_x;
		posY = 290;
		formX = 0;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Pet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	Pet()
	{
		width = PET_WIDTH;
		height = PET_HEIGHT;
		posX = 300;
		posY = 290;
		formX = 0;
		isFalling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"Pet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
		count = 0;
	}

	~Pet()
	{

	}

	void MakeAnimation(int a_posX, int a_posY)
	{
		posX = a_posX - 10;
		posY = a_posY - 50;
		clock++;
		if (clock >= 10)
		{
			clock = 0;
			if ((formX == 3) || (formX == 11))
			{
				formX = 0;
			}
			else
			{
				formX++;
			}
			//--------
		}
	}

	bool CheckToAttack()
	{
		count++;
		if ((formY == 11) && count >= 10)
		{
			count = 0;
			return true;
		}
		return false;
	}

};