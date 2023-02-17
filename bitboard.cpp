#include <bits/stdc++.h>

typedef uint64_t Bitboard;

struct ChessBoard
{
	/* The white piece positions */
	Bitboard WhitePawns;
	Bitboard WhiteRooks;
	Bitboard WhiteKnights;
	Bitboard WhiteBishops;
	Bitboard WhiteQueens;
	Bitboard WhiteKing;

	/* The black piece positions */
	Bitboard BlackPawns;
	Bitboard BlackRooks;
	Bitboard BlackKnights;
	Bitboard BlackBishops;
	Bitboard BlackQueens;
	Bitboard BlackKing;

	/* Commonly derived positions */
	Bitboard AllWhitePieces;
	Bitboard AllBlackPieces;
	Bitboard AllPieces;
};

int main() {
    
}