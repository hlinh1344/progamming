#include "GamePlay.h"



GamePlay::GamePlay()
{
	enemyID = 0;
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

	enemyID = (map.checkToAddEnemy(BaseObject::mapSlider + MAP_WIDTH));

	switch (enemyID)
	{
	case 1:
		objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
		enemyID = 0;
		break;
	case 2:
		objects.push_back(new EnemyDuck(BaseObject::mapSlider + MAP_WIDTH));
		enemyID = 0;
		break;
	case 3:
		objects.push_back(new EnemySpinyBeetle(BaseObject::mapSlider + MAP_WIDTH));
		enemyID = 0;
		break;
	case 4:
		objects.push_back(new EnemyMushroom(BaseObject::mapSlider + MAP_WIDTH));
		enemyID = 0;
		break;
	case 5:
		objects.push_back(new EnemyBuzzyBeetle(BaseObject::mapSlider + MAP_WIDTH));
		enemyID = 0;
		break;
	default:
		break;
	}
	

	//time_t currentTime2 = time(NULL);   // get time now
	//tm now2;
	//localtime_s(&now2, &currentTime2);
	//double  diff = (-1) * (double)difftime(currentTime, mktime(&now2));

	//if (diff > 0.0000001)
	//{
	//	currentTime = currentTime2;
	//	localtime_s(&now, &currentTime);
	//	for (auto object : objects) {
	//		object->makeAnimation();
	//	}
	//}

	// check to add monster
	// based map settings
	// draw
	// check to move mario
	// moveMonster()
	// handle collision

}

void GamePlay::draw(HWND hwnd, HDC hdc)
{
	timer++;
	map.draw(hwnd, hdc);
	mario.draw(hwnd,hdc);
	//for () 
	if (timer >= 2)
	{
		for (auto object : objects) {
			object->draw(hwnd, hdc);
			object->makeAnimation();
		}
		timer = 0;
	}
	else
	{
		for (auto object : objects) {
			object->draw(hwnd, hdc);
		}
	}
		


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

	//for (auto object : objects) {
	//	object->makeAnimation();
	//}
}

void GamePlay::moveMarioRight()
{
	mario.moveRight();
	map.increseClousDrifting(CLOUD_SPEED);
	if (mario.getPosX() - map.getMapSlider() >= 500)
	{
		map.increseMapSlider(PLAYER_SPEED);
	}
	
	if (mario.getPosX() >= END_OF_MAP)
	{
		map.increseMapSlider(-PLAYER_SPEED);
		mario.moveLeft();
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

	//for (auto object : objects) {
	//	object->makeAnimation();
	//}
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