#pragma once
#include "LiveObject.h"
#include "Map.h"

class Enemy : public LiveObject
{
protected:
	int xOriginal;
	int xArea;
	int yArea;
	int yOriginal;
public:
	Enemy();
	~Enemy();
};

