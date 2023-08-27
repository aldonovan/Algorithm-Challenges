#include <iostream>
using namespace std;
int main() {
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int octal;
        cin >> octal;
        int binary = 0;
        int multiplier = 1;
        while(octal > 0) {
            int lastBit = octal % 10;
            binary += lastBit*multiplier;
            octal /= 10;
            multiplier *= 8;
        }
        int bits[18];
        for (int i = 0; i < 18; i++) {
            int bit = binary & (1 << i);
            if (bit) {
                bits[i] = 1;
            } else {
                bits[i] = 0;
            }
        }
        int numberOfEmptyCells = 0;
        int rowXTally[3] = {0, 0, 0};
        int rowOTally[3] = {0, 0, 0};
        int colXTally[3] = {0, 0, 0};
        int colOTally[3] = {0, 0, 0};
        int state[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

        bool foundWinner = false;
        for (int i = 0; i <= 8; i++) {
            if (bits[i] == 0) {
                numberOfEmptyCells++;
            } else {
                int rowNumber = i / 3;
                int colNumber = i % 3;
                if (bits[i+9]) {
                    rowXTally[rowNumber]++;
                    colXTally[colNumber]++;
                    state[i] = 1;
                    if (rowXTally[rowNumber] == 3 || colXTally[colNumber] == 3) {
                        cout << "X wins" << endl;
                        foundWinner = true;
                        break;
                    }
                } else {
                    state[i] = 0;
                    rowOTally[rowNumber]++;
                    colOTally[colNumber]++;
                    if (rowOTally[rowNumber] == 3 || colOTally[colNumber] == 3) {
                        cout << "O wins" << endl;
                        foundWinner = true;
                        break;
                    }
                }
            }
        }
        if (!foundWinner) {
            if ((state[0] == 1 && state[4] == 1 && state[8] == 1) || (state[4] == 1 && state[2] == 1 && state[6] == 1)) {
                cout << "X wins" << endl;
                foundWinner = true;
            } else if ((state[0] == 0 && state[4] == 0 && state[8] == 0) || (state[4] == 0 && state[2] == 0 && state[6] == 0)) {
                cout << "O wins" << endl;
                foundWinner = true;
            }
        }
        if (!foundWinner && numberOfEmptyCells == 0) {
            cout << "Cat's" << endl;
        } else if (!foundWinner && numberOfEmptyCells > 0) {
            cout << "In progress" << endl;
        }
    }
    return 0;
}
