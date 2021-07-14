#pragma once
#include <windows.h>
#include <WindowsX.h>
#include <ctime>
#include <chrono>
#include <time.h>



class BaseObject
{
protected:
	int posX;
	int posY;
	int formX;
	int formY;
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
	virtual void makeAnimation();
	virtual void moveLeft();
	virtual void moveRight();
	virtual bool isGoLeft();
	virtual bool isGoRight();

	static int mapSlider;
	static int clousDrifting;
};

