#include <WindowsX.h>
#include "Character.h"

Character::Character() 
{
	posX = 0;
	posY = 400;
	formX = 7;
	formY = 0;
	isJump = false;
	isDead = false;
	life = 3;
}

Character::~Character()
{

}

int Character::getPosX()
{
	return posX;
}

int Character::getPosY()
{
	return posY;
}

int Character::getFormX()
{
	return formX;
}

int Character::getFormY() 
{
	return formY;
}

void Character::setPosX(int a_posX)
{
	this->posX = a_posX;
}

void Character::setPosY(int a_posY)
{
	this->posY = a_posY;
}

void Character::setFormX(int a_formX)
{
	this->formX = a_formX;
}

void Character::setFormY(int a_formY)
{
	this->formY = a_formY;
}

void Character::incresePosX(int a)
{
	this->posX = this->posX + a;
}

void Character::incresePosY(int a)
{
	this->posY = this->posY + a;
}

void Character::increseFormX(int a)
{
	this->formX = this->formX + a;
}

void Character::moveLeft()
{
		posX -= 10;
		if (posX <= -20)
			posX += 10;
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
	posX += 10;
	if (posX >= (1000-63))
		posX -= 10;
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
	if (posY <= 350)
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


void Character::draw(HWND hwnd) 
{

	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	HBITMAP hBitmap, hbmMask = NULL;
	HINSTANCE hInst = NULL;
	HDC hdcMem = NULL;
	HGDIOBJ oldBitmap = NULL;
	BITMAP bitmap;
	HBRUSH hbrushOld = CreateSolidBrush(RGB(20, 95, 155));
	FillRect(hdc, &ps.rcPaint, hbrushOld);
	hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hdcMem = CreateCompatibleDC(hdc);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
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
	EndPaint(hwnd, &ps);
}

HBITMAP Character::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
{
	HDC hdcMem, hdcMem2;
	HBITMAP hbmMask;
	BITMAP bm;
	GetObject(hbmColour, sizeof(BITMAP), &bm);
	hbmMask = CreateBitmap(bm.bmWidth, bm.bmHeight, 1, 1, NULL);
	hdcMem = CreateCompatibleDC(0);
	hdcMem2 = CreateCompatibleDC(0);
	SelectBitmap(hdcMem, hbmColour);
	SelectBitmap(hdcMem2, hbmMask);
	SetBkColor(hdcMem, crTransparent);
	BitBlt(hdcMem2, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
	BitBlt(hdcMem, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem2, 0, 0, SRCINVERT);
	DeleteDC(hdcMem);
	DeleteDC(hdcMem2);
	return hbmMask;
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