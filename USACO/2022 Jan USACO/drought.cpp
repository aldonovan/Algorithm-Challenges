#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int hunger[n];
    for (int i = 0; i < n; i++) {
        cin >> hunger[i];
    }

    if (n == 1) {
        cout <<  hunger[0] + 1 << endl;
        return;
    }

    if (n == 2) {
        cout <<  min(hunger[0], hunger[1]) + 1 << endl;
        return;
    }

    if (hunger[0] > hunger[1]) {
        hunger[0] = hunger[1];
    }

    int values[n][1001];
    int prefixSums[n][1001];
    for (int i = 0; i <= hunger[0]; i++) {
        values[0][i] = i + 1;
        prefixSums[0][i] = i + 1;
        if (i > 0) {
            prefixSums[0][i] += prefixSums[0][i-1];
        }
    }

    for (int i = 0; i <= hunger[1]; i++) {
        values[1][i] = 0;
        if (i <= hunger[0]) {
            values[1][i] = i + 1;
        }
        prefixSums[1][i] = values[1][i];
        if (i > 0) {
            prefixSums[1][i] += prefixSums[1][i-1];
        }
    }

    for (int index = 2; index < n; index++) {
        int currHunger = hunger[index];
        int pastHunger = hunger[index - 1];
        // For given i, we need dp[i-2][max] + dp[i-2][max-1] + ... + dp
        for (int i = 0; i <= currHunger; i++) {
            values[index][i] = 0;
            if (i <= pastHunger) {

            }
        }
    }
    return 0;
}

