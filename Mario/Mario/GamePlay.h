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
#include "Bullet.h"
class GamePlay
{
private:
	std::vector <BaseObject*> objects; // static objects
	std::vector <Bullet*> bullets;
	Map map;
	Character* mario = new Character();
	int enemyID;
	int timer;
public:
	GamePlay();
	~GamePlay();

	void Run();
	void Draw(HWND hwnd, HDC hdc);
	void MoveMonsters();
	void MoveMarioLeft();
	void MoveMarioRight();
	void MoveMarioUp();
	void MoveMarioDown();
	void Attack();
	void KeyUpMarioDown();
	void KeyUpMarioUp();
	void KeyUpMarioLeft();
	void KeyUpMarioRight();
	void KeyUpSpace();
	void Collision(Character* mario, BaseObject * monster);
};

