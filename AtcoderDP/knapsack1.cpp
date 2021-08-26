#include <iostream>
using namespace std;
int main() {
    int n, w;
    cin >> n >> w;
    long long dp[w+1];
    for(int i = 0; i <= w; i++) dp[i] = 0;
    int currNumber, currValue;
    for(int i = 0; i < n; i++) {
        cin >> currNumber >> currValue;
        for(int amount = w; amount >= currNumber; amount--) {
            dp[amount] = max(dp[amount], currValue + dp[amount-currNumber]);
        }
    }
    cout << dp[w] << endl;
    return 0;
}