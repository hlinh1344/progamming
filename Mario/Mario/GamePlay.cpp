#include "GamePlay.h"

void GamePlay::init()
{
	//objects.push_back(e1);
	//objects.push_back(e2);
	//objects.push_back(e3);
	//objects.push_back(e4);
}
void GamePlay::run()
{
	// check to add monster
	// based map settings
	// draw()
	// check to move mario
	// moveMonster()
	// handle collision
	// 
}
void GamePlay::draw(HWND hwnd, HDC hdc)
{
	map.draw(hwnd, hdc);
	Mario.draw(hwnd,hdc);
	// for monster in object
	// monster.draw()
}
void GamePlay::moveMonsters()
{
	// for monster in object
	// monster.move()
}
void GamePlay::moveMarioLeft()
{
	Mario.moveLeft();
}

void GamePlay::moveMarioRight()
{
	Mario.moveRight();
}

void GamePlay::moveMarioUp()
{
	Mario.moveUp();
}

void GamePlay::moveMarioDown()
{
	Mario.moveDown();
}

void GamePlay::keyUpMarioDown()
{
	if (Mario.isGoRight())
		Mario.setFormX(7);
	else
		Mario.setFormX(6);
}

void GamePlay::keyUpMarioUp()
{
	Mario.setPosY(0);
	if(Mario.isGoRight())
		Mario.setFormX(7);
	else
		Mario.setFormX(6);
}

void GamePlay::keyUpMarioRight()
{
	Mario.setFormX(7);
}

void GamePlay::keyUpMarioLeft()
{
	Mario.setFormX(6);
}