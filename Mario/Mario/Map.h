#pragma once
#include "BaseObject.h"
class Map :public BaseObject
{
private:
	HBITMAP hbmGround, hbmCloud;
	int enemiesPosition[7] = { 500, 1000, 1400, 1800, 2300, 2700, 3200 };
public:

	Map();
	~Map();
	void draw(HWND hwnd, HDC hdc) override;
	
};

