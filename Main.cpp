#include <iostream>
#include "Game.h"
#include "GameObject.h"

using namespace std;

int main() {
	UserPlayer player{};
	GameObject block;
	Game game(player,block);
	game.printGameBoard();
	game.playGame();
}
