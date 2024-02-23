#include <iostream>
using namespace std;
int main() {
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  int dp[n + 1][m + 2];
  for (int dough = 0; dough <= n; dough++) {
    dp[dough][0] = 0;
  }
  int a, b, c, d, upperLimit;
  for (int i = 1; i <= m + 1; i++) {
    for (int dough = 0; dough <= n; dough++) {
      dp[dough][i] = dp[dough][i - 1];
    }
    if (i <= m) {
      cin >> a >> b >> c >> d;
      upperLimit = min(a / b, n / c);
    } else {
      upperLimit = n / c0;
      c = c0;
      d = d0;
    }
    for (int numBuns = 1; numBuns <= upperLimit; numBuns++) {
      for (int dough = numBuns * c; dough <= n; dough++) {
        dp[dough][i] =
            max(dp[dough][i], dp[dough - numBuns * c][i - 1] + d * numBuns);
      }
    }
  }
  cout << dp[n][m + 1] << endl;
  return 0;
}
