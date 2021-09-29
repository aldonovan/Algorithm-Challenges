#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("cowmbat.in","r",stdin);
	freopen("cowmbat.out","w",stdout);
    // Run Floyd-Warshall to get the true costs between letters
    // Then DP
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int distances[m][m];
    for (int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cin >> distances[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                distances[j][k] = min(distances[j][k], distances[j][i] + distances[i][k]);
            }
        }
    }
    int prefixLetterCosts[n][m];
    for (int letter = 0; letter < m; letter++) {
        for (int index = 0; index < n; index++) {
            prefixLetterCosts[index][letter] = distances[s[index]-'a'][letter];
            if (index > 0) {
                prefixLetterCosts[index][letter] += prefixLetterCosts[index-1][letter];
            }
        }
    }
    int dp[n][m];
    int dpSmallest[n];
    for (int index = 0; index < n; index++) {
        dpSmallest[index] = INT_MAX;
        for (int letter = 0; letter < m; letter++) {
            if (index < 2*k - 1) {
                dp[index][letter] = prefixLetterCosts[index][letter];
            } else {
                dp[index][letter] = prefixLetterCosts[index][letter] - prefixLetterCosts[index-k][letter] + dpSmallest[index-k];
                dp[index][letter] = min(dp[index][letter], dp[index-1][letter] + distances[s[index]-'a'][letter]);
            }
            dpSmallest[index] = min(dpSmallest[index], dp[index][letter]);
        }
    }
    cout << dpSmallest[n-1] << endl;
    return 0;
}
