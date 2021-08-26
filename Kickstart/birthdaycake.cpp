#include <bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int r, c, k, r1, c1, r2, c2;
        cin >> r >> c >> k >> r1 >> c1 >> r2 >> c2;
        int numCols = c2 - c1 + 1;
        int numRows = r2 - r1 + 1;
        int totalSegments = (numCols + 1)*numRows + numCols*(numRows + 1);
        if(c1 == 1) {
            totalSegments -= numRows;
        }
        if(c2 == c) {
            totalSegments -= numRows;
        }
        if(r1 == 1) {
            totalSegments -= numCols;
        }
        if(r2 == r) {
            totalSegments -= numCols;
        }
        int additional = min(r1 - 1, r - r2);
        additional = min(additional, min(c1 - 1, c - c2));
        totalSegments += additional;
        cout << "Case #" << i << ": " << totalSegments << endl;
    }
    return 0;
}