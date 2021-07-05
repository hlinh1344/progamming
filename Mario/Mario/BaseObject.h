#pragma once
#include <windows.h>
#include <WindowsX.h>
#include <ctime>
#include <chrono>
#include <time.h>

#define MAP_WIDTH 984
#define MAP_HEIGHT 290
#define CLOUD_HEIGHT 246

class BaseObject
{
protected:
	int posX;
	int posY;
	bool isDead;
	HBITMAP hBitmap, hbmMask;
	HINSTANCE hInst;
	HDC hdcMem;
	HGDIOBJ oldBitmap;
	BITMAP bitmap;
	
public:
	BaseObject();
	~BaseObject();
	int getPosX();
	int getPosY();
	void setPosX(int a_posX);
	void setPosY(int a_posY);
	void incresePosX(int a);
	void incresePosY(int a);
	virtual void draw(HWND hwnd, HDC hdc);
	HBITMAP CreateBitmapMask(HBITMAP hbmColour, COLORREF crTransparent);
};

static int mapSlider;