#include <bits/stdc++.h>
#include "board.hpp"

using namespace std;

/*
NOTAZIONE BITBOARD
+-------+-------+-------+-------+-------+
|       | >> 17 |       | >> 15 |       |    
+-------+-------+-------+-------+-------+
| >> 10 |       |       |       | >> 6  |
+-------+-------+-------+-------+-------+
|       |       |   K   |       |       |
+-------+-------+-------+-------+-------+
| << 6  |       |       |       | << 10 |
+-------+-------+-------+-------+-------+
|       | << 15 |       | << 17 |       |
+-------+-------+-------+-------+-------+


VALIDO PER CAVALLI

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

Bitboard knightMove(Bitboard bitboard, int square) {

    Bitboard move = 0ULL;

    Bitboard knight = 0ULL;
    set_bit(knight, square);

    if (knight >> 17 & ~ranks[0] & ~ranks[1] & ~files[7] & ~files[6]) {
        move |= (knight >> 17);
    }

    if (knight >> 15 & ~ranks[0] & ~ranks[1] & ~files[0] & ~files[1]) {
        move |= (knight >> 15);
    }

    if (knight >> 10 & ~ranks[0] & ~ranks[1] & ~files[7] & ~files[6]) {
        move |= (knight >> 10);
    }

    if (knight >> 6 & ~ranks[0] & ~ranks[1] & ~files[0] & ~files[1]) {
        move |= (knight >> 6);
    }

    if (knight << 6 & ~ranks[7] & ~ranks[6] & ~files[7] & ~files[6]) {
        move |= (knight << 6);
    }

    if (knight << 10 & ~ranks[7] & ~ranks[6] & ~files[0] & ~files[1]) {
        move |= (knight << 10);
    }

    if (knight << 15 & ~ranks[7] & ~ranks[6] & ~files[7] & ~files[6]) {
        move |= (knight << 15);
    }

    if (knight << 17 & ~ranks[7] & ~ranks[6] & ~files[0] & ~files[1]) {
        move |= (knight << 17);
    }

    return move;
}

int main() {
    Bitboard bitboard = 0ULL;
    Bitboard result = knightMove(bitboard, d4);
    printBitboard(result);

    //CONTROLLARE VUOTO
    result = knightMove(bitboard, a7);
    printBitboard(result);

    result = knightMove(bitboard, g2);
    printBitboard(result);

    result = knightMove(bitboard, d7);
    printBitboard(result);

    // CONTROLLARE VUOTO
    result = knightMove(bitboard, a8);
    printBitboard(result);
}