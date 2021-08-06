#pragma once
#include "Item.h"

#define KUNAI_ITEM_HEIGHT 72
#define KUNAI_ITEM_WIDTH 74

//L = 0, R = 1;

class KunaiItem : public Item
{
private:;

public:


	KunaiItem()
	{
		width = KUNAI_ITEM_WIDTH;
		height = KUNAI_ITEM_HEIGHT;
		posX = 1600;
		typeOfWeapn = 2;
		hBitmap = (HBITMAP)LoadImage(hInst, L"KunaiItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 0));
	}

	KunaiItem(int a_x)
	{
		width = KUNAI_ITEM_WIDTH;
		height = KUNAI_ITEM_HEIGHT;
		posX = a_x;
		typeOfWeapn = 2;
		hBitmap = (HBITMAP)LoadImage(hInst, L"KunaiItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 0));
	}

	~KunaiItem()
	{

	}

};