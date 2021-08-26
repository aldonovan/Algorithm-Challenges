#include <iostream>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int dp[n][n];
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int length = 2; length <= n; length++) {
        for(int startIndex = 0; startIndex <= n - length; startIndex++) {
            int endIndex = startIndex + length - 1;
            if(s[endIndex] == s[endIndex - 1]) {
                dp[startIndex][endIndex] = dp[startIndex][endIndex - 1];
            } else {
                dp[startIndex][endIndex] = dp[startIndex][endIndex-1] + 1;
                for(int medIndex = endIndex - 2; medIndex >= startIndex; medIndex--) {
                    if(s[medIndex] == s[endIndex]) {
                        dp[startIndex][endIndex] = min(dp[startIndex][endIndex], dp[startIndex][medIndex]
                            + dp[medIndex+1][endIndex-1]);
                    }
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}