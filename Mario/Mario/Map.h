#pragma once
#include "BaseObject.h"
#include <fstream>
#include <string>

#define MAP_WIDTH 985
//#define MAP_HEIGHT 290
#define MAP_HEIGHT 536
//#define CLOUD_HEIGHT 246

#define MAX_OF_MONSTERS 21
#define END_OF_MAP 3655
#define MAX_OF_ITEMS 10

class Map :public BaseObject
{
private:
	int mapID;
	int monsters;
	int items;

	HBITMAP hbmGround, hbmCloud, hbmMask;
	
	int enemiesPosition[MAX_OF_MONSTERS];

	int itemsPosition[MAX_OF_ITEMS];

public:

	Map();
	~Map();
	void Draw(HWND hwnd, HDC hdc) override;
	void increseMapSlider(int a);
	int getMapSlider();
	void checkToAddEnemy(int a_posX, int &enemyID, bool &checkToAdd);
	void checkToAddItem(int a_posX, int& itemyID, bool& checkToAdd);
	void Switch();
	void loadMap(int mapID);
};
