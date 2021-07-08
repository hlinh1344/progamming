#include "Map.h"

Map::Map()
{
	hbmGround = (HBITMAP)LoadImage(hInst, L"mario_map.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmCloud = (HBITMAP)LoadImage(hInst, L"cloud.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}
Map::~Map()
{

}
void Map::draw(HWND hwnd, HDC hdc)
{
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmGround);
	GetObject(hbmGround, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		0,
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
		0,
		0,
		MAP_WIDTH,
		CLOUD_HEIGHT,
		hdcMem,
		clousDrifting + 360,
		0,
		SRCCOPY
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
}
