#include <bits/stdc++.h>
#include "bitboard.hpp"
#include "board.hpp"

using namespace std;

int promotionWhite (ChessBoard &chessboard) { 

}

int captureWhite (ChessBoard &chessboard) {     

}

int initialMoveWhite (ChessBoard &chessboard) {

}

int intermediateRankWhite (ChessBoard &chessboard, Bitboard bitboard) {

}

int intermediateRankBlack (ChessBoard &chessboard, Bitboard bitboard) {
    
}

int promotionBlack (ChessBoard &chessboard) {   

}

int captureBlack (ChessBoard &chessboard) {    

}

int initialMoveBlack (ChessBoard &chessboard) {

}

int validMoveWhite (ChessBoard &chessboard) { 

    initialMoveWhite(chessboard, chessBoard.WhitePawns | rank[2]);
    
    for (int i=2; i<=6; i++) {
       intermediateRank(chessboard, chessboard.WhitePawns | rank[i]);
    }

    promotionWhite(chessboard, chessboard.WhitePawns | rank[7]);
}

int validMoveBlack (ChessBoard &chessboard) {    

    initialMoveBlack(chessboard, chessboard.BlackPawns | rank[7]);

    for (int i=6; i>=2; i--) {
       intermediateRank(chessboard, chessboard.BlackPawns | rank[i]);
    }

    promotionBlack(chessboard, chessboard.BlackPawns | rank[2]);

}

int pawnMove (ChessBoard &chessboard, int color) { //color = White(0) or Black(1)
    if (color == 0) {
        return validMoveWhite(chessboard);
    }
    else {
        return validMoveBlack(chessboard);
    }
}