#include <bits/stdc++.h>
#include "pawn.hpp"

using namespace std;

/*
NOTAZIONE BITBOARD

+------+-------+------+
| >> 9 | >> 8  | >> 7 |
+------+-------+------+
| >> 1 |   0   | << 1 |
+------+-------+------+
| << 7 | << 8  | << 9 |
+------+-------+------+

VALIDO PER PEDONI E RE

*/

// bitboard = occupancy board + attack board of opponent pieces
// square   = position of king
Bitboard kingMove(Bitboard bitboard, int square) {

    Bitboard move = 0ULL;

    Bitboard king = 0ULL;
    set_bit(king, square);

    //NORD  -> ~ranks[0]
    //SUD   -> ~ranks[7]
    //EST   -> ~files[0]
    //OVEST -> ~files[7]     

    //NORD-OVEST
    if (king >> 9 & ~files[7] & ~ranks[0] & ~bitboard) {
            move |= (king >> 9);
    }
    //NORD
    if (king >> 8 & ~ranks[0] & ~bitboard) {
            move |= (king >> 8);
    }
    //NORD-EST
    if (king >> 7 & ~files[0] & ~ranks[0] & ~bitboard) {
            move |= (king >> 7);
    }
    //OVEST
    if (king >> 1 & ~files[7] & ~bitboard) {
            move |= (king >> 1);
    }
    //EST
    if (king << 1 & ~files[0] & ~bitboard) {
            move |= (king << 1);
    }
    //SUD-OVEST
    if (king << 7 & ~files[7] & ~ranks[7] & ~bitboard) {
            move |= (king << 7);
    }
    //SUD
    if (king << 8 & ~ranks[7] & ~bitboard) {
            move |= (king << 8);
    }
    //SUD-EST
    if (king << 9 & ~files[0] & ~ranks[7] & ~bitboard) {
            move |= (king << 9);
    }

    return move;

}

/* TRY FUNCTIONS
int main() {
    Bitboard bitboard = 0ULL;
    set_bit(bitboard, b7);
    set_bit(bitboard, d2);
    set_bit(bitboard, d4);
    set_bit(bitboard, e3);

    printBitboard(files[7]);
    Bitboard result = kingMove(bitboard, d3);
    printBitboard(result);

    result = kingMove(bitboard, a7);
    printBitboard(result);

    result = kingMove(bitboard, a8);
    printBitboard(result);

    result = kingMove(bitboard, d2);
    printBitboard(result);

    result = kingMove(bitboard, d7);
    printBitboard(result);

    result = kingMove(bitboard, b3);
    printBitboard(result);
}

*/