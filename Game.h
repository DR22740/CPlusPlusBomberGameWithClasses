#pragma once
#include "GameObject.h"

class Game {
private:

	int width = 15;
	int height = 10;
	char gameboard[10][15];
	int numDeadBlock = 10;
	char player = 'X';
	char block = '-';
	int numHit = 0;
	int deadBlockLocation[10][2];
	bool running = false;
	int input;
	bool bombActive1 = true;
	bool bombActive2 = true;
	bool bombActive3 = true;
	bool bombActive4 = true;
	bool bombActive5 = true;
	bool bombActive6 = true;
	bool bombActive7 = true;
	bool bombActive8 = true;
	bool bombActive9 = true;
	bool bombActive10 = true;
public:
	GameObject blockE;
	UserPlayer playerE;
	Game(UserPlayer p_, GameObject b_);
	void printGameBoard();
	void playGame();
	bool withinBorders(int x, int y);
};