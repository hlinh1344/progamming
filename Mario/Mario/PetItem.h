#pragma once
#include "SpecialItem.h"

#define PET_ITEM_HEIGHT 49
#define PET_ITEM_WIDTH 50

class PetItem : public SpecialItem
{
protected:

public:
    PetItem()
    {
        width = PET_ITEM_WIDTH;
        height = PET_ITEM_HEIGHT;
        posX = 2000;
        posY = 50;
        formX = 0;
        changeDir = false;
        value = 2;
        hBitmap = (HBITMAP)LoadImage(hInst, L"PetItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        hbmMask = CreateBitmapMask(hBitmap, RGB(82, 181, 198));
    }
    PetItem(int a_x)
    {
        width = PET_ITEM_WIDTH;
        height = PET_ITEM_HEIGHT;
        posX = a_x;
        posY = 50;
        formX = 0;
        changeDir = false;
        value = 2;
        hBitmap = (HBITMAP)LoadImage(hInst, L"PetItem.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
        hbmMask = CreateBitmapMask(hBitmap, RGB(82, 181, 198));
    }
    ~PetItem();

    void MakeAnimation() override
    {
        clock++;
        if (clock >= 1)
        {
            clock = 0;
            if (formX == 8)
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
                if (posY >= 80)
                {
                    changeDir = true;
                }
            }
            else if (changeDir == true)
            {
                posY--;
                if (posY <= 30)
                {
                    changeDir = false;
                }
            }

        }

    }
};

