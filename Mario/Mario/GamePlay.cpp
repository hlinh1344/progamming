#include "GamePlay.h"



GamePlay::GamePlay()
{

}

GamePlay::~GamePlay()
{
	for (auto object : objects) {
		delete(object);
		object = nullptr;
	}
}


void GamePlay::init()
{


}

void GamePlay::run()
{
	/*int count = 0;
	if (map.checkToAddEnemy(BaseObject::mapSlider + MAP_WIDTH))
	{
		count++;
		switch (count)
		{
		case 1:
			objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case2:
			objects.push_back(new EnemyDuck(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case 3:
			objects.push_back(new EnemySpinyBeetle(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case 4:
			objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case 5:
			objects.push_back(new EnemyBuzzyBeetle(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case 6:
			objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
			break;
		case 7:
			objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
			break;
		default:
			break;
		}
	}*/

	if (BaseObject::mapSlider + MAP_WIDTH == 1000)
		objects.push_back(new EnemyMushroom(1000));
	else if (BaseObject::mapSlider + MAP_WIDTH == 1400)
		objects.push_back(new EnemyDuck(1400));
	else if (BaseObject::mapSlider + MAP_WIDTH == 1800)
		objects.push_back(new EnemySpinyBeetle(1800));
	else if (BaseObject::mapSlider + MAP_WIDTH == 2400)
		objects.push_back(new EnemyBuzzyBeetle(2400));
	// check to add monster
	// based map settings
	// draw
	// check to move mario
	// moveMonster()
	// handle collision

}

void GamePlay::draw(HWND hwnd, HDC hdc)
{
	map.draw(hwnd, hdc);
	mario.draw(hwnd,hdc);
	//for () 
	for (auto object : objects) {
		object->draw(hwnd, hdc);
	}

	//e1->draw(hwnd, hdc);
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
	mario.moveLeft();
	if (mario.getPosX() - map.getMapSlider() <= 0)
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
	if (mario.getPosX() - map.getMapSlider() >= 500)
	{
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