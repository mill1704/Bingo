#include "Hole.h"
#include <cmath>
#include <GL\glut.h>

Hole::Hole() {
	vacancy = false;
	r = 0; 
	g = 0; 
	b = 0;
}

Hole::~Hole()
{
}

void Hole::draw() {
	int nside = 50;
	float radius = 0.4;
	glColor3f(r, g, b);
	glBegin(GL_POLYGON);
	for (int i = 0; i < nside; i++) {
		float pi = 3.14159265;
		float thetar = i * 2.0* pi / nside;
		float x = radius*cos(thetar);
		float y = radius*sin(thetar);
		glVertex2f(x, y);
	}
	glEnd();
}
void Hole::draw(float posx ,float posy){
	glPushMatrix();
	toPosition(posx, posy);
	draw();
	glPopMatrix();
}

void Hole::setColor(float red, float green, float blue) {
	r = red;
	g = green;
	b = blue;
}

void Hole::toPosition(float newx, float newy) {
	glTranslatef(newx, newy, 0);
}

void Hole::setPosition(float newx, float newy) {
	x = newx;
	y = newy;
}

void Hole::getPosition(float & newx, float & newy) {
	newx = x;
	newy = y;
}
