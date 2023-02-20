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

*/

int promotionWhite (ChessBoard &chessboard, Bitboard bitboard) { 

    if (bitboard == 0) {
        return -0xFFFFFFFFFFFFFFFF;
    }

    //CALCOLARE PEZZI IN POSIZIONE +8
}

int captureWhite (ChessBoard &chessboard, Bitboard bitboard) {     

    if (bitboard == 0) {
        return -0xFFFFFFFFFFFFFFFF;
    }

    //CALCOLARE PEZZI IN POSIZIONE +7, +9
}

int initialMoveWhite (ChessBoard &chessboard, Bitboard bitboard) {

    if (bitboard == 0) {
        return -0xFFFFFFFFFFFFFFFF;
    }

    //CALCOLARE PEZZI IN POSIZIONE +7, +8, +9, +16
}

int intermediateRankWhite (ChessBoard &chessboard, Bitboard bitboard) {

    if (bitboard == 0) {
        return -0xFFFFFFFFFFFFFFFF;
    }

    //CALCOLARE PEZZI IN POSIZIONE +7, +8, +9
}

int intermediateRankBlack (ChessBoard &chessboard, Bitboard bitboard) {
    
}

int promotionBlack (ChessBoard &chessboard, Bitboard bitboard) {   

}

int captureBlack (ChessBoard &chessboard, Bitboard bitboard) {    

}

int initialMoveBlack (ChessBoard &chessboard, Bitboard bitboard) {

}

int validPawnMoveWhite (ChessBoard &chessboard) { 

    int bestValue = initialMoveWhite(chessboard, chessBoard.WhitePawns & rank[2]);
    
    for (int i=2; i<=6; i++) {
       int value = intermediateRank(chessboard, chessboard.WhitePawns & rank[i]);
       if (value > bestValue) {
            bestValue = value;
       }
    }

    int value = promotionWhite(chessboard, chessboard.WhitePawns & rank[7]);
    if (value > bestValue) {
            bestValue = value;
       }

    return bestValue;
}

int validPawnMoveBlack (ChessBoard &chessboard) {    

    initialMoveBlack(chessboard, chessboard.BlackPawns & rank[7]);

    for (int i=6; i>=2; i--) {
       intermediateRank(chessboard, chessboard.BlackPawns & rank[i]);
    }

    promotionBlack(chessboard, chessboard.BlackPawns & rank[2]);

}

int pawnMove (ChessBoard &chessboard, int color) { //color = White(0) or Black(1)
    if (color == 0) {
        return validMoveWhite(chessboard);
    }
    else {
        return validMoveBlack(chessboard);
    }
}