#pragma once
#include <windows.h>
#include <WindowsX.h>
#include <vector>

#include "Character.h"
#include "BaseObject.h"
#include "EnemyMushroom.h"
#include "EnemyDuck.h"
#include "EnemyBuzzyBeetle.h"
#include "EnemySpinyBeetle.h"
#include "Map.h"

class GamePlay
{
private:
	std::vector <BaseObject*> objects; // static objects
	Map map;
	Character mario;
	int enemyID;
	time_t currentTime;   // get time now
	tm now;
public:
	GamePlay();
	~GamePlay();

	void init();
	void run();
	void draw(HWND hwnd, HDC hdc);
	void moveMonsters();
	void moveMarioLeft();
	void moveMarioRight();
	void moveMarioUp();
	void moveMarioDown();
	void keyUpMarioDown();
	void keyUpMarioUp();
	void keyUpMarioLeft();
	void keyUpMarioRight();
};

