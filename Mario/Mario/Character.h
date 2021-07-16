#pragma once
#include <cmath>
#include "BaseObject.h"
#include "Map.h"

#define CHARACTER_WIDTH 62.5
#define CHARACTER_HEIGHT 93
#define PLAYER_SPEED 4

class Character : public BaseObject
{
private:
	int jumpHeight;
public:
	Character();
	~Character();
	int GetFormX();
	int GetFormY();
	void SetFormX(int a_formX);
	void SetFormY(int a_formY);
	void IncreseFormX(int a);
	void Draw(HWND hwnd, HDC hdc) override;
	void MoveUp();
	void MoveDown();
	bool IsJump();
	void SetJumpHeight(int a_jumpHeight);
	void IncreseJumpHeight(int a);
	int GetJumpHeight();
	bool CheckDeath();
};



