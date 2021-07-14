#include "Character.h"

Character::Character() 
{
	posX = 0;
	posY = 372;
	formX = 7;
	formY = 0;
	life = 3;
	jumpHeight = 0;
	hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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

void BaseObject::moveLeft()
{
	posX = posX - PLAYER_SPEED;
}

void BaseObject::moveRight()
{
	posX = posX + PLAYER_SPEED;
}

void Character::moveUp()
{
	jumpHeight += 84;
	if (jumpHeight > 84)
		jumpHeight = 84;

}

void Character::moveDown()
{
	jumpHeight = 0;
}

void Character::draw(HWND hwnd, HDC hdc)
{
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmMask);
	GetObject(hbmMask, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		posX - mapSlider,
		//posX,
		posY - jumpHeight,
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
		posX - mapSlider,
		//posX,
		posY - jumpHeight,
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


bool BaseObject::isGoLeft()
{
	if ((formY != 3) && (formX <= 6) && (formX != 2))
		return true;
	return false;
}

bool  BaseObject::isGoRight()
{
	if ((formY != 3) && (formX >= 7) && (formX != 11))
		return true;
	return false;
}

bool Character::isJump()
{
	if (posY > 0)
		return true;
	return false;
}

void Character::setJumpHeight(int a_jumpHeight)
{
	this->jumpHeight = a_jumpHeight;
}

void Character::increseJumpHeight(int a)
{
	this->jumpHeight += a;
}

int Character::getJumpHeight()
{
	return jumpHeight;
}