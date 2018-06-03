#include "Coin.h"
#include <GL\glut.h>
#include <math.h>


Coin::Coin()
{
	r = 0;
	g = 0;
	b = 0;
	x = 0;
	y = 0;
	yStep = .001;
}

Coin::~Coin()
{
}

void Coin::draw() {
	float pi = 3.14159265;
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.4, 0.4, 0.4);
	glColor3f(r, g, b);
	glBegin(GL_QUAD_STRIP);
	float angel_strip = (2 * pi) / 20;
		for (int i = 0; i <= 20; i++) {
		float x = cos(angel_strip*i);
		float y = sin(angel_strip*i);
		glVertex3f(x, y, 0.5);
		glVertex3f(x, y, -0.5);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	float slice_angle = (2 * pi) / 20;
	glVertex3f(0, 0.5, 0);
	for (int i = 0; i <= 20; i++) {
	float x = cos(slice_angle*i);
	float y = sin(slice_angle*i);
	glVertex3f(x, y, 0.5);

	}
	glEnd();
	glPopMatrix();
}

void Coin::setGrey50() {
	r *= 0.5;
	g *= 0.5;
	b *= 0.5;
}
void Coin::setColor(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void Coin::setPosition(float px, float py) {
	x = px;
	y = py;
}

void Coin::setDropStep(float dropStep) {
	yStep = dropStep;
	
}

float Coin::getDropStep() {
	return yStep;

}

float Coin::getYPosition() {
	return y;
}

void Coin::setYPosition(float py) {
	y = py;
}

Coins::Coins() {

}

Coins::~Coins() {

}
void Coins::add(Coin c) {
	coin.push_back(c);
}
void Coins::draw() {
	for (unsigned i = 0; i < coin.size(); i++) {
		coin[i].draw();
	}
}