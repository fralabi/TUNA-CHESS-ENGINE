#include <bits/stdc++.h>
#include "evaluate.hpp"

using namespace std;

//MINIMAX CON ALPHA-BETA PRUNING
int minimax (ChessBoard chessboard, int depth, long int alpha, long int beta, int side, ChessBoard& position, int maximize) {

    if (depth == 0) {
        return evaluate(chessboard);  
    }

    long int maxEva, minEva, eva; 
    ChessBoard bestMove;

    if (maximize) { //MAXIMIZE PLAYER
        maxEva = -(1000000000000);

        vector<ChessBoard> possibleMoves;

        generateMove(possibleMoves, chessboard, side);

        for (long int i = 0; i < possibleMoves.size(); i++) {
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, !side, position, 0); //0 = Minimize
            if (eva > maxEva) {
                bestMove = possibleMoves[i];
            }
            maxEva = max(maxEva, eva);
            alpha = max(alpha, maxEva);

            if(beta <= alpha) {
                break;
            }
        }

        position = bestMove;
        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (1000000000000);

        vector<ChessBoard> possibleMoves;
        
        generateMove(possibleMoves, chessboard, side);

        for (long int i=0; i < possibleMoves.size(); i++) {
            eva = minimax(possibleMoves[i], depth-1, alpha, beta, !side, position, 1); //1 = Maximize
            if (eva < minEva) {
                bestMove = possibleMoves[i];
            }
            minEva = min(minEva, eva);
            beta = min(beta, minEva);

            if(beta <= alpha) {
                break;
            }
        }

        position = bestMove;
        return minEva;
    }
}

int main() {

    ChessBoard first; //POSIZIONE INIZIALE
	initializeChessBoard(first);

    init_sliders_attacks(0);
    init_sliders_attacks(1);
    
    ChessBoard position; //POSIZIONE PARZIALE
    cout << minimax(first, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimax(position, 3, -1000000000000, 1000000000000, black, position, 1) << endl;

    printChessBoard(position);

}
