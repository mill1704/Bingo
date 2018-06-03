#pragma once
#include "Hole.h"
#include <vector>
#include "Coin.h"

class Board
{ 
protected:
	float width;
	float height;

public:
	Board();
	~Board();
	virtual void draw();
protected:
	void drawBoard();
};

class BingoBoard : Board {
public:
	static const int nrow = 6;
	static const int ncol = 7;

	
	Coin redcoin, yellowcoin;
	enum Status { red, yellow } status;

public:
	Hole holes[nrow][ncol];
	Coin coinStatus;

public:
	BingoBoard();
	~BingoBoard();
	BingoBoard(float newWidth, float newHeight);
	void draw();
};
