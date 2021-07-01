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
		posX -= 10;
		mapSlider -= 2;
		if (posX <= 0)
		{
			posX += 10;
			mapSlider += 2;
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
	posX += 6;
	if (posX >= (400 - 63))
	{
		posX -= 5;
		mapSlider += 7;
	}
	else
		mapSlider += 2;
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
	posY -= 40;
	if (posY <= 320)
		posY +=40;
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