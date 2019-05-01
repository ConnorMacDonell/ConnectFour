/*
 * ConnectFour.h
 *
 *  Created on: May 1, 2019
 *      Author: Connor
 */

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

#include "Board.h"

#ifndef CONNECTFOUR_H_
#define CONNECTFOUR_H_

class connectFourGame{
public:
	void playGame();
	connectFourGame();
private:
	connectFourBoard playSpace;
	void takeTurns();
	int turnNumber;

};



#endif /* CONNECTFOUR_H_ */
