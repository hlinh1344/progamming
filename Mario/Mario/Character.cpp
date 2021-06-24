#include "Character.h"

Character::Character() 
{
	posX = 0;
	posY = 400;
	formX = 0;
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

void  Character::setPosX(int a_posX)
{
	this->posX = a_posX;
}

void  Character::setPosY(int a_posY)
{
	this->posY = a_posY;
}

void  Character::setFormX(int a_formX)
{
	this->formX = a_formX;
}

void  Character::setFormY(int a_formY)
{
	this->formY = a_formY;
}

void Character::draw(HWND hwnd) 
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);
	HBITMAP hBitmap = NULL;
	HINSTANCE hInst = NULL;
	HDC hdcMem = NULL;
	HGDIOBJ oldBitmap = NULL;
	BITMAP bitmap;
	hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hBitmap);
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	BitBlt(hdc, posX, posY, CHARACTER_WIDTH, CHARACTER_HEIGHT, hdcMem, 90 * formX, 70 *formY, SRCCOPY);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
	//InvalidateRect(hwnd, NULL, FALSE);
	//EndPaint(hwnd, &ps);
}
