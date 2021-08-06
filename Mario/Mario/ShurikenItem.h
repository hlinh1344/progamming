#pragma once
#include "Item.h"

#define SHURIKEN_ITEM_HEIGHT 87
#define SHURIKEN_ITEM_WIDTH 98

//L = 0, R = 1;

class ShurikenItem : public Item
{
private:;

public:


	ShurikenItem()
	{
		width = SHURIKEN_ITEM_WIDTH;
		height = SHURIKEN_ITEM_HEIGHT;
		posX = 1600;
		typeOfWeapn = 1;
		hBitmap = (HBITMAP)LoadImage(hInst, L"ShurikenItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 0));
	}

	ShurikenItem(int a_x)
	{
		width = SHURIKEN_ITEM_WIDTH;
		height = SHURIKEN_ITEM_HEIGHT;
		posX = a_x;
		typeOfWeapn = 1;
		hBitmap = (HBITMAP)LoadImage(hInst, L"ShurikenItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 0));
	}

	~ShurikenItem()
	{

	}

};