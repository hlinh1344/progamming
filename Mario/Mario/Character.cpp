#include "Character.h"

Character::Character()
{
	posX = 0;
	posY = 353;
	formX = 10;
	formY = 0;
	life = 3;
	jumpHeight = 0;
	typeOfWeapon = 4;
	isJumping = false;
	isSitting = false;
	isAttack = false;
	isWin = false;
	hBitmap_Hear = (HBITMAP)LoadImage(hInst, L"Hear.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBitmap_GameOver = (HBITMAP)LoadImage(hInst, L"GameOver.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBitmap_YouWin = (HBITMAP)LoadImage(hInst, L"YouWin.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBitmap = (HBITMAP)LoadImage(hInst, L"NinjaBoy.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
	hbmMask_GameOver = CreateBitmapMask(hBitmap_GameOver, RGB(255, 0, 255));
	hbmMask_YouWin = CreateBitmapMask(hBitmap_YouWin, RGB(255, 0, 255));
	hbmMask_Hear = CreateBitmapMask(hBitmap_Hear, RGB(255, 0, 255));
	countGameOver = MAP_HEIGHT;
	formXOver = 0;
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

void Character::MoveLeft()
{
	posX = posX - PLAYER_SPEED;
	//change sprite
	if (jumpHeight > 0)
	{
		if (Character::IsGoRight())
		{
			formX = 9;
		}
		else
		{
			if (formX <= 6)
				formX = 9;
			else
				this->formX = this->formX - 1;
		}
	}
	else
	{
		if (Character::IsGoRight())
			formX = 9;
		else
		{
			if (formX <= 1)
				formX = 8;
			else
				this->formX = this->formX - 1;
		}
	}
}

void Character::MoveRight()
{
	posX = posX + PLAYER_SPEED;
	//change sprite
	if (jumpHeight > 0)
	{
		if (Character::IsGoLeft())
		{
			formX = 10;
		}
		else
		{
			if (formX >= 13)
				formX = 10;
			else
				this->formX = this->formX + 1;
		}
	}
	else
	{
		if (Character::IsGoLeft())
			formX = 10;
		else
		{
			if (formX >= 18)
				formX = 11;
			else
				this->formX = this->formX + 1;
		}
	}

}

void Character::MoveUp()
{

	this->isJumping = true;
	if (jumpHeight <= 270)
	{
		jumpHeight += 60;
	}



}

void Character::MoveDown()
{
	if (jumpHeight > 0)
	{
		jumpHeight -= 10;
	}
}

void Character::Draw(HWND hwnd, HDC hdc)
{
	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hbmMask_Hear);
	GetObject(hbmMask_Hear, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		0,
		20,
		HEAR_WIDTH * this->life,
		HEAR_HEIGHT,
		hdcMem,
		HEAR_WIDTH * 0,
		0,
		SRCAND
	);
	oldBitmap = SelectObject(hdcMem, hBitmap_Hear);
	GetObject(hBitmap_Hear, sizeof(bitmap), &bitmap);
	BitBlt
	(
		hdc,
		0,
		20,
		HEAR_WIDTH * this->life,
		HEAR_HEIGHT,
		hdcMem,
		HEAR_WIDTH * 0,
		0,
		SRCPAINT
	);
	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);



	if (this->life >= 0)
	{
		if (this->isWin == true)
		{

			if (countGameOver > 50)
			{
				countGameOver = countGameOver - 3;
			}

			if (formXOver >= 7)
			{
				formXOver = 0;
			}
			else
			{
				formXOver++;
			}


			hdcMem = CreateCompatibleDC(hdc);
			oldBitmap = SelectObject(hdcMem, hbmMask_YouWin);
			GetObject(hbmMask_YouWin, sizeof(bitmap), &bitmap);
			BitBlt
			(
				hdc,
				(1000 - NOTIFICATION_WIDTH) / 2,
				countGameOver,
				NOTIFICATION_WIDTH,
				NOTIFICATION_HEIGHT,
				hdcMem,
				NOTIFICATION_WIDTH * formXOver,
				0,
				SRCAND
			);
			oldBitmap = SelectObject(hdcMem, hBitmap_YouWin);
			GetObject(hBitmap_YouWin, sizeof(bitmap), &bitmap);
			BitBlt
			(
				hdc,
				(1000 - NOTIFICATION_WIDTH) / 2,
				countGameOver,
				NOTIFICATION_WIDTH,
				NOTIFICATION_HEIGHT,
				hdcMem,
				NOTIFICATION_WIDTH * formXOver,
				0,
				SRCPAINT
			);
			SelectObject(hdcMem, oldBitmap);
			DeleteDC(hdcMem);
		}
		else
		{
			if (CheckSitting() == true)
			{
				formY = 2;
			}
			else if (CheckJumping() == false)
			{
				formY = 0;
			}

			hdcMem = CreateCompatibleDC(hdc);
			oldBitmap = SelectObject(hdcMem, hbmMask);
			GetObject(hbmMask, sizeof(bitmap), &bitmap);
			BitBlt
			(
				hdc,
				posX - mapSlider,
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

	}
	else
	{
		if (countGameOver > 50)
		{
			countGameOver = countGameOver - 3;
		}

		if (formXOver >= 7)
		{
			formXOver = 0;
		}
		else
		{
			formXOver++;
		}


		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hbmMask_GameOver);
		GetObject(hbmMask_GameOver, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			(1000 - NOTIFICATION_WIDTH) / 2,
			countGameOver,
			NOTIFICATION_WIDTH,
			NOTIFICATION_HEIGHT,
			hdcMem,
			NOTIFICATION_WIDTH * formXOver,
			0,
			SRCAND
		);
		oldBitmap = SelectObject(hdcMem, hBitmap_GameOver);
		GetObject(hBitmap_GameOver, sizeof(bitmap), &bitmap);
		BitBlt
		(
			hdc,
			(1000 - NOTIFICATION_WIDTH) / 2,
			countGameOver,
			NOTIFICATION_WIDTH,
			NOTIFICATION_HEIGHT,
			hdcMem,
			NOTIFICATION_WIDTH * formXOver,
			0,
			SRCPAINT
		);
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}

}


bool Character::IsGoLeft()
{
	if ((formY != 3) && (formX <= 9))
		return true;
	return false;
}

bool  Character::IsGoRight()
{
	if ((formY != 3) && (formX >= 10))
		return true;
	return false;
}
void Character::SetJump(bool trueOrFalse)
{
	this->isJumping = trueOrFalse;
}

void Character::SetSit(bool trueOrFalse)
{
	this->isSitting = trueOrFalse;
}

bool Character::CheckJumping()
{
	if (jumpHeight > 0)
		this->isJumping = true;
	else
		this->isJumping = false;

	return this->isJumping;
}

bool Character::CheckSitting()
{
	return this->isSitting;
}

void Character::SetJumpHeight(int a_jumpHeight)
{
	this->jumpHeight = a_jumpHeight;
}

void Character::IncreseJumpingHeight(int a)
{
	this->jumpHeight += a;
}

int Character::GetJumpingHeight()
{
	return this->jumpHeight;
}

void Character::SetDeath(bool a_isDead)
{
	this->isDead = a_isDead;
}

bool Character::CheckDeath()
{
	if (this->isDead == true)
	{
		if (IsGoLeft() == true)
		{
			formX = 9;
			formY = 3;
		}
		else if (IsGoRight() == true)
		{
			formX = 10;
			formY = 3;
		}
	}
	return this->isDead;
}

int Character::GetWidth()
{
	return CHARACTER_WIDTH;
}

int Character::GetHeight()
{
	return CHARACTER_HEIGHT;
}

void Character::UpgradeWeapon()
{
	this->typeOfWeapon++;
}

int Character::GetTypeOfWeapon()
{
	return this->typeOfWeapon;
}

void Character::SetTypeOfWeapon(int a_typeOfWeapon)
{
	this->typeOfWeapon = a_typeOfWeapon;
}

int Character::GetPosY()
{
	return (this->posY - this->jumpHeight);
}

void Character::MakeAnimation()
{
	if (this->isDead == true)
	{
		this->jumpHeight += 10;
		if ((this->life >= 0) && (this->jumpHeight >= 400))
		{
			this->posX = this->posX - 200;
			Character::Regeneration();
		}
	}

	if ((this->isDead == false) && (this->jumpHeight) > 0)
	{
		this->jumpHeight -= 5;
	}
}

void Character::Regeneration()
{
	this->posY = 353;
	this->formX = 10;
	this->formY = 0;
	this->jumpHeight = 0;
	this->isJumping = false;
	this->isSitting = false;
	this->isAttack = false;
	this->isDead = false;
	//this->life--;
	this->typeOfWeapon = -1;
}


void Character::IncreseLife(int a_life)
{
	this->life = this->life + a_life;
}

void Character::Win()
{
	this->isWin = true;
}

void Character::IncreseClock()
{
	this->clock = this->clock + 1;
}

int Character::GetClock()
{
	return this->clock;
}

void Character::ResetClock()
{
	this->clock = 0;
}