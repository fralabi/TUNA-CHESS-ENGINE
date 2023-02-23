#include <bits/stdc++.h>
#include "magics.hpp"

using namespace std;

// vector in cui metteremo tutte le possibili mosse usando il formato Chessboard
void generateMove (vector<ChessBoard>& move, ChessBoard chessboard, int side) {

    Bitboard move2 = 0ULL;

    ChessBoard temp = chessboard;

    if (!side) {

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhitePawns,i) > 0) {
                move2 = pawnMove(AllPieces(chessboard), AllBlackPieces(chessboard), i, side);

                for (int j=0; j<=63; j++) {
                    temp = chessboard;

                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhitePawns, j);
                        remove_bit(temp.WhitePawns, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteRooks,i) > 0) {
                move2 = get_rook_attacks(i, AllPieces(chessboard));

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteRooks, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteBishops,i) > 0) {
                move2 = get_bishop_attacks(i, AllPieces(chessboard));

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhiteBishops, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteKnights,i) > 0) {
                move2 = knightMove(AllPieces(chessboard), i);

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteKnights, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteQueens,i) > 0) {
                move2 = get_bishop_attacks(i, AllPieces(chessboard)) | get_rook_attacks(i, AllPieces(chessboard));

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteQueens, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.WhiteKing,i) > 0) {
                move2 = kingMove(AllPieces(chessboard), i);

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.WhiteKing, j);
                        remove_bit(temp.WhiteKing, i);
                        remove_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackPawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

    }
    else {

        //BLACK
        for (int i=8; i<=55; i++) {
            if(get_bit(chessboard.BlackPawns,i) > 0) {
                move2 = pawnMove(AllPieces(chessboard), AllWhitePieces(chessboard), i, side);

                for (int j=0; j<=63; j++) {
                    temp = chessboard;

                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackPawns, j);
                        remove_bit(temp.BlackPawns, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        //printChessBoard(temp);
                        move.push_back(temp);
                    }
                }
            }
        }
        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackRooks,i) > 0) {
                move2 = get_rook_attacks(i, AllPieces(chessboard));

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackRooks, j);
                        remove_bit(temp.BlackRooks, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackBishops,i) > 0) {
                move2 = get_bishop_attacks(i, AllPieces(chessboard));

                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackBishops, j);
                        remove_bit(temp.BlackBishops, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackKnights,i) > 0) {
                move2 = knightMove(AllPieces(chessboard), i);
                
                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackKnights, j);
                        remove_bit(temp.BlackKnights, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackQueens,i) > 0) {
                move2 = get_bishop_attacks(i, AllPieces(chessboard)) | get_rook_attacks(i, AllPieces(chessboard));
                
                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackQueens, j);
                        remove_bit(temp.BlackQueens, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

        for (int i=0; i<=63; i++) {
            if(get_bit(chessboard.BlackKing,i) > 0) {
                move2 = kingMove(AllPieces(chessboard), i);
                
                for (int j=0; j<=63; j++) {
                    temp = chessboard;
                    if(get_bit(move2,j) > 0) {
                        set_bit(temp.BlackKing, j);
                        remove_bit(temp.BlackKing, i);
                        remove_bit(temp.WhiteQueens, j);
                        remove_bit(temp.WhiteRooks, j);
                        remove_bit(temp.WhiteKnights, j);
                        remove_bit(temp.WhiteBishops, j);
                        remove_bit(temp.WhitePawns, j);
                        move.push_back(temp);
                    }
                }
            }
        }

    }
}

