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

bool connectFourBoard::isWon(int col){
	int row = 0;
	while(board[row][col] == EMPTY && row <= 5){
		++row;
	}
	piece color = board[row][col];
	if(checkAdjacent(row, col, color) || checkBelow(row, col, color) ||
			checkRD(row, col, color) || checkLD(row, col, color)){
		return true;
	}
	return false;
}

piece connectFourBoard::getSlot(int row, int col){
	return board[row][col];
}

bool connectFourBoard::checkAdjacent(int row, int col, piece color){
	int count = 0;
	int tempCol = col;
	while(tempCol <= 6 && board[row][tempCol] == color){
		++tempCol;
		++count;
	}
	while(tempCol >= 0 && board[row][tempCol] == color){
		--tempCol;
		++count;
	}
	return count == 4 ? true : false;
}

bool connectFourBoard::checkBelow(int row, int col, piece color){
	if(row < 3){
		return false;
	}
	int count = 0;
	while(row >= 0 && board[row][col] == color){
		++count;
		--row;
	}
	return count == 4 ? true : false;
}

bool connectFourBoard::checkLD(int row, int col, piece color){
	if(row > 2){
		return false;
	}
	int count = 0;
	while(col >= 0 && row <= 5 && board[row][col] == color){
		++count;
		++row;
		--col;
	}
	return count == 4 ? true : false;
}

bool connectFourBoard::checkRD(int row, int col, piece color){
	if(row > 2){
		return false;
	}
	int count = 0;
	while(col <= 6 && row <= 5 && board[row][col] == color){
		++count;
		++row;
		++col;
	}
	return count == 4 ? true : false;
}

