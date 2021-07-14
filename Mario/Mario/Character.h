#pragma once
#include <cmath>
#include "BaseObject.h"
#include "Map.h"

#define CHARACTER_WIDTH 62.5
#define CHARACTER_HEIGHT 93
#define PLAYER_SPEED 4

class Character : public BaseObject
{
private:
	int life;
	int jumpHeight;
public:
	Character();
	~Character();
	int getFormX();
	int getFormY();
	void setFormX(int a_formX);
	void setFormY(int a_formY);
	void increseFormX(int a);
	void draw(HWND hwnd, HDC hdc) override;
	void moveUp();
	void moveDown();
	bool isJump();
	void setJumpHeight(int a_jumpHeight);
	void increseJumpHeight(int a);
	int getJumpHeight();
};



