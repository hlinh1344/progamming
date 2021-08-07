#pragma once

#include "LiveObject.h"

class Weapon : public LiveObject
{
protected:
	int dir; // left = 0, right = 1
	int xOriginal;
	int xArea;
	int yArea;
	int yOriginal;
public:
	Weapon();
	~Weapon();

	void virtual CheckDistance(int xOriginal);
	void Draw(HWND hwnd, HDC hdc) override;

};

