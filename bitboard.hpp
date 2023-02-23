#include <bits/stdc++.h>

using namespace std;

typedef long long unsigned int Bitboard;

// bits manipulations
#define get_bit(bitboard, square) (bitboard & (1ULL << square))
#define set_bit(bitboard, square) (bitboard |= (1ULL << square))
#define pop_bit(bitboard, square) (get_bit(bitboard, square) ? (bitboard ^= (1ULL << square)) : 0)
#define remove_bit(bitboard, square) (bitboard = bitboard ^ (1ULL << square))


// 1ULL << 2 -> 4  -> 100   -> c8
// 1ULL << 4 -> 16 -> 10000 -> e8

// DEFINE BOARD
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
enum { black, white };


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

};

Bitboard AllWhitePieces(ChessBoard chessboard) {
	return chessboard.WhitePawns | chessboard.WhiteRooks | chessboard.WhiteKnights | chessboard.WhiteBishops | chessboard.WhiteQueens | chessboard.WhiteKing;
}

Bitboard AllBlackPieces(ChessBoard chessboard) {
	return chessboard.BlackPawns | chessboard.BlackRooks | chessboard.BlackKnights | chessboard.BlackBishops | chessboard.BlackQueens | chessboard.BlackKing;
}

Bitboard AllPieces(ChessBoard chessboard) {
	return AllWhitePieces(chessboard) | AllBlackPieces(chessboard);
}

void printBitboard (Bitboard bitboard)
{
    cout << "   +---+---+---+---+---+---+---+---+" << endl;
    
    // RANKS
    for (int rank = 0; rank < 8; rank++)
    {
		cout << 8-rank << "  |";

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

void printChessBoard (ChessBoard chessboard) {

	printBitboard(AllPieces(chessboard));

}

void initializeChessBoard (ChessBoard &chessboard) {

	chessboard.WhitePawns 	= 0x00FF000000000000;
	chessboard.WhiteRooks	= 0x8100000000000000;
	chessboard.WhiteKnights = 0x4200000000000000;
	chessboard.WhiteBishops = 0x2400000000000000;
	chessboard.WhiteQueens	= 0x0800000000000000;
	chessboard.WhiteKing	= 0x1000000000000000;

	chessboard.BlackPawns 	= 0x000000000000FF00;
	chessboard.BlackRooks 	= 0x0000000000000081;
	chessboard.BlackKnights = 0x0000000000000042;
	chessboard.BlackBishops = 0x0000000000000024;
	chessboard.BlackQueens 	= 0x0000000000000008;
	chessboard.BlackKing 	= 0x0000000000000010;
}

const Bitboard ranks[8] = {

    0xFF00000000000000,
    0x00FF000000000000,
    0x0000FF0000000000,
    0x000000FF00000000,
    0x00000000FF000000,
    0x0000000000FF0000,
    0x000000000000FF00,
    0x00000000000000FF
};

const Bitboard files[8] = {

    0x0101010101010101,
    0x0202020202020202,
    0x0404040404040404,
    0x0808080808080808,
    0x1010101010101010,
    0x2020202020202020,
    0x4040404040404040,
    0x8080808080808080
};