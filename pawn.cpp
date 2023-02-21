#include <bits/stdc++.h>
#include "bitboard.hpp"
#include "board.hpp"

using namespace std;

/*
NOTAZIONE BITBOARD

+----+-----+----+
|    | +16 |    |
+----+-----+----+
| +7 |  +8 | +9 |
+----+-----+----+
| -1 |  0  | +1 |
+----+-----+----+
| -9 |  -8 | -7 |
+----+-----+----+

VALIDO PER PEDONI E RE

PER I PEZZI NERI BASTEREBBE RUOTARE TUTTO DI 180 GRADI E USARE LE STESSE FUNZIONI

*/

// bits manipulations
#define get_bit(bitboard, square) (bitboard & (1ULL << square))
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))
#define pop_bit(bitboard, square) (get_bit(bitboard, square) ? (bitboard ^= (1ULL << square)) : 0)

// define squares
enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1
};

// define sides
enum { white, black };

// pawn_attacks[side][bitboard]
Bitboard pawn_attacks[2][64];

/*
 ~file[0]

  8  0 1 1 1 1 1 1 1
  7  0 1 1 1 1 1 1 1
  6  0 1 1 1 1 1 1 1
  5  0 1 1 1 1 1 1 1
  4  0 1 1 1 1 1 1 1
  3  0 1 1 1 1 1 1 1
  2  0 1 1 1 1 1 1 1
  1  0 1 1 1 1 1 1 1
     a b c d e f g h
*/

/*
 ~file[7]

  8  1 1 1 1 1 1 1 0
  7  1 1 1 1 1 1 1 0
  6  1 1 1 1 1 1 1 0
  5  1 1 1 1 1 1 1 0
  4  1 1 1 1 1 1 1 0
  3  1 1 1 1 1 1 1 0
  2  1 1 1 1 1 1 1 0
  1  1 1 1 1 1 1 1 0
     a b c d e f g h
*/

// bitboard = occupancy board
// square   = position of pawn
Bitboard pawnMove (Bitboard bitboard, int square, int color) {
    
    Bitboard move = 0ULL;

    Bitboard pawn = 0ULL;
    set_bit(pawn, square);

    if (!color) { //WHITE

        //NORD-OVEST
        if (pawn >> 7 & ~files[0] & ~bitboard) {
            move |= (pawn >> 7);
        }

        //NORD-EST
        if (pawn >> 9 & ~files[7] & ~bitboard){
            move |= (pawn >> 9);
        }

        //NORD
        move |= (pawn >> 8 & ~bitboard);

        //NORD NORD if SQUARE is on 2nd RANK

        printBitboard(pawn & ranks[7]);
        printBitboard(ranks[]);

        if ((pawn & ranks[1]) >> 16) {
            move |= (pawn & ranks[1] >> 16);
        }

    }

    else { //BLACK

        //NORD-OVEST
        if (pawn << 7 & ~files[7]) {
            move |= (pawn << 7);
        }

        //NORD-EST
        if (pawn << 9 & ~files[0]){
            move |= (pawn << 9);
        }
    }

    return move;
}

int main() {
    Bitboard bitboard = 0ULL;
    set_bit(bitboard, d4);
    Bitboard result = pawnMove(bitboard, d2, 0);

    printBitboard(result);

    result = pawnMove(bitboard, a2, 0);

    printBitboard(result);
}