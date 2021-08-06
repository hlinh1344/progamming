#pragma once
#include "LiveObject.h"
#include "Map.h"
class Item : public LiveObject
{
protected:
    int typeOfWeapn;
    bool isDead;
    int xOriginal;
public:
    Item();
    ~Item();

    int GetTypeOfWeapn();
    bool CheckDeath();
    void MakeAnimation() override;
};

