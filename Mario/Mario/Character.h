#pragma once
#include <cmath>
#include "BaseObject.h"


#define CHARACTER_WIDTH 62.5
#define CHARACTER_HEIGHT 93
#define PLAYER_SPEED 0.5

class Character : public BaseObject
{
private:
	int formX;
	int formY;
	int life;
	int ground;
	HBITMAP hBitmap2, hBitmap3;
	int clousDrifting;

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
	bool isJump();
};



