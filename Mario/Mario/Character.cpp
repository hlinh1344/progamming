#include "Character.h"

Character::Character() 
{
	posX = 0;
	posY = 372;
	formX = 7;
	formY = 0;
	life = 3;
	jumpHeight = 0;
	isJump = false;
	isFalling = false;
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
	
	this->isJump = true;
	if (jumpHeight >= 100)
	{
		this->isFalling = true;
	}
	else
	{
		jumpHeight += 70;
		this->isFalling = false;
	}
		

	
}

void Character::MoveDown()
{
	if (jumpHeight > 0)
	{
		jumpHeight -= 10;
		this->isFalling = true;
	}
	else
		this->isFalling = true;
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
void Character::SetJump(bool trueOrFalse)
{
	this->isJump = trueOrFalse;
}

bool Character::CheckJump()
{
	if (jumpHeight > 0)
		this->isJump = true;
	else
		this->isJump = false;

	return this->isJump;
}

bool Character::CheckFalling()
{
	return this->isJump;
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
	return this->jumpHeight;
}

void BaseObject::SetDeath(bool a_isDead)
{
	this->isDead = a_isDead;
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