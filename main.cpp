#include <bits/stdc++.h>
#include "bitboard.hpp"
#include "magics.hpp"

using namespace std;

int main() {

    ChessBoard first;
	initializeChessBoard(first);
	printChessBoard(first);

	init_sliders_attacks(bishop);
    init_sliders_attacks(rook);

}