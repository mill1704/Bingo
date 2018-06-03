#pragma once
#include <vector>

class Coin
{
	float r, g, b;	// color
	float x, y;	// position
	float yStep;
	bool move;

public:
	Coin();
	~Coin();
	void draw();
	void setColor(float red,float green,float blue);
	void setGrey50();
	void setPosition(float px, float py);
	void setDropStep(float dropStep);
	float getDropStep();
	float getYPosition();
	void setYPosition(float py);
};

class Coins {
	std::vector<Coin> coin;
public:
	Coins();
	~Coins();
	void add(Coin c);
	void draw();
};
