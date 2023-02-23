#include <bits/stdc++.h>
#include "move.hpp"

using namespace std;

int minimax (ChessBoard chessboard, int depth, long int alpha, long int beta, int side, ChessBoard& position) {

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
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, side, position);
            maxEva = max(maxEva, eva);
            if (maxEva == eva) {
                bestMove = possibleMoves[i];
            }
            alpha = max(alpha, maxEva);

            if(beta <= alpha) {
                break;
            }
        }

        position = bestMove;
        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;
        
        generateMove(possibleMoves, chessboard, side);

        for (long int i=0; i < possibleMoves.size(); i++) {
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, side, position);
            minEva = min(minEva, eva);
            beta = min(beta, eva);

            if (minEva == eva) {
                bestMove = possibleMoves[i];
            }

            if(beta <= alpha) {
                break;
            }
        }

        
        position = bestMove;
        return minEva;
    }
}

int main() {

    ChessBoard first;
	initializeChessBoard(first);
    
    ChessBoard position;
    cout << minimax(first, 3, -8000000, 8000000, white, position) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, black, position) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, white, position) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, black, position) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, white, position) << endl;

    printChessBoard(position);



}