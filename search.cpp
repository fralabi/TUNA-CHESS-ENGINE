#include <bits/stdc++.h>
#include "evaluate.hpp"

using namespace std;

int minimaxBlack(ChessBoard chessboard, int depth, long int alpha, long int beta, int side, ChessBoard& position, int maximize);

//MINIMAX CON ALPHA-BETA PRUNING
int minimaxWhite (ChessBoard chessboard, int depth, long int alpha, long int beta, int side, ChessBoard& position, int maximize) {

    if (depth == 0) {
        return evaluate(chessboard);   
    }

    long int maxEva, minEva, eva; 
    ChessBoard bestMove;

    if (maximize) { //MAXIMIZE PLAYER
        maxEva = -(numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;

        generateMove(possibleMoves, chessboard, side);

        for (long int i = 0; i < possibleMoves.size(); i++) {
            eva = minimaxWhite(possibleMoves[i], depth-1, alpha, beta, !side, position, 0); //0 = minimize
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
        possibleMoves.clear();
        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;
        
        generateMove(possibleMoves, chessboard, side);

        for (long int i=0; i < possibleMoves.size(); i++) {
            eva = minimaxBlack(possibleMoves[i], depth-1, alpha, beta, !side, position, 1); //1 = Maximize
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
        possibleMoves.clear();
        return minEva;
    }
}

int minimaxBlack (ChessBoard chessboard, int depth, long int alpha, long int beta, int side, ChessBoard& position, int maximize) {

    if (depth == 0) {
        return -evaluate(chessboard);   
    }

    long int maxEva, minEva, eva; 
    ChessBoard bestMove;

    if (maximize) { //MAXIMIZE PLAYER
        maxEva = -(numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;

        generateMove(possibleMoves, chessboard, side);

        for (long int i = 0; i < possibleMoves.size(); i++) {
            eva = minimaxBlack(possibleMoves[i], depth-1, alpha, beta, !side, position, 0); //0 = minimize
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
        possibleMoves.clear();
        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (numeric_limits<long int>::infinity());

        vector<ChessBoard> possibleMoves;
        
        generateMove(possibleMoves, chessboard, side);

        for (long int i=0; i < possibleMoves.size(); i++) {
            eva = minimaxWhite(possibleMoves[i], depth-1, alpha, beta, !side, position, 1); //1 = Maximize
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
        possibleMoves.clear();
        return minEva;
    }
}

int main() {

    ChessBoard first; //POSIZIONE INIZIALE
	initializeChessBoard(first);

    init_sliders_attacks(0);
    init_sliders_attacks(1);
    
    ChessBoard position; //POSIZIONE PARZIALE
    cout << minimaxWhite(first, 2, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimaxBlack(position, 2, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------WHITE----------------------" << endl;

    cout << minimaxWhite(position, 2, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimaxBlack(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

        cout << "----------------------WHITE----------------------" << endl;

    cout << minimaxWhite(position, 3, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimaxBlack(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

        cout << "----------------------WHITE----------------------" << endl;

    cout << minimaxWhite(position, 3, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimaxBlack(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

        cout << "----------------------WHITE----------------------" << endl;

    cout << minimaxWhite(position, 3, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << "----------------------BLACK----------------------" << endl;

    cout << minimaxBlack(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

    /*cout << "----------------------WHITE----------------------" << endl;

    cout << minimaxWhite(position, 1, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    /*printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

        cout << minimax(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, white, position, 1) << endl;

    printChessBoard(position);

    cout << minimax(position, 3, -8000000, 8000000, black, position, 1) << endl;

    printChessBoard(position);*/


}
