#pragma once
#include "BaseObject.h"
#include "Map.h"

#define BULLET_HEIGHT 26
#define BULLET_WIDTH 30
#define BULLET_AREA 500
#define BULLET_SPEED 10

class Bullet :
    public BaseObject
{
protected:

	int originalLocation;
	bool isMoving;
	int dir; // left = 0, right = 1
	int type; // type of weapon
public:
	Bullet();
	~Bullet();
	Bullet(int a_x, int a_dir, int	a_posY);


	void SetIsMoving(bool a_isMoving);
	bool GetIsMoving();
	void CheckDistance();
	void Draw(HWND hwnd, HDC hdc) override;
	void MoveLeft() override;
	void MoveRight() override;
	bool IsGoLeft() override;
	bool IsGoRight()override;
	void SetDeath(bool a_isDead) override;
	int GetWidth() override;
	int GetHeight() override;

};

