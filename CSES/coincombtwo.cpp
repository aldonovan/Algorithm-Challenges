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
  for(int i = 0; i < n; i++) {
    if(i == 0) {
      for(int total = 1; total <= x; total++) {
        ways[total] = 0;
      }
    }
    for(int total = coins[i]; total <= x; total++) {
      ways[total] += ways[total-coins[i]];
      ways[total] = ways[total] % 1000000007;
    }
  }
  cout << ways[x] << endl;
  return 0;
}
