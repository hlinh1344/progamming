#pragma once
#include "LiveObject.h"
class SpecialItem : public LiveObject
{
protected:
    bool changeDir;
    int value;
public:
    SpecialItem();
    ~SpecialItem();

    int GetValue();
};

