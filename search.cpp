#include <bits/stdc++.h>
#include "move.hpp"

using namespace std;

int minimax (ChessBoard chessboard, int depth, long int alpha, long int beta, int side) {

    if (depth == 0) {
        return evaluate(chessboard);
    }

    long int maxEva, minEva, eva; 
    ChessBoard bestMove;

    if (side) { //MAXIMIZE PLAYER
        maxEva = -(numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;

        generateMove(possibleMoves, chessboard, side);

        for (long int i = 0; i < possibleMoves.size(); i++) {
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, side);
            maxEva = max(maxEva, eva);
            if (maxEva == eva) {
                bestMove = possibleMoves[i];
            }
            alpha = max(alpha, maxEva);

            if(beta <= alpha) {
                break;
            }
        }

        if (depth == 3)
            printChessBoard(bestMove);

        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;
        
        generateMove(possibleMoves, chessboard, side);

        for (long int i=0; i < possibleMoves.size(); i++) {
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, side);
            minEva = min(minEva, eva);
            beta = min(beta, minEva);

            if (minEva == eva) {
                bestMove = possibleMoves[i];
            }

            if(beta <= alpha) {
                break;
            }
        }

        
        if (depth == 3)
            printChessBoard(bestMove);

        return minEva;
    }
}

int main() {

    ChessBoard first;
	initializeChessBoard(first);

    cout << minimax(first, 3, -8000000, 8000000, white) << endl;
}