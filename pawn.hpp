#include <bits/stdc++.h>
#include "bitboard.hpp"

using namespace std;

/*
NOTAZIONE BITBOARD

+------+-------+------+
|      | >> 16 |      |
+------+-------+------+
| >> 9 | >> 8  | >> 7 |
+------+-------+------+
| >> 1 |   0   | << 1 |
+------+-------+------+
| << 7 | << 8  | << 9 |
+------+-------+------+

VALIDO PER PEDONI E RE

*/

// DEFINE SQUARES
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
// color    = side of the board
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

        //CONTROLLO SUL FATTO CHE SIA IN SECONDA RIGA E CHE LA CASELLA DAVANTI SIA LIBERA
        if ((pawn & ranks[1]) > 0 && get_bit(bitboard, square-8) == 0) {
            move |= (pawn >> 16 & ~bitboard);
        }

    }

    else { //BLACK

        //SUD-EST
        if (pawn << 7 & ~files[0] & ~bitboard) {
            move |= (pawn << 7);
        }

        //SUD-OVEST
        if (pawn << 9 & ~files[7] & ~bitboard){
            move |= (pawn << 9);
        }

        //SUD
        move |= (pawn << 8 & ~bitboard);

        //SUD SUD if SQUARE is on 2nd RANK

        //CONTROLLO SUL FATTO CHE SIA IN SETTIMA RIGA E CHE LA CASELLA DAVANTI SIA LIBERA
        if ((pawn & ranks[6]) > 0 && get_bit(bitboard, square+8) == 0) {
            move |= (pawn << 16 & ~bitboard);
        }
    }

    return move;
}

/* TRY FUNCTIONS
int main() {
    Bitboard bitboard = 0ULL;
    set_bit(bitboard, c6);
    set_bit(bitboard, d3);
    set_bit(bitboard, d4);
    set_bit(bitboard, e3);
    Bitboard result = pawnMove(bitboard, d2, white);

    printBitboard(result);

    result = pawnMove(bitboard, d7, black);

    printBitboard(result);
}
*/