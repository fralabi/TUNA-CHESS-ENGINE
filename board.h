#include <bits/stdc++.h>

const uint64_t ranks[8] = {

    0x00000000000000FF,
    0x000000000000FF00,
    0x0000000000FF0000,
    0x00000000FF000000,
    0x000000FF00000000,
    0x0000FF0000000000,
    0x00FF000000000000,
    0xFF00000000000000
};

const uint64_t files[8] = {

    0x0101010101010101,
    0x0202020202020202,
    0x0404040404040404,
    0x0808080808080808,
    0x1010101010101010,
    0x2020202020202020,
    0x4040404040404040,
    0x8080808080808080
};

void printRankOrFile(int n, int k) { // n = NUMERO DI FILA, k = RANK (0) o FILE (1)

    cout << "\n   +---+---+---+---+---+---+---+---+" << endl;

    for (int i=7; i>=0; i--) {
	cout << " " << i+1 << " |";
		for (int j=0; j<=7; j++) {
			//CHECK IF Nth BIT IS SET OR NOT
            if (k == 0) {
                if ((( ranks[n-1] >> (j+i*8)) & 1) > 0)
                    cout << " X |";
                else
                    cout << "   |"; 
            }
            else {
                if ((( files[n-1] >> (j+i*8)) & 1) > 0)
                    cout << " X |";
                else
                    cout << "   |"; 
            }
		}
		cout << "\n   +---+---+---+---+---+---+---+---+" << endl;
	}
	cout << "     a   b   c   d   e   f   g   h  " << endl;
}