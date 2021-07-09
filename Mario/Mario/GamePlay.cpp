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
	if (map.checkToAddEnemy(mapSlider + MAP_WIDTH))
	{
		EnemyMushroom* mushroom = e1->clone(mapSlider + MAP_WIDTH);
		objects.push_back(mushroom);
	}
	// check to add monster
	// based map settings
	// draw
	// check to move mario
	// moveMonster()
	// handle collision
	// 
}
void GamePlay::draw(HWND hwnd, HDC hdc)
{
	map.draw(hwnd, hdc);
	mario.draw(hwnd,hdc);
	// for monster in object
	objects[0]->draw(hwnd, hdc);
	// monster.draw()
}
void GamePlay::moveMonsters()
{
	// for monster in object
	// monster.move()
}
void GamePlay::moveMarioLeft()
{
	mario.moveLeft();
	if (mario.getPosX() - mapSlider <= 0)
	{
		mario.incresePosX(PLAYER_SPEED);
	}
	//change sprite
	if (mario.isGoRight())
		mario.setFormX(2);
	else
	{
		if (mario.getFormX() <= 3)
			mario.setFormX(5);
		else
			mario.increseFormX(-1);
	}
}

void GamePlay::moveMarioRight()
{
	mario.moveRight();
	map.increseClousDrifting(CLOUD_SPEED);
	if (mario.getPosX() - mapSlider >= 500)
	{
		mario.incresePosX(-PLAYER_SPEED);
		map.increseMapSlider(PLAYER_SPEED);
	}
	
	//change sprite
	if (mario.isGoLeft())
		mario.setFormX(11);
	else
	{
		if (mario.getFormX() >= 10)
			mario.setFormX(8);
		else
			mario.increseFormX(1);
	}
}

void GamePlay::moveMarioUp()
{
	mario.moveUp();
	if (mario.isGoRight())
		mario.setFormX(12);
	else
		mario.setFormX(1);
}

void GamePlay::moveMarioDown()
{
	mario.moveDown();
	if (mario.isGoRight())
		mario.setFormX(13);
	else
		mario.setFormX(0);
}

void GamePlay::keyUpMarioDown()
{
	if (mario.isGoRight())
		mario.setFormX(7);
	else
		mario.setFormX(6);
}

void GamePlay::keyUpMarioUp()
{

	while (mario.getJumpHeight() <= 0)
	{
		mario.increseJumpHeight(-4);
	}
	mario.setJumpHeight(0);
	
	//if(mario.getJumpHeight() <=0)
	//	mario.setJumpHeight(0);

	if(mario.isGoRight())
		mario.setFormX(7);
	else
		mario.setFormX(6);
}

void GamePlay::keyUpMarioRight()
{
	mario.setFormX(7);
}

void GamePlay::keyUpMarioLeft()
{
	mario.setFormX(6);
}