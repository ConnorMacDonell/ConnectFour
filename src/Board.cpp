/*
 * Board.cpp
 *
 *  Created on: May 1, 2019
 *      Author: Connor
 */

#include "Board.h"

void connectFourBoard::insertPiece(int col, piece color){
	for(int row = 5; row >= 0; --row){
		if(board[row][col] == EMPTY){
			board[row][col] = color;
			return;
		}
	}
}

void connectFourBoard::display(){
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 7; ++j){
			if(board[i][j] == EMPTY){
				std::cout << 0 << " ";
			}
			else if(board[i][j] == RED){
				std::cout << "R ";
			}
			else{
				std::cout << "B ";
			}
		}
		std::cout << "\n";
	}
}

connectFourBoard::connectFourBoard(){
	std::vector<piece> temp;
	piece inserter = EMPTY;
	for(int i = 0; i < 7; ++i){
		temp.push_back(inserter);
	}
	for(int i = 0; i < 6; ++i){
		board.push_back(temp);
	}
}


