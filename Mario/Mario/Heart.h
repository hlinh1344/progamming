#pragma once
#include "LiveObject.h"

#define HEART_ITEM_HEIGHT 69
#define HEART_ITEM_WIDTH 80

class Heart : public LiveObject
{
protected:
    bool isDead;
    bool changeDir;
public:
    Heart()
    {
        width = HEART_ITEM_WIDTH;
        height = HEART_ITEM_HEIGHT;
        posX = 2200;
        posY = 10;
        formX = 0;
        changeDir = false;
        hBitmap = (HBITMAP)LoadImage(hInst, L"HeartItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
    }
    Heart(int a_x)
    {
        width = HEART_ITEM_WIDTH;
        height = HEART_ITEM_HEIGHT;
        posX = a_x;
        posY = 10;
        formX = 0;
        changeDir = false;
        hBitmap = (HBITMAP)LoadImage(hInst, L"HeartItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        hbmMask = CreateBitmapMask(hBitmap, RGB(255, 0, 255));
    }
    ~Heart();

    void MakeAnimation() override
    {
        clock++;
        if (clock >= 6)
        {
            clock = 0;
            if (formX == 4)
            {
                formX = 0;
            }
            else
            {
                formX++;
            }

            if (changeDir == false)
            {
                posY++;
                if (posY >= 35)
                {
                    changeDir = true;
                }
            }
            else if (changeDir == true)
            {
                posY--;
                if (posY <= 10)
                {
                    changeDir = false;
                }
            }
               
        }
       
    }
};

