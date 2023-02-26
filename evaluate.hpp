#include <bits/stdc++.h>
#include "move.hpp"

using namespace std;

enum { 
  whitePawn, 
  blackPawn, 
  knight, 
  bishop, 
  rook, 
  queen, 
  whiteKing,
  blackKing
};

const int pieceChessBoardValue [8][64] =
{
// PAWN (WHITE)
{
  0,  0,  0,  0,  0,  0,  0,  0,
  50, 50, 50, 50, 50, 50, 50, 50,
  10, 10, 20, 30, 30, 20, 10, 10,
  5,  5, 10, 45, 45, 10,  5,  5,
  0,  0,  0, 30, 30,  0,  0,  0,
  5, -5,-10,  0,  0,-10, -5,  5,
  5, 10, 10,-20,-20, 10, 10,  5,
  0,  0,  0,  0,  0,  0,  0,  0
},
// PAWN (BLACK)
{
  0,  0,  0,  0,  0,  0,  0,  0,
  5, 10, 10,-20,-20, 10, 10,  5,
  5, -5,-10,  0,  0,-10, -5,  5,
  0,  0,  0, 30, 30,  0,  0,  0,
  5,  5, 10, 45, 45, 10,  5,  5,
  10, 10, 20, 30, 30, 20, 10, 10,
  50, 50, 50, 50, 50, 50, 50, 50,
  0,  0,  0,  0,  0,  0,  0,  0
},
// KNIGHT
{
-50,-40,-30,-30,-30,-30,-40,-50,
-40,-20,  0,  0,  0,  0,-20,-40,
-30,  0, 10, 15, 15, 10,  0,-30,
-30,  5, 15, 20, 20, 15,  5,-30,
-30,  0, 15, 20, 20, 15,  0,-30,
-30,  5, 10, 15, 15, 10,  5,-30,
-40,-20,  0,  5,  5,  0,-20,-40,
-50,-40,-30,-30,-30,-30,-40,-50
},
// BISHOP
{
-20,-10,-10,-10,-10,-10,-10,-20,
-10,  0,  0,  0,  0,  0,  0,-10,
-10,  0,  5, 10, 10,  5,  0,-10,
-10,  5,  5, 10, 10,  5,  5,-10,
-10,  0, 10, 10, 10, 10,  0,-10,
-10, 10, 10, 10, 10, 10, 10,-10,
-10,  5,  0,  0,  0,  0,  5,-10,
-20,-10,-10,-10,-10,-10,-10,-20
},
// ROOK
{
  0,  0,  0,  0,  0,  0,  0,  0,
  5, 10, 10, 10, 10, 10, 10,  5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
 -5,  0,  0,  0,  0,  0,  0, -5,
  0,  0,  0,  5,  5,  0,  0,  0
},
// QUEEN
{
-20,-10,-10, -5, -5,-10,-10,-20,
-10,  0,  0,  0,  0,  0,  0,-10,
-10,  0,  5,  5,  5,  5,  0,-10,
 -5,  0,  5,  5,  5,  5,  0, -5,
  0,  0,  5,  5,  5,  5,  0, -5,
-10,  5,  5,  5,  5,  5,  0,-10,
-10,  0,  5,  0,  0,  0,  0,-10,
-20,-10,-10, -5, -5,-10,-10,-20
},
// KING (WHITE)
{
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-20,-30,-30,-40,-40,-30,-30,-20,
-10,-20,-20,-20,-20,-20,-20,-10,
 20, 20,  0,  0,  0,  0, 20, 20,
 20, 30, 10,  0,  0, 10, 30, 20
},
// KING (BLACK)
{
 20, 30, 10,  0,  0, 10, 30, 20,
 20, 20,  0,  0,  0,  0, 20, 20,
-10,-20,-20,-20,-20,-20,-20,-10,
-20,-30,-30,-40,-40,-30,-30,-20,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30,
-30,-40,-40,-50,-50,-40,-40,-30
}
};

//VALUTAZIONE OGGETTIVA DELLA POSIZIONE INDIPENDENTEMENTE DA CHI HA LA MOSSA
int evaluate (ChessBoard chessboard) {
  int white=0, black=0;

  //WHITE
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhitePawns,i) > 0) {
      white += pieceChessBoardValue[whitePawn][i]*100;
    }
  }
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteRooks,i) > 0) {
      white += pieceChessBoardValue[rook][i]*500;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteBishops,i) > 0) {
      white += pieceChessBoardValue[bishop][i]*330;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKnights,i) > 0) {
      white += pieceChessBoardValue[knight][i]*320;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteQueens,i) > 0) {
      white += pieceChessBoardValue[queen][i]*900;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKing,i) > 0) {
      white += pieceChessBoardValue[whiteKing][i]*20000;
    }
  }

  //BLACK
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackPawns,i) > 0) {
      black += pieceChessBoardValue[blackPawn][i]*100;
    }
  }
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackRooks,i) > 0) {
      black += pieceChessBoardValue[rook][i]*500;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackBishops,i) > 0) {
      black += pieceChessBoardValue[bishop][i]*330;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackKnights,i) > 0) {
      black += pieceChessBoardValue[knight][i]*320;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackQueens,i) > 0) {
      black += pieceChessBoardValue[queen][i]*900;
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackKing,i) > 0) {
      black += pieceChessBoardValue[blackKing][i]*20000;
    }
  }

  return white-black;
  
}