#include <bits/stdc++.h>
#include "board.hpp"

using namespace std;

int main() {

    ChessBoard first;
	initializeChessBoard(first);
	printChessBoard(first);

	printBitboard(ranks[0]);
	printBitboard(ranks[1]);
	printBitboard(ranks[2]);
	printBitboard(ranks[3]);
	printBitboard(ranks[4]);
	printBitboard(ranks[5]);
	printBitboard(ranks[6]);
	printBitboard(ranks[7]);

}