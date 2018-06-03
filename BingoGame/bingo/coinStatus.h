#pragma once
#include <vector>
#include "Coin.h"

class coinStatus
{
	float r, g, b;	// color
	float x, y;	// position

public:
	coinStatus();
	~coinStatus();
	void draw();
	void setColor(float red, float green, float blue);
	void setGrey50();
};

class coinStatus {
	
public:
	coinStatus();
	~coinStatus();
	void draw();
};

class coinStatus
{
public:
	coinStatus();
	~coinStatus();
};
