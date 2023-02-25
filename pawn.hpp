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
Bitboard pawnMove (Bitboard bitboard, Bitboard opponent, int square, int color) {
    
    Bitboard move = 0ULL;

    Bitboard pawn = 0ULL;
    set_bit(pawn, square);

    if (color) { //WHITE

        //NORD-OVEST
        if (pawn >> 7 & ~files[0] & opponent) {
            move |= (pawn >> 7);
        }

        //NORD-EST
        if (pawn >> 9 & ~files[7] & opponent){
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
        if (pawn << 7 & ~files[0] & opponent) {
            move |= (pawn << 7);
        }

        //SUD-OVEST
        if (pawn << 9 & ~files[7] & opponent){
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
    //set_bit(bitboard, b3);
    Bitboard result = pawnMove(bitboard, bitboard, a2, white);

    printBitboard(bitboard);
    printBitboard(result);

    result = pawnMove(bitboard, bitboard, d7, black);

    printBitboard(result);
}

*/