#pragma once
#include "Item.h"

#define BLUE_SWORD_ITEM_HEIGHT 177
#define BLUE_SWORD_ITEM_WIDTH 59

//L = 0, R = 1;

class BlueSwordItem : public Item
{
private:

public:
	
	BlueSwordItem()
	{
		
		width = BLUE_SWORD_ITEM_WIDTH;
		height = BLUE_SWORD_ITEM_HEIGHT;
		posX = 1100;
		typeOfWeapn = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BlueSwordItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	BlueSwordItem(int a_x)
	{
		width = BLUE_SWORD_ITEM_WIDTH;
		height = BLUE_SWORD_ITEM_HEIGHT;
		posX = a_x;
		typeOfWeapn = 0;
		hBitmap = (HBITMAP)LoadImage(hInst, L"BlueSwordItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	}

	~BlueSwordItem()
	{

	}
};