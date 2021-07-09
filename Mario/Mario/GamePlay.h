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
public:
	std::vector <BaseObject*> objects; // static objects

	Map map;
	Character mario;
	EnemyMushroom* e1;
	EnemyDuck* e2;
	EnemyBuzzyBeetle* e3;
	EnemySpinyBeetle* e4;

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

