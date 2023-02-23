#include <bits/stdc++.h>
#include "bitboard.hpp"

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

Bitboard knightMove(Bitboard bitboard, int square) {

    Bitboard move = 0ULL;

    Bitboard knight = 0ULL;
    set_bit(knight, square);

    //NORD NORD OVEST
    if (knight >> 17 & ~ranks[0] & ~ranks[1] & ~files[7]) {
        move |= (knight >> 17);
    }
    //NORD NORD EST
    if (knight >> 15 & ~ranks[0] & ~ranks[1] & ~files[0]) {
        move |= (knight >> 15);
    }
    //NORD OVEST
    if (knight >> 10 & ~ranks[0] & ~files[7] & ~files[6]) {
        move |= (knight >> 10);
    }
    //NORD EST
    if (knight >> 6 & ~ranks[0] & ~files[0] & ~files[1]) {
        move |= (knight >> 6);
    }
    //SUD OVEST
    if (knight << 6 & ~ranks[7] & ~files[7] & ~files[6]) {
        move |= (knight << 6);
    }
    //SUD EST
    if (knight << 10 & ~ranks[7] & ~files[0] & ~files[1]) {
        move |= (knight << 10);
    }
    //SUD SUD OVEST
    if (knight << 15 & ~ranks[7] & ~ranks[6] & ~files[7]) {
        move |= (knight << 15);
    }
    //SUD SUD EST
    if (knight << 17 & ~ranks[7] & ~ranks[6] & ~files[0]) {
        move |= (knight << 17);
    }

    return move;
}

/*
int main() {
    Bitboard bitboard = 0ULL;
    Bitboard result = knightMove(bitboard, d4);
    printBitboard(result);

    result = knightMove(bitboard, a7);
    printBitboard(result);

    result = knightMove(bitboard, g2);
    printBitboard(result);

    result = knightMove(bitboard, d7);
    printBitboard(result);

    result = knightMove(bitboard, a8);
    printBitboard(result);
}
*/