#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int currWhiteRow = 1;
    int currWhiteColumn = 1;
    int currBlackRow = 1;
    int currBlackColumn = 2;
    for(int turn = 1; turn <= n*n; turn++) {
        int a;
        cin >> a;
        if(a == 1) {
            if(currBlackRow <= n) {
                //Writing 2
                cout << 2 << " " << currBlackRow << " " << currBlackColumn << endl;
                cout.flush();
                currBlackColumn += 2;
                if(currBlackColumn > n) {
                    currBlackRow += 1;
                    currBlackColumn = (currBlackColumn % 2) + 1;
                }
            } else {
                //Writing 3
                cout << 3 << " " << currWhiteRow << " " << currWhiteColumn << endl;
                currWhiteColumn += 2;
                if(currWhiteColumn > n) {
                    currWhiteRow += 1;
                    currWhiteColumn = 2 - (currWhiteRow % 2);
                }
            }
        } else {
            if(currWhiteRow <= n) {
                 //Writing 1
                cout << 1 << " " << currWhiteRow << " " << currWhiteColumn << endl;
                cout.flush();
                currWhiteColumn += 2;
                if(currWhiteColumn > n) {
                    currWhiteRow += 1;
                    currWhiteColumn = 2 - (currWhiteRow % 2);
                }
            } else {
                int numToWrite = (a == 2) ? 3 : 2;
                cout << numToWrite << " " << currBlackRow << " " << currBlackColumn << endl;
                cout.flush();
                currBlackColumn += 2;
                if(currBlackColumn > n) {
                    currBlackRow += 1;
                    currBlackColumn = (currBlackColumn % 2) + 1;
                }
            }
        }
    }
    return 0;
}
