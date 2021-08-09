#pragma once
#include "BaseObject.h"


#define MENU_HEIGHT 536
#define MENU_WIDTH 990
#define SELECTION_HEIGHT 148
#define SELECTION_WIDTH 347
#define SONG_NAME_HEIGHT 41
#define SONG_NAME_WIDTH 290


class Menu : public BaseObject
{
private:
	HBITMAP hBitmap_Menu, hBitmap_Song, hBitmap_SongMask;
	int songID;
	int formMenu;
	int songPosX;
	bool changeDirection;
public:

	Menu()
	{
		changeDirection = false;
		songPosX = 10;
		songID = 0;
		posX = 45;
		posY = 150;
		formX = 0;
		formY = 0;
		formMenu = 0;
		hBitmap_Menu = (HBITMAP)LoadImage(hInst, L"Menu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap_Song = (HBITMAP)LoadImage(hInst, L"SongList.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hBitmap = (HBITMAP)LoadImage(hInst, L"Selection.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
		hBitmap_SongMask = CreateBitmapMask(hBitmap_Song, RGB(0, 0, 0));
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


	void Draw(HWND hwnd, HDC hdc) override
	{
		hdcMem = CreateCompatibleDC(hdc);
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
		
		//--------
		oldBitmap = SelectObject(hdcMem, hBitmap_SongMask);
		GetObject(hBitmap_SongMask, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			songPosX ,
			10,
			SONG_NAME_WIDTH,
			SONG_NAME_HEIGHT,
			hdcMem,
			SONG_NAME_WIDTH * formMenu,
			SONG_NAME_HEIGHT * (songID - 1),
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap_Song);
		GetObject(hBitmap_Song, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			songPosX,
			10,
			SONG_NAME_WIDTH,
			SONG_NAME_HEIGHT,
			hdcMem,
			SONG_NAME_WIDTH * formMenu,
			SONG_NAME_HEIGHT * (songID - 1),
			SRCPAINT
		);

		if (changeDirection == false)
		{
			songPosX = songPosX + 3;
			if (songPosX >= 600)
				changeDirection = true;
		}
		else
		{
			songPosX = songPosX - 3;
			if (songPosX <= 10)
				changeDirection = false;
		}



		if (formX >= 3)
		{
			formX = 0;
		}
		else
			formX++;
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
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
			if (songID >= 7)
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