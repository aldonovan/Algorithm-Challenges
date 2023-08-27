#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    long long runningChanges[2*m + 2];
    for (int i = 0; i < 2*m + 2; i++) {
        runningChanges[i] = 0;
    }
    long long aCounts[m + 1];
    long long bCounts[m + 1];
    for (int i = 0; i < m + 1; i++) {
        aCounts[i] = 0;
        bCounts[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        aCounts[a]++;
        bCounts[b]++;
    }
    for (int firstValue = 0; firstValue <= m; firstValue++) {
        for (int secondValue = firstValue; secondValue <= m; secondValue++) {
            if (aCounts[firstValue] != 0 && aCounts[secondValue] != 0) {
                if (secondValue == firstValue) {
                    runningChanges[2*firstValue] += aCounts[firstValue]*aCounts[firstValue];
                } else if (secondValue != firstValue) {
                    runningChanges[firstValue + secondValue] += aCounts[firstValue] * aCounts[secondValue] * 2;
                }
            }
            if (bCounts[firstValue] != 0 && bCounts[secondValue] != 0) {
                if (secondValue == firstValue) {
                    runningChanges[2*firstValue + 1] -= bCounts[firstValue]*bCounts[firstValue];
                } else if (secondValue != firstValue) {
                    runningChanges[firstValue + secondValue + 1] -= bCounts[firstValue] * bCounts[secondValue] * 2; 
                }
            }
        }
    }
    long long runningTally = 0;
    for (int k = 0; k <= 2*m; k++) {
        runningTally += runningChanges[k];
        cout << runningTally << endl;
    }
    return 0;
}
