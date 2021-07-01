#pragma once
#include "BaseObject.h"

#define CHARACTER_WIDTH 62.5
#define CHARACTER_HEIGHT 93
#define MAP_WIDTH 984
#define MAP_HEIGHT 540
#define PLAYER_SPEED 0.5

class Character : public BaseObject
{
private:
	int formX;
	int formY;
	bool isJump;
	int life;
	HBITMAP hBitmap2;
public:
	Character();
	~Character();
	int getFormX();
	int getFormY();
	void setFormX(int a_formX);
	void setFormY(int a_formY);
	void increseFormX(int a);
	void draw(HWND hwnd, HDC hdc) override;
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	bool isGoLeft();
	bool isGoRight();
};

static int mapSlider = 0;

