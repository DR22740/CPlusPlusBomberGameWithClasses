#include "Game.h"
#include "GameObject.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

char gameBoard[10][15];

Game::Game(UserPlayer p_, GameObject b_) {
    // Set the initial values for the game attributes
    playerE = p_;
    blockE = b_;

    // Set the initial values for the game board
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            gameboard[i][j] = blockE.getSymbol();
        }
    }

    // Set the initial location of the player
    playerE.setLocation(0, 0);
    system("Color 0A");
    gameboard[0][0] = playerE.getSymbol();
    // Set the initial locations of the deadly blocks (hardcoded)
    deadBlockLocation[0][0] = 2;
    deadBlockLocation[0][1] = 3;
    deadBlockLocation[1][0] = 4;
    deadBlockLocation[1][1] = 5;
}

void Game::printGameBoard() {
  // Print the game board, with the player's symbol and the
  // deadly blocks' symbols
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      // If the player's location matches the current position,
      // print the player's symbol
      if (playerE.getX() == j && playerE.getY() == i) {
        std::cout << playerE.getSymbol();
      }
      // Otherwise, check if the current position is a deadly block
      // If it is, print the deadly block's symbol
      else {
        bool isDeadBlock = false;
        for (int k = 0; k < numDeadBlock; k++) {
          if (deadBlockLocation[k][0] == j && deadBlockLocation[k][1] == i) {
            std::cout << "-";
            isDeadBlock = true;
            break;
          }
        }
        // If the current position is not a deadly block or the player,
        // print a space
        if (!isDeadBlock) {
          std::cout << "-";
        }
      }
    }
    std::cout << std::endl;
  }

  // Print the bottom border of the game board
  std::cout << std::endl;
}


void Game::playGame() {
    while (true) {
        // Ask the user for input
        cout << "Enter WASD to move or Q to quit: " << endl;
        cout << "You've been hit: " << numHit << " times" << endl;
        char input;
        cin >> input;
        int x = playerE.getX();
        int y = playerE.getY();


        if (y == 10 && x == 4 && bombActive1 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive1 = false;
            numHit += 1;
        }
        else if (y == 4 && x == 2 && bombActive2 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive2 = false;
            numHit += 1;
        }
        else if (y == 6 && x == 2 && bombActive3 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive3 = false;
            numHit += 1;
        }
        else if (y == 5 && x == 2&& bombActive4 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive4 = false;
            numHit += 1;
        }
        else if (y == 3 && x ==  9&& bombActive5 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive5 = false;
            numHit += 1;
        }
        else if (y ==  2&& x ==  8&& bombActive6 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive6 = false;
            numHit += 1;
        }
        else if (y ==  1&& x ==  7&& bombActive7 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive7 = false;
            numHit += 1;
        }
        else if (y ==  7&& x ==  6&& bombActive8 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive8 = false;
            numHit += 1;
        }
        else if (y ==  8 && x ==  4&& bombActive9 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive9 = false;
            numHit += 1;
        }
        else if (y ==  9 && x ==  1&& bombActive10 == true) {
            cout << "You stepped on a bomb!!!" << endl;
            bombActive10 = false;
            numHit += 1;
        }
        // Handle input
        if (input == 'w' || input == 'W') {
            // Move up if the move is valid
             if (withinBorders(playerE.getX(), playerE.getY() - 1)) {
            playerE.setLocation(playerE.getX(), playerE.getY() - 1);
             }
 
        }
        else if (input == 'a' || input == 'A') {
            // Move left if the move is valid
             if (withinBorders(playerE.getX() - 1, playerE.getY())) { 
            playerE.setLocation(playerE.getX() - 1, playerE.getY());
             }
        }
        else if (input == 's' || input == 'S') {
            // Move down if the move is valid
             if (withinBorders(playerE.getX(), playerE.getY() + 1)) {
            playerE.setLocation(playerE.getX(), playerE.getY() + 1);
             }
        }
        else if (input == 'd' || input == 'D') {
            // Move right if the move is valid
             if (withinBorders(playerE.getX() + 1, playerE.getY())) {
            playerE.setLocation(playerE.getX() + 1, playerE.getY());
             }
        }
        else if (input == 'q' || input == 'Q') {
            // Quit the game
            return;
        }
        else {
            cout << "Invalid Move" << endl;
        }
        // updates the players location on the gameBoard
        gameBoard[y][x] = playerE.getSymbol();
        // Print the game board
        printGameBoard();
        // Check if the player's move is within the game borders
    // If not, print an error and continue the game
        if (withinBorders(playerE.getX(),playerE.getY())) {
           
        }
        else {
            
            std::cout << "Invalid move! You cannot move outside the game borders." << std::endl;

        }
        // Check if the player has reached the end of the board
        if (playerE.getX() == 14 && playerE.getY() == 9) {
            cout << "You win!" << endl;
            return;
        }
    }
}
bool Game::withinBorders(int x, int y) {
    // Check if the given x and y coordinates are within the game borders
    if (playerE.getX() <= 14 && playerE.getX() >= 0 && playerE.getY() <= 9 && playerE.getY() >= 0) {
        return true;
    }
    else {
        return false;
    }
}