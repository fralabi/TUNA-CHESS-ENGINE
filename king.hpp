#include <bits/stdc++.h>
#include "board.hpp"

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

enum {
    a8, b8, c8, d8, e8, f8, g8, h8,  //  0  1  2  3  4  5  6  7
    a7, b7, c7, d7, e7, f7, g7, h7,  //  8  9 10 11 12 13 14 15
    a6, b6, c6, d6, e6, f6, g6, h6,  // 16 17 18 19 20 21 22 24
    a5, b5, c5, d5, e5, f5, g5, h5,  // 24 25 26 27 28 29 30 31
    a4, b4, c4, d4, e4, f4, g4, h4,  // 32 33 34 35 36 37 38 39
    a3, b3, c3, d3, e3, f3, g3, h3,  // 40 41 42 43 44 45 46 47
    a2, b2, c2, d2, e2, f2, g2, h2,  // 48 49 50 51 52 53 54 55
    a1, b1, c1, d1, e1, f1, g1, h1   // 56 57 58 59 60 61 62 63
};
 

// DEFINE SIDES
enum { white, black };

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