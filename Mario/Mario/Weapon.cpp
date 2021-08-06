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
	CheckDistance();

}
void Weapon::SetIsMoving(bool a_isMoving)
{
	isMoving = a_isMoving;
}

bool  Weapon::GetIsMoving()
{
	return isMoving;
}

void Weapon::CheckDistance() 
{
	int distance = abs(xOriginal - posX);
	if (distance >= xArea)
	{
		isDead = true;
	}
}

void Weapon::MakeAnimation()
{
	//if (dir == 0)
	//{
	//	MoveLeft();
	//}
	//else if (dir == 1)
	//{
	//	MoveRight();
	//}
}