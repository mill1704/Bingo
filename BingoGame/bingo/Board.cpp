#include "board.h"
#include <GL\glut.h>
#include <vector>
#include "coin.h"

void Board::draw() {
	drawBoard();
}

void Board::drawBoard() {
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(-width/2, -height/2.0, 0);
	glVertex3f(width/2, -height/2, 0);
	glVertex3f(width/2, height/2, 0);
	glVertex3f(-width/2, height/2, 0);
	glEnd();
}
Board::Board()
{
	width = 7;
	height = 6;
}

Board::~Board()
{
}

BingoBoard::BingoBoard() {
	width = 8;
	height = 7;
	coinStatus.setPosition(3, 3);
	coinStatus.setColor(1, 0, 0);
	status = Status::red;
	for (int i = 0; i < nrow; i++)
	{
		for (int j = 0; j < ncol; j++)
		{
			holes[i][j].x = i - 3;
			holes[i][j].y = j - 3;
		}
	}
}
BingoBoard::~BingoBoard() {

}
BingoBoard::BingoBoard(float newWidth, float newHeight) {
	width = newWidth;
	height = newHeight;
}
void BingoBoard::draw() {

	drawBoard();
	for (int i = 0; i < nrow; i++) {
		for (int j = 0; j < ncol; j++) {
			glPushMatrix();
			glTranslatef(j-3.0, i-3.0, 0);
			holes[i][j].draw();
			glPopMatrix();
		}
	}

	coinStatus.draw();


}


