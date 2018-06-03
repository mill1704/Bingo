#pragma once
#include "Board.h"
#include "Coin.h"
#include <vector>
class Bingo
{
public:
	BingoBoard bingoBoard;
	Coins coinsRed;
	Coins coinsYellow;
	
	Coin coinCurrent;
	enum Status { red = 0, yellow = 1 }status;
public:
	Bingo();
	~Bingo();
	void draw();
	void setCoinCurrentPosition(float x, float y);
	const int getNumberOfRow();
};

