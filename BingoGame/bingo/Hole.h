#pragma once
#include <vector>
class Hole
{
public:
	bool vacancy;
	float r, g, b;
	float x, y;

public:
	Hole();
	~Hole();
	void draw();
	void draw(float x, float y);
	void toPosition(float x, float y);
	void setColor(float red ,float green ,float blue);
	void setPosition(float newx, float newy);
	void getPosition(float & newx, float & newy);
};

