#include "BaseObject.h"

int BaseObject::clousDrifting = 0;
int BaseObject::mapSlider = 0;

BaseObject::BaseObject()
{
	isDead = false;
	hdcMem = NULL;
	oldBitmap = NULL;
	hInst = NULL;
}

BaseObject::~BaseObject()
{

}

void BaseObject::Draw(HWND hwnd, HDC hdc)
{

}

void BaseObject::IncresePosX(int a)
{
	this->posX = this->posX + a;
}

void BaseObject::IncresePosY(int a)
{
	this->posY = this->posY + a;
}

int BaseObject::GetPosX()
{
	return posX;
}

int BaseObject::GetPosY()
{
	return posY;
}

void BaseObject::SetPosX(int a_posX)
{
	this->posX = a_posX;
}

void BaseObject::SetPosY(int a_posY)
{
	this->posY = a_posY;
}

HBITMAP BaseObject::CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent)
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

void BaseObject::MakeAnimation()
{

}

bool BaseObject::GetDeath()
{
	return this->isDead;
}