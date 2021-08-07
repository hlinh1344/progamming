#include "Weapon.h"

Weapon::Weapon()
{
	bool isMoving = false;
	formY = 0;
}

Weapon::~Weapon()
{

}
void Weapon::Draw(HWND hwnd, HDC hdc)
{
	BaseObject::Draw(hwnd, hdc);
	MakeAnimation();
}


void Weapon::CheckDistance(int xOriginal)
{
	int distance = abs(xOriginal - posX);
	if (distance >= xArea)
	{
		isDead = true;
	}
}

