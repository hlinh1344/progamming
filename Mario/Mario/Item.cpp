#include "Item.h"

Item::Item()
{
	isDead = false;
	posY = 50;
	xOriginal = posY;
	formX = 0;
	formY = 0;
}

Item::~Item()
{

}

int Item::GetTypeOfWeapn()
{
	return typeOfWeapn;
}

bool Item::CheckDeath()
{
	return isDead;
}

void Item::MakeAnimation() 
{
	clock++;
	if (clock >= 7)
	{
		clock = 0;

		if (formX == 0)
		{
			posY++;
			if (posY >= xOriginal + 10)
			{
				formX = 1;
			}
		}
		else if (formX == 1)
		{
			posY--;
			if (posY <= xOriginal)
			{
				formX = 0;
			}
		}
	}

}