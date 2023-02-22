#include <bits/stdc++.h>
#include "evaluate.cpp"

using namespace std;

enum {
    white,
    black
};

int minimax (Chessboard chessboard, int depth, int alpha, int beta, int side) {

    if (depth == 0) {
        return evaluate(chessboard);
    }

    long int maxEva, minEva, eva; 

    if (!side) { //MAXIMIZE PLAYER
        maxEva = -(numeric_limits<long int>::infinity());
        for (/* ALL MOVE*/) {
            eva = minimax(/* NEW CHESSBOARD*/, depth-1, alpha, beta, side);
            maxEva = max(maxEva, eva);
            alpha = max(alpha, maxEva);

            if(beta <= alpha) {
                break;
            }
        }
        return maxEva;
    } 
    else { //MINIMIZE PLAYER
        minEva = (numeric_limits<long int>::infinity());
        for (/* ALL MOVE*/) {
            eva = minimax(/* NEW CHESSBOARD*/, depth-1, alpha, beta, !side);
            minEva = min(minEva, eva);
            beta = max(beta, maxEva);

            if(beta <= alpha) {
                break;
            }
        }
        return minEva;
    }
}