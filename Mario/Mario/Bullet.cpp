#include "Bullet.h"


void Bullet::SetIsMoving(bool a_isMoving)
{
	this->isMoving = a_isMoving;
}

bool  Bullet::GetIsMoving()
{
	return this->isMoving;
}

Bullet::Bullet(int a_x, int a_dir, int	a_posY)
{
	posX = a_x;
	posY = a_posY;
	formX = a_dir;
	dir = a_dir;
	formY = 0;
	originalLocation = a_x;
	life = 1;
	isMoving = false;
	hBitmap = (HBITMAP)LoadImage(hInst, L"Bullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
}

Bullet::Bullet()
{
	posX = 0;
	posY = 421;
	formX = 1;
	formY = 0;
	originalLocation = 0;
	life = 1;
	isMoving = false;
	hBitmap = (HBITMAP)LoadImage(hInst, L"Bullet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 255, 255));
}
Bullet::~Bullet()
{

}

void Bullet::Draw(HWND hwnd, HDC hdc)
{
	if (!isDead)
	{
		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hbmMask);
		GetObject(hbmMask, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX - BaseObject::mapSlider,
			posY,
			BULLET_WIDTH,
			BULLET_HEIGHT,
			hdcMem,
			BULLET_WIDTH * formX,
			BULLET_HEIGHT * formY,
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			posX - BaseObject::mapSlider,
			posY,
			BULLET_WIDTH,
			BULLET_HEIGHT,
			hdcMem,
			BULLET_WIDTH * formX,
			BULLET_HEIGHT * formY,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
		if (dir == 0)
		{
			MoveLeft();
			if (formX <= 0)
				formX = 3;
			else
				formX--;
		}
		else if (dir == 1)
		{
			MoveRight();
			if (formX >= 7)
				formX = 4;
			else
				formX++;
		}
		CheckDistance();
	}
}

void Bullet::MoveLeft() 
{
	posX = posX - BULLET_SPEED;
}

void Bullet::MoveRight() 
{
	posX = posX + BULLET_SPEED;
}

bool Bullet::IsGoLeft() 
{
	if (formX <= 3)
		return true;
	return false;
}

bool Bullet::IsGoRight()
{
	if (formX >= 4 )
		return true;
	return false;
}

void Bullet::SetDeath(bool a_isDead)
{
	this->isDead = a_isDead;
}

void Bullet::CheckDistance() 
{
	int distance = abs(originalLocation - posX);
	if (distance >= BULLET_AREA)
	{
		this->isDead = true;
	}
}

int Bullet::GetWidth() 
{
	return BULLET_WIDTH;
}

int Bullet::GetHeight()
{
	return BULLET_HEIGHT;
}