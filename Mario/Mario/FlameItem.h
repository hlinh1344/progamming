#pragma once
#include "Item.h"

#define FLAME_ITEM_HEIGHT 144
#define FLAME_ITEM_WIDTH 60


//L = 0, R = 1;

class FlameItem : public Item
{
private:;
	   bool falling;
public:


	FlameItem()
	{
		width = FLAME_ITEM_WIDTH;
		height = FLAME_ITEM_HEIGHT;
		posX = 1600;
		posY = 0;
		typeOfWeapn = 3;
		falling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"FlameItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	FlameItem(int a_x)
	{
		width = FLAME_ITEM_WIDTH;
		height = FLAME_ITEM_HEIGHT;
		posX = a_x;
		posY = 0;
		typeOfWeapn = 3;
		falling = true;
		hBitmap = (HBITMAP)LoadImage(hInst, L"FlameItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~FlameItem()
	{

	}


	void MakeAnimation() override
	{
		clock++;
		if (clock >= 15)
		{
			clock = 0;
			if (formX == 6)
				formX = 0;
			else formX++;
		}
	}
};