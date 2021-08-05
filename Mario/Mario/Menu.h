#pragma once
#include "BaseObject.h"
#include "Map.h"

#define MENU_HEIGHT 536
#define MENU_WIDTH 990
#define SELECTION_HEIGHT 148
#define SELECTION_WIDTH 347



class Menu : public BaseObject
{
private:
	HBITMAP hBitmap_Menu;
	int songID;
	int formMenu;
public:

	Menu()
	{
		songID = 0;
		posX = 45;
		posY = 150;
		formX = 0;
		formY = 0;
		formMenu = 0;
		hBitmap_Menu = (HBITMAP)LoadImage(hInst, L"Menu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

		hBitmap = (HBITMAP)LoadImage(hInst, L"Selection.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
	}

	~Menu()
	{

	}

	void Up()
	{
		if (posY == 150)
		{
			posY = 150 + (2 * SELECTION_HEIGHT);
			formY = 2;
		}
		else
		{
			posY = posY - SELECTION_HEIGHT;
			formY--;
		}

	}

	void Down()
	{
		if (posY == 150 + (2 * SELECTION_HEIGHT))
		{
			posY = 150;
			formY = 0;
		}
		else
		{
			posY = posY + SELECTION_HEIGHT;
			formY++;
		}
	}


	void Draw(HWND hwnd, HDC hdc, HDC hdcMem) override
	{
		//hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap_Menu);
		GetObject(hBitmap_Menu, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			0,
			0,
			MENU_WIDTH,
			MENU_HEIGHT,
			hdcMem,
			MENU_WIDTH * formMenu,
			0,
			SRCCOPY
		);
		if (formMenu == 0)
			formMenu = 1;
		else
			formMenu = 0;
		//------
		//Select
		oldBitmap = SelectObject(hdcMem, hbmMask);
		GetObject(hbmMask, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX,
			posY,
			SELECTION_WIDTH,
			SELECTION_HEIGHT,
			hdcMem,
			SELECTION_WIDTH * formX,
			SELECTION_HEIGHT * formY,
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX,
			posY,
			SELECTION_WIDTH,
			SELECTION_HEIGHT,
			hdcMem,
			SELECTION_WIDTH * formX,
			SELECTION_HEIGHT * formY,
			SRCPAINT
		);
		if (formX >= 3)
		{
			formX = 0;
		}
		else
			formX++;
		//SelectObject(hdcMem, oldBitmap);
		//DeleteDC(hdcMem);
	}

	int SelectOption(bool& inMenu)
	{
		if (posY == 150)
		{
			inMenu = false;
			return 99;
		}
		else if (posY == 150 + SELECTION_HEIGHT)
		{
			if (songID >= 6)
				songID = 0;
			else
				songID++;
			return songID;
		}
		else if (posY == 150 + SELECTION_HEIGHT + SELECTION_HEIGHT)
		{
			return -1;
		}
	}

};