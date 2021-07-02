#include "Character.h"

Character::Character() 
{
	posX = 0;
	posY = 372;
	formX = 7;
	formY = 0;
	isJump = false;
	life = 3;

	hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBitmap2 = (HBITMAP)LoadImage(hInst, L"mario_map.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
}

Character::~Character()
{

}

int Character::getFormX()
{
	return formX;
}

int Character::getFormY() 
{
	return formY;
}

void Character::setFormX(int a_formX)
{
	this->formX = a_formX;
}

void Character::setFormY(int a_formY)
{
	this->formY = a_formY;
}

void Character::increseFormX(int a)
{
	this->formX = this->formX + a;
}

void Character::moveLeft()
{
	//posX -= 6;
	//if (posX <= 0)
	//{
	//	posX += 6;
	//	mapSlider -= 6;
	//}

	//if (mapSlider <= 0)
	//{
	//	posX -= 6;
	//	mapSlider -= 6;
	//}

	posX -= 5;
	mapSlider -= 5;
	if (posX <= 0)
	{
		posX += 5;
		mapSlider += 5;
	}
			
	if (isGoRight())
		formX = 2;
	else
	{
		if (formX <= 3)
			formX = 5;
		else
			formX--;
	}
}

void Character::moveRight()
{
	posX += 5;
	if (posX >= (550))
	{
		posX -= 5;
		mapSlider += 5;
	}

	if ((mapSlider >= 1313) && (mapSlider <= 1457))
	{
		if (posY < 372)
		{
			posY = 290;
		}
		else if(posY = 372)
		{
			posX -= 5;
			mapSlider -= 5;
		}
	}

	if (mapSlider == 1460)
		posY = 372;
	
	if (mapSlider >= 3155)
	{
		posX -= 5;
		mapSlider -= 5;
	}

	if (isGoLeft())
		formX = 11;
	else
	{
		if (formX >= 10)
			formX = 8;
		else
			formX++;
	}
}

void Character::moveUp()
{
	posY -= 83;
	if (posY <= 277)
		posY +=83;
	if (isGoRight())
		formX = 12;
	else
		formX = 1;
}

void Character::moveDown()
{
	if (isGoRight())
		formX = 13;
	else
		formX = 0;
}

void Character::draw(HWND hwnd, HDC hdc)
{
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hBitmap2);
	GetObject(hBitmap2, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		0,
		0,
		MAP_WIDTH,
		MAP_HEIGHT,
		hdcMem,
		mapSlider,
		0,
		SRCCOPY
	);
	oldBitmap = SelectObject(hdcMem, hbmMask);
	GetObject(hbmMask, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX,
		posY,
		CHARACTER_WIDTH,
		CHARACTER_HEIGHT,
		hdcMem,
		CHARACTER_WIDTH * formX,
		CHARACTER_HEIGHT * formY,
		SRCAND
	);
	oldBitmap = SelectObject(hdcMem, hBitmap);
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX,
		posY,
		CHARACTER_WIDTH,
		CHARACTER_HEIGHT,
		hdcMem,
		CHARACTER_WIDTH * formX,
		CHARACTER_HEIGHT * formY,
		SRCPAINT
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
}


bool Character::isGoLeft()
{
	if ((formY != 3) && (formX <= 6) && (formX != 2))
		return true;
	return false;
}

bool  Character::isGoRight()
{
	if ((formY != 3) && (formX >= 7) && (formX != 11))
		return true;
	return false;
}