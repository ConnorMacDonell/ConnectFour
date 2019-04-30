/*
 * Board.h
 *
 *  Created on: May 1, 2019
 *      Author: Connor
 */

#include <vector>
#include <iostream>
#include <utility>
#include <stdexcept>

#ifndef BOARD_H_
#define BOARD_H_

enum piece{RED, BLACK, EMPTY};

class connectFourBoard{
public:
	void insertPiece(int col, piece color);
	void display();
	connectFourBoard();
private:
	std::vector<std::vector<piece> > board;
};



#endif /* BOARD_H_ */
