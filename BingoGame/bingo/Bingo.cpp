#include "Bingo.h"

Bingo::Bingo()
{
	status = Status::red;
	coinCurrent.setPosition(0, 0);
	coinCurrent.setColor(1, 0, 0);
}


Bingo::~Bingo()
{
}

void Bingo::draw() 
{
	bingoBoard.draw();
	coinsYellow.draw();
	coinsRed.draw();
	
	coinCurrent.draw();
}

void Bingo::setCoinCurrentPosition(float newX, float newY) 
{
	coinCurrent.setPosition(newX, newY);
}

const int Bingo::getNumberOfRow() {
	return BingoBoard::nrow;
}
