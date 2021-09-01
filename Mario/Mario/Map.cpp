#include "Map.h"

Map::Map()
{
	posX = 0;
	posY = 0;
	hbmGround = (HBITMAP)LoadImage(hInst, L"Map2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	mapID = 1;
	loadMap(mapID);
}
Map::~Map()
{

}

void Map::increseMapSlider(int a)
{
	BaseObject::mapSlider = BaseObject::mapSlider + a;
}


int Map::getMapSlider()
{
	return BaseObject::mapSlider;
}

void Map::Draw(HWND hwnd, HDC hdc)
{
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmGround);
	GetObject(hbmGround, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX,
		0,
		MAP_WIDTH,
		MAP_HEIGHT,
		hdcMem,
		BaseObject::mapSlider,
		0,
		SRCCOPY
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
}

void Map::checkToAddEnemy(int a_posX, int& enemyID, bool& checkToAdd)
{
	int checkPosition = 0;
	for (int i = 0; i < MAX_OF_MONSTERS; i++)
	{
		if (a_posX == enemiesPosition[i])
		{
			checkPosition = i + 1;
		}
	}

	if (enemyID == checkPosition)
	{
		checkToAdd = false;
	}
	else if (enemyID != checkPosition)
	{
		checkToAdd = true;
		enemyID = checkPosition;
	}
}

void Map::checkToAddItem(int a_posX, int& itemID, bool& checkToAdd)
{
	int checkPosition = 0;
	for (int i = 0; i < MAX_OF_ITEMS; i++)
	{
		if (a_posX == itemsPosition[i])
		{
			checkPosition = i + 1;
		}
	}

	if (itemID == checkPosition)
	{
		checkToAdd = false;
	}
	else if (itemID != checkPosition)
	{
		checkToAdd = true;
		itemID = checkPosition;
	}
}


void Map::Switch()
{
	hbmGround = (HBITMAP)LoadImage(hInst, L"Map1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	BaseObject::mapSlider = 0;
	mapID++;
	loadMap(mapID);
}

void Map::loadMap(int mapID)
{
	std::ifstream map;
	switch (mapID)
	{
	case 1:
		map.open("map1.txt");
		break;
	case 2:
		map.open("map2.txt");
		break;
	default:
		break;
	}

	if (map.is_open())
	{
		char line[5] = {};
		while (!map.eof())
		{
			map.getline(line,5);
			monsters = atoi(line);
			for (int i = 0; i < monsters; i++)
			{
				map.getline(line, 5);
				enemiesPosition[i] = atoi(line);
			}


			map.getline(line, 5);
			items = atoi(line);
			for (int i = 0; i < items; i++)
			{
				map.getline(line, 5);
				itemsPosition[i] = atoi(line);
			}
		}



	}
	map.close();	
}