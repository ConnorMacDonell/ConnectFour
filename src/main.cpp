//============================================================================
// Name        : ConnectFour.cpp
// Author      : Connor
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Board.h"

int main() {
	connectFourBoard playSpace;
	playSpace.insertPiece(1, RED);
	playSpace.insertPiece(1, RED);
	playSpace.insertPiece(1, BLACK);
	playSpace.insertPiece(2, BLACK);
	playSpace.insertPiece(5, RED);
	playSpace.insertPiece(6, RED);
	playSpace.insertPiece(2, BLACK);
	playSpace.display();

	return 0;
}
