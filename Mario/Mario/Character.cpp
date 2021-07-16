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

int Character::GetFormX()
{
	return formX;
}

int Character::GetFormY() 
{
	return formY;
}

void Character::SetFormX(int a_formX)
{
	this->formX = a_formX;
}

void Character::SetFormY(int a_formY)
{
	this->formY = a_formY;
}

void Character::IncreseFormX(int a)
{
	this->formX = this->formX + a;
}

void BaseObject::MoveLeft()
{
	posX = posX - PLAYER_SPEED;
}

void BaseObject::MoveRight()
{
	posX = posX + PLAYER_SPEED;
}

void Character::MoveUp()
{
	jumpHeight += 90;
	if (jumpHeight > 90)
		jumpHeight = 90;
}

void Character::MoveDown()
{
	jumpHeight = 0;
}

void Character::Draw(HWND hwnd, HDC hdc)
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


bool BaseObject::IsGoLeft()
{
	if ((formY != 3) && (formX <= 6) && (formX != 2))
		return true;
	return false;
}

bool  BaseObject::IsGoRight()
{
	if ((formY != 3) && (formX >= 7) && (formX != 11))
		return true;
	return false;
}

bool Character::IsJump()
{
	if (jumpHeight > 0)
		return true;
	return false;
}

void Character::SetJumpHeight(int a_jumpHeight)
{
	this->jumpHeight = a_jumpHeight;
}

void Character::IncreseJumpHeight(int a)
{
	this->jumpHeight += a;
}

int Character::GetJumpHeight()
{
	return jumpHeight;
}

void BaseObject::SetDeath()
{
	this->isDead = true;
	if ((formY > 0) && (formY < 3))
	{
		formY--;
	}
	else if (formY == 0)
	{
		this->life--;
		formX = 0;
		formY = 3;
	}
}

bool Character::CheckDeath()
{
	return this->isDead;
}