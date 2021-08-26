#include <iostream>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int coins[n];
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  int ways[x+1];
  ways[0] = 1;
  for(int i = 1; i <= x; i++) {
    ways[i] = 0;
    for(int j = 0; j < n; j++) {
      if(coins[j] <= i) {
        ways[i] += ways[i-coins[j]];
        ways[i] = ways[i] % 1000000007;
      }
    }
  }
  cout << ways[x] << endl;
  return 0;
}
