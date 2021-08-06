#pragma once
#include "Item.h"


#define THUNDER_DRAGON_ITEM_HEIGHT 195
#define THUNDER_DRAGON_ITEM_WIDTH 195

//L = 0, R = 1;

class ThunderDragonItem : public Item
{
private:;

public:


	ThunderDragonItem()
	{
		width = THUNDER_DRAGON_ITEM_WIDTH;
		height = THUNDER_DRAGON_ITEM_HEIGHT;
		posX = 1600;
		posY = 0;
		originalLocation = posY;
		typeOfWeapn = 4;
		hBitmap = (HBITMAP)LoadImage(hInst, L"ThunderDragonItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 128, 0));
	}

	ThunderDragonItem(int a_x)
	{
		width = THUNDER_DRAGON_ITEM_WIDTH;
		height = THUNDER_DRAGON_ITEM_HEIGHT;
		posX = a_x;
		posY = 0;
		originalLocation = posY;
		typeOfWeapn = 4;
		hBitmap = (HBITMAP)LoadImage(hInst, L"ThunderDragonItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(0, 128, 0));
	}

	~ThunderDragonItem()
	{

	}

};