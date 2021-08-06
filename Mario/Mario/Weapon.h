#pragma once

#include "LiveObject.h"

class Weapon : public LiveObject
{
protected:
	bool isMoving;
	int dir; // left = 0, right = 1
	int xOriginal;
	int xArea;
	int yArea;
	int yOriginal;
public:
	Weapon();
	~Weapon();
	void SetIsMoving(bool a_isMoving);
	bool GetIsMoving();
	void virtual CheckDistance();
	void Draw(HWND hwnd, HDC hdc) override;
	void MakeAnimation() override;
};

