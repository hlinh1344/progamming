#include "BaseObject.h"

BaseObject::BaseObject()
{
	hdcMem = NULL;
	oldBitmap = NULL;
	hbrushOld = NULL;
	hInst = NULL;
	//hBitmap = (HBITMAP)LoadImage(hInst, L"mario.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

BaseObject::~BaseObject()
{

}
