#include <iostream>
#include <vector>
using namespace std;
int main() {
    // Looking for an O(n^2) DP solution here hopefully 
    // Hmm, wondering how to handle multiply by 0 and multiply by 1 
    // Multiply by 1 seems to keep things constant - wonder if that could just be stripped out from input 
    // Multiply by 0 - we can effectively skip to the last x0 for each string
    // We can represent operation as digit (0-9) or -1 for an addition
    int base = 1000000007;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string b, e;
        cin >> b >> e;
        int bOperations[n];
        int eOperations[n];
        int bLastZero = -1;
        int eLastZero = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] == '+') {
                bOperations[i] = -1;
            } else {
                bOperations[i] = b[i];
                if (b[i] == '0') {
                    bLastZero = i;
                }
            }
            if (e[i] == '+') {
                eOperations[i] = -1;
            } else {
                eOperations[i] = e[i];
                if (e[i] == '0') {
                    eLastZero = i;
                }
            }
        }
        vector<int> bOps;
        vector<int> eOps;
        int startIndex = 0;
        if (bLastZero > -1) {
            startIndex = bLastZero;
        }
        for (int index = startIndex; index < n; index++) {
            if (bOperations[index] != '1') {
                bOps.push_back(bOperations[index]);
            }
        }
        startIndex = 0;
        if (eLastZero > -1) {
            startIndex = eLastZero;
        }
        for (int index = startIndex; index < n; index++) {
            if (eOperations[index] != '1') {
                eOps.push_back(bOperations[index]);
            }
        }
        if (bOps.size() == 0 || eOps.size() == 0) {
            cout << 1 << endl;
            continue;
        }
        if (eOps[0] == '0' && bOps[0] != '0') {
            vector<int> temp = bOps;
            bOps = eOps;
            eOps = temp;
        }
        int m = bOps.size();
        int p = eOps.size();
        vector<int> prevDp(m + 1, 0);
        vector<int> newDp(m + 1, 0);
        prevDp[m] = 1;
        newDp[m] = 1;
        int lastBPlus = -1;
        int lastEPlus = -1;
        for (int eIndex = p - 1; eIndex >= 0; eIndex--) {
            for (int bIndex = m - 1; bIndex >= 0; bIndex--) {
                // Case work here
                if ((eOps[eIndex] == '+' && (bOps[bIndex] >= '2' && bOps[bIndex] <= '9')) || 
                    ((eOps[eIndex] >= '2' && eOps[eIndex] <= '9') && bOps[bIndex] == '+')) {
                    newDp[bIndex] = newDp[bIndex + 1];
                    if (eIndex < p - 1) {
                        newDp[bIndex] += prevDp[bIndex];
                    }
                } else if((eOps[eIndex] >= '2' && eOps[eIndex] <= '9') && (bOps[bIndex] >= '2' && bOps[bIndex] <= '9')) {
                    // Two multiplications case 
                    newDp[bIndex] = newDp[bIndex + 1];
                }
            }
        }
    }
    return 0;
}

