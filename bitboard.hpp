#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned int Bitboard;

// bits manipulations
#define get_bit(bitboard, square) (bitboard & (1ULL << square))
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))
#define pop_bit(bitboard, square) (get_bit(bitboard, square) ? (bitboard ^= (1ULL << square)) : 0)


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

void printChessBoard (ChessBoard chessboard) {

	cout << "   +---+---+---+---+---+---+---+---+" << endl;

	for (int i=7; i>=0; i--) {
		cout << " " << i+1 << " |";
		for (int j=0; j<=7; j++) {
			//CHECK IF Nth BIT IS SET OR NOT
			if (((chessboard.AllPieces >> (j+i*8)) & 1) > 0)
				cout << " X |";
			else
				cout << "   |";
		}
		cout << "\n   +---+---+---+---+---+---+---+---+" << endl;
	}
	cout << "     a   b   c   d   e   f   g   h  " << endl;

}

void printBitboard (Bitboard bitboard)
{
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
    
    // RANKS
    for (int rank = 0; rank < 8; rank++)
    {
		cout << 8-rank << "  | ";

        // FILE
        for (int file = 0; file < 8; file++)
        {
            
            // print bit indexed by board square
			      cout << " " << (get_bit(bitboard, rank * 8 + file) ? "X |" : "  |");
        }
        
        cout << endl << "   +---+---+---+---+---+---+---+---+" << endl;
    }
    
    // print files
    cout << "     a   b   c   d   e   f   g   h  " << endl;
    
    cout << "\nBITBOARD VALUE: " << bitboard << endl << endl;
}

void initializeChessBoard (ChessBoard &chessboard) {

	chessboard.WhitePawns 	= 0x000000000000FF00;
	chessboard.WhiteRooks 	= 0x0000000000000081;
	chessboard.WhiteKnights = 0x0000000000000042;
	chessboard.WhiteBishops = 0x0000000000000024;
	chessboard.WhiteQueens 	= 0x0000000000000010;
	chessboard.WhiteKing 	= 0x0000000000000008;

	chessboard.BlackPawns 	= 0x00FF000000000000;
	chessboard.BlackRooks	= 0x1800000000000000;
	chessboard.BlackKnights = 0x2400000000000000;
	chessboard.BlackBishops = 0x4200000000000000;
	chessboard.BlackQueens	= 0x0100000000000000;
	chessboard.BlackKing	= 0x8000000000000000;

	chessboard.AllBlackPieces = chessboard.BlackPawns | chessboard.BlackRooks | chessboard.BlackKnights | chessboard.BlackBishops | chessboard.BlackQueens | chessboard.BlackKing;
	chessboard.AllWhitePieces = chessboard.WhitePawns | chessboard.WhiteRooks | chessboard.WhiteKnights | chessboard.WhiteBishops | chessboard.WhiteQueens | chessboard.WhiteKing;

	chessboard.AllPieces = chessboard.AllBlackPieces | chessboard.AllWhitePieces;
}