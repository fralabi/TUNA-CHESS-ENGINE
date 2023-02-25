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
  0,   0,   0,   0,   0,   0,   0,   0,
500, 500, 500, 500, 500, 500, 500, 500,
200, 200, 300, 300, 300, 300, 200, 200,
 75,  75, 100, 800, 800, 100,  75,  75,
 50,  50, 100, 800, 800, 100,  50,  50,
 40,  40,  50,  50,  50,  50,  40,  40,
 20,  20,  20,  20,  20,  20,  20,  20,
  0,   0,   0,   0,   0,   0,   0,   0
},
// PAWN (BLACK)
{
  0,   0,   0,   0,   0,   0,   0,   0,
 20,  20,  20,  20,  20,  20,  20,  20,
 40,  40,  50,  50,  50,  50,  40,  40,
 50,  50, 100, 800, 800, 100,  50,  50,
 75,  75, 100, 800, 800, 100,  75,  75,
200, 200, 300, 300, 300, 300, 200, 200,
500, 500, 500, 500, 500, 500, 500, 500,
  0,   0,   0,   0,   0,   0,   0,   0
},
// KNIGHT
{
-600, -400, -400, -400, -400, -400, -400, -600,
-200,   75,   75,   75,   75,   75,   75, -200,
 200,   75,  150,  150,  150,  150,   75,  200,
-200,   75,  150,  300,  300,  150,   75, -200,
-200,   75,  150,  300,  300,  150,   75, -200,
-200,   75,  150,  150,  150,  150,   75, -200,
-200,   75,   75,   75,   75,   75,   75, -200,
-600, -400, -400, -400, -400, -400, -400, -600
},
// BISHOP
{
-40, -40,  -40,  -40,  -40,  -40, -40, -40,
-40,  70,   70,   70,   70,   70,  70, -40,
-40,  70,  120,  120,  120,  120,  70, -40,
-40,  70,  120,  170,  170,  120,  70, -40,
-40,  70,  120,  170,  170,  120,  70, -40,
-40,  70,  120,  120,  120,  120,  70, -40,
-40,  70,   70,   70,   70,   70,  70, -40,
-40, -40,  -40,  -40,  -40,  -40, -40, -40
},
// ROOK
{
0, 50, 100, 150, 150, 100, 50, 0,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
0, 50, 100, 150, 150, 100, 50, 0
},
// QUEEN
{
250,  250, 250,  250,  250, 250, 250, 250,
250,  500, 500,  500,  500, 500, 500, 250,
250,  500, 750,  750,  750, 750, 500, 250,
250,  500, 750, 1000, 1000, 750, 500, 250,
250,  500, 750, 1000, 1000, 750, 500, 250,
250,  500, 750,  750,  750, 750, 500, 250,
250,  500, 500,  500,  500, 500, 500, 250,
250,  250, 250,  250,  250, 250, 250, 250
},
// KING (WHITE)
{
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-700, -700, -700, -700, -700, -700, -700, -700,
-200, -200, -500, -500, -500, -500, -200, -200,
 200,  300,  100, -300,  300,  100,  300,  200
},
// KING (BLACK)
{
 200,  300,  100, -300,  300,  100,  300,  200
-200, -200, -500, -500, -500, -500, -200, -200,
-700, -700, -700, -700, -700, -700, -700, -700,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900
}
};

//VALUTAZIONE OGGETTIVA DELLA POSIZIONE INDIPENDENTEMENTE DA CHI HA LA MOSSA
int evaluate (ChessBoard chessboard) {
  int white=0, black=0;

  //WHITE
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhitePawns,i) > 0) {
      white += pieceChessBoardValue[whitePawn][i];
    }
  }
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteRooks,i) > 0) {
      white += pieceChessBoardValue[rook][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteBishops,i) > 0) {
      white += pieceChessBoardValue[bishop][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKnights,i) > 0) {
      white += pieceChessBoardValue[knight][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteQueens,i) > 0) {
      white += pieceChessBoardValue[queen][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKing,i) > 0) {
      white += pieceChessBoardValue[whiteKing][i];
    }
  }

  //BLACK
  for (int i=0; i<=63; i++) {
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

  return white-black;
  
}