#include "Map.h"

Map::Map()
{
	mapSlider = 0;
	clousDrifting = 0;
	posX = 0;
	posY = 0;
	hbmGround = (HBITMAP)LoadImage(hInst, L"mario_map.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmCloud = (HBITMAP)LoadImage(hInst, L"cloud.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}
Map::~Map()
{

}

void Map::increseMapSlider(int a)
{
	mapSlider += a;
}

void Map::increseClousDrifting(int a)
{
	clousDrifting += a;
}

int Map::getMapSlider()
{
	return mapSlider;
}

void Map::draw(HWND hwnd, HDC hdc)
{
	if (clousDrifting >= CLOUD_WIDTH - MAP_WIDTH - 2)
	{
		clousDrifting = 0;
	}
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmGround);
	GetObject(hbmGround, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX,
		CLOUD_HEIGHT,
		MAP_WIDTH,
		MAP_HEIGHT,
		hdcMem,
		mapSlider,
		0,
		SRCCOPY
	);
	oldBitmap = SelectObject(hdcMem, hbmCloud);
	GetObject(hbmCloud, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX ,
		posY,
		MAP_WIDTH,
		CLOUD_HEIGHT,
		hdcMem,
		clousDrifting,
		0,
		SRCCOPY
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
}

bool Map::checkToAddEnemy(int a_posX)
{
	bool checkPosition = false;
	for (int i = 0; i < NUMBER_OF_MONSTERS; i++)
	{
		if (a_posX == enemiesPosition[i])
		{
			checkPosition = true;
		}
	}
	return checkPosition;
}
