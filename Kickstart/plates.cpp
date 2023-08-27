//Google Kick Start
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int main() {
    int t;
    cin >> t;
    ll n, k, p, beauty;
    for(int i = 1; i <= t; i++) {
        cin >> n >> k >> p;
        ll plateStacks[n][max(k,p)+1];
        for(int j = 0; j < n; j++) {
            ll currSum = 0;
            plateStacks[j][0] = 0;
            for(int l = 1; l <= k; l++) {
                cin >> beauty;
                currSum += beauty;
                plateStacks[j][l] = currSum;
            }
            if(k < p) {
              for(int l = k + 1; l <= p; l++) {
                plateStacks[j][l] = plateStacks[j][k];
              }
            }
        }
        ll answer = plateStacks[0][p];
        for(int index = 1; index < n; index++) {
            ll dp[p + 1];
            dp[0] = 0;
            for(ll num = 1; num <= p; num++) {
              ll maxBeauty = 0;
              for(int m = 0; m <= num; m++) {
                maxBeauty = max(maxBeauty, plateStacks[index][m] + plateStacks[index-1][num-m]);
              }
              dp[num] = maxBeauty;
            }
            for(int i = 1; i <= p; i++) {
              plateStacks[index][i] = dp[i];
            }
            answer = max(answer, plateStacks[index][p]);
        }
        cout << "Case " << i << ": "<< answer << endl;
    }
    return 0;
}
