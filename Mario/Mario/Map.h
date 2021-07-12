#pragma once
#include "BaseObject.h"

#define MAP_WIDTH 984
#define MAP_HEIGHT 290
#define CLOUD_HEIGHT 246
#define CLOUD_WIDTH 5218
#define CLOUD_SPEED 2
#define NUMBER_OF_MONSTERS 7
class Map :public BaseObject
{
private:
	HBITMAP hbmGround, hbmCloud;
	int enemiesPosition[NUMBER_OF_MONSTERS] = { 500, 1000, 1400, 1800, 2300, 2700, 3200 };
public:
	
	Map();
	~Map();
	void draw(HWND hwnd, HDC hdc) override;
	void increseMapSlider(int a);
	void increseClousDrifting(int a);
	int getMapSlider();
	bool checkToAddEnemy(int a_posX);
};


