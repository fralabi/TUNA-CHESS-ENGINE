#include <bits/stdc++.h>
#include "pawn.hpp"
#include "king.hpp"
#include "knight.hpp"
#include "magics.hpp"

using namespace std;

enum {
    white,
    black
};

//CAPIRE COME MEMORIZZARE TUTTE LE POSSIBILI MOSSE e COME PASSARLE ALLA FUNZIONE DI RICERCA
// ARRAY DI CHESSBOARD MODIFICATE, CHE CREDO SIA LA COSA PIU' PROBABILE
// CAPIRE SE C'E' UN MODO PER NON MEMORIZZARE MA PASSARE DIRETTAMENTE LE CHESSBOARD ALLA FUNZIONE DI RICERCA
// STILE ITERATOR OR NEXT 
int generateMove (ChessBoard chessboard, int side) {

    Bitboard move = 0ULL;

    if (!side) {

        for (int i=8; i<=55; i++) {
            if(get_bit(chessboard.WhitePawns,i) > 0) {
                move = pawnMove(chessboard.AllPieces, i, side);
            }
        }
        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteRooks,i) > 0) {
                move = get_rook_attacks(i, chessboard.AllPieces);
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteBishops,i) > 0) {
                move = get_bishop_attacks(i, chessboard.AllPieces);
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteKnights,i) > 0) {
                move = knightMove(chessboard.AllPieces, i);
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteQueens,i) > 0) {
                move = get_bishop_attacks(i, chessboard.AllPieces) | get_rook_attacks(i, chessboard.AllPieces);
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteKing,i) > 0) {
                move = kingMove(chessboard.AllPieces, i);
            }
        }

    }
    else {

        //BLACK
        for (int i=8; i<=55; i++) {
            if(get_bit(chessboard.BlackPawns,i) > 0) {
            black += pieceChessBoardValue[blackPawn][i];
            }
        }
        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackRooks,i) > 0) {
            black += pieceChessBoardValue[rook][i];
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackBishops,i) > 0) {
            black += pieceChessBoardValue[bishop][i];
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackKnights,i) > 0) {
            black += pieceChessBoardValue[knight][i];
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackQueens,i) > 0) {
            black += pieceChessBoardValue[queen][i];
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackKing,i) > 0) {
            black += pieceChessBoardValue[blackKing][i];
            }
        }

    }
}

