#pragma once
#include <windows.h>

#define CHARACTER_WIDTH 90
#define CHARACTER_HEIGHT 70
class Character
{
private:
	int posX;
	int posY;
	int formX;
	int formY;
	bool isJump;
	bool isDead;
	int life;
public:
	Character();
	~Character();
	int getPosX();
	int getPosY();
	int getFormX();
	int getFormY();
	void setPosX(int a_posX);
	void setPosY(int a_posY);
	void setFormX(int a_formX);
	void setFormY(int a_formY);
	void draw(HWND hwnd);
};



