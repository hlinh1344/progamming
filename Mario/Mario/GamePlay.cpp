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

void GamePlay::Run()
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
	
	for (auto object : objects) {
		Collision(mario, object);
	}
	// check to add monster
	// based map settings
	// Draw
	// check to move mario
	// moveMonster()
	// handle collision

}

void GamePlay::Draw(HWND hwnd, HDC hdc)
{
	timer++;
	map.Draw(hwnd, hdc);
	mario.Draw(hwnd,hdc);
	//for () 
	if (timer >= 2)
	{
		for (auto object : objects) {
			object->Draw(hwnd, hdc);
			object->MakeAnimation();

			if (mario.CheckDeath())
			{
				mario.IncreseJumpHeight(10);
			}

			if (mario.GetJumpHeight() > 0)
			{
				mario.IncreseJumpHeight(-1);
			}
		}
		timer = 0;
	}
	else
	{
		if (mario.GetJumpHeight() > 0)
		{
			mario.IncreseJumpHeight(-1);
		}

		for (auto object : objects) {
			object->Draw(hwnd, hdc);
		}
	}
		


	// for monster in object
	
	// monster.Draw()
}
void GamePlay::MoveMonsters()
{
	// for monster in object
	// monster.move()
}
void GamePlay::MoveMarioLeft()
{
	if (!mario.CheckDeath())
	{
		mario.MoveLeft();
		if (mario.GetPosX() - map.getMapSlider() <= 0)
		{
			mario.IncresePosX(PLAYER_SPEED);
		}

		//change sprite
		if (mario.IsGoRight())
			mario.SetFormX(2);
		else
		{
			if (mario.GetFormX() <= 3)
				mario.SetFormX(5);
			else
				mario.IncreseFormX(-1);
		}
	}


	//for (auto object : objects) {
	//	object->MakeAnimation();
	//}
}

void GamePlay::MoveMarioRight()
{
	if (!mario.CheckDeath())
	{
		mario.MoveRight();
		map.increseClousDrifting(CLOUD_SPEED);
		if (mario.GetPosX() - map.getMapSlider() >= 500)
		{
			map.increseMapSlider(PLAYER_SPEED);
		}

		if (mario.GetPosX() >= END_OF_MAP)
		{
			map.increseMapSlider(-PLAYER_SPEED);
			mario.MoveLeft();
		}

		//change sprite
		if (mario.IsGoLeft())
			mario.SetFormX(11);
		else
		{
			if (mario.GetFormX() >= 10)
				mario.SetFormX(8);
			else
				mario.IncreseFormX(1);
		}
	}


	//for (auto object : objects) {
	//	object->MakeAnimation();
	//}
}

void GamePlay::MoveMarioUp()
{
	if (!mario.CheckDeath())
	{
		mario.MoveUp();
		if (mario.IsGoRight())
			mario.SetFormX(12);
		else
			mario.SetFormX(1);
	}

}

void GamePlay::MoveMarioDown()
{
	if (!mario.CheckDeath())
	{
		mario.MoveDown();
		if (mario.IsGoRight())
			mario.SetFormX(13);
		else
			mario.SetFormX(0);
	}

}

void GamePlay::KeyUpMarioDown()
{
	if (!mario.CheckDeath())
	{
		if (mario.IsGoRight())
			mario.SetFormX(7);
		else
			mario.SetFormX(6);

	}
}

void GamePlay::KeyUpMarioUp()
{
	if (!mario.CheckDeath())
	{
		if (mario.IsGoRight())
			mario.SetFormX(7);
		else
			mario.SetFormX(6);
	}

}

void GamePlay::KeyUpMarioRight()
{
	if (!mario.CheckDeath())
	{
		mario.SetFormX(7);
	}
	
}

void GamePlay::KeyUpMarioLeft()
{
	if (!mario.CheckDeath())
	{
		mario.SetFormX(6);
	}
	
}

void GamePlay::Collision(Character &mario, BaseObject* monster)
{
	//horizontal
	int marioLeftEdge = mario.GetPosX();
	int marioRightEdge = mario.GetPosX() + CHARACTER_WIDTH;
	int marioTopEdge = mario.GetPosY();
	int marioBottomEdge = mario.GetPosY() + CHARACTER_HEIGHT;
	int monsterLeftEdge = monster->GetPosX();
	int monsterRightEdge = monster->GetPosX() + 45 ;
	int monsterTopEdge = monster->GetPosY();
	int monsterBottomEdge = monster->GetPosY() + 42 ;

	if ((marioRightEdge > monsterLeftEdge) && (marioRightEdge < monsterRightEdge))
	{
		if (!mario.IsJump())
		{
			mario.SetDeath();
		}
	}
}