/*
 * Board.h
 *
 *  Created on: May 1, 2019
 *      Author: Connor
 */

#include <vector>
#include <iostream>
#include <utility>
#include <stack>

#ifndef BOARD_H_
#define BOARD_H_

enum piece{RED, BLACK, EMPTY};

class connectFourBoard{
public:
	void insertPiece(int col, piece color);
	void display();
	connectFourBoard();
	bool isWon(int col);
	piece getSlot(int row, int col);
private:
	std::vector<std::vector<piece> > board;
	bool checkAdjacent(int row, int col, piece color);
	bool checkBelow(int row, int col, piece color);
	bool checkLD(int row, int col, piece color);
	bool checkRD(int row, int col, piece color);
};



#endif /* BOARD_H_ */
