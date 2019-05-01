/*
 * ConnectFour.cpp
 *
 *  Created on: May 1, 2019
 *      Author: Connor
 */

#include "ConnectFour.h"
#include "Board.h"

void connectFourGame::playGame(){
	std::cout << "Welcome to a new game of Connect Four. Surely you already know the rules of the analog\n"
	"version of the game, here's how this digital version works: \n"
	"1. Red always goes first.\n"
	"2. The game will continue until someone wins, the board is full, or you enter a negative number.\n"
	"3. You will be prompted to enter a number, please enter a number between 0 and 6 indicating which\n"
	"column you wish to play in or any negative number if you're bored. Turns will alternate automatically.\n"
	"以上です。\n";
	takeTurns();
}

void connectFourGame::takeTurns(){
	int count = 0;
	while(turnNumber < 42){
		std::cout << "Please enter a number between 0 and 6 or a negative number to end the game: ";
		int input;
		std::cin >> input;
		std::cout << "\n";
		while(input > 6){
			std::cout << "Please read more carefully and try again: ";
			std::cin >> input;
			std::cout << "\n";
			++count;
			if(count >= 2){
				std::cout << "This won't do. Come back when you feel like cooperating.\n";
				return;
			}
		}
		if(input < 0){
			std::cout << "Fair enough, cya.\n";
			return;
		}
		else if(playSpace.getSlot(0, input) != EMPTY){
			std::cout << "Please play in a column with room. \n";
			++count;
			if(count >= 3){
				std::cout << "This won't do. Come back when you feel like cooperating.\n";
				return;
			}
			--turnNumber;
		}
		else{
			playSpace.insertPiece(input, turnNumber % 2 == 0 ? RED : BLACK);
			playSpace.display();
			count = 0;
			if(playSpace.isWon(input)){
				std:: cout << "Game has been won." << std::endl;
				return;
			}
		}
		++turnNumber;
	}
	std::cout << "Game is a draw";
}


connectFourGame::connectFourGame() : turnNumber(0) {}



