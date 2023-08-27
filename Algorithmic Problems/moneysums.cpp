#include <iostream>
#include <set>
using namespace std;
int main() {
  int n;
  cin >> n;
  int coins[n];
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> coins[i];
    sum += coins[i];
  }
  bool sums[sum + 1][n];
  int numSums = 0;
  for(int i = 0; i < n; i++) {
    sums[0][i] = true;
    for(int total = 1; total <= sum; total++) {
      if(i == 0) {
        if(total == coins[i]) {
          numSums++;
          sums[total][i] = true;
        } else {
          sums[total][i] = false;
        }
      } else {
        if(!sums[total][i-1] && coins[i] <= total
           && sums[total-coins[i]][i-1]) {
          sums[total][i] = true;
          numSums++;
        } else {
          sums[total][i] = sums[total][i-1];
        }
      }
    }
  }
  cout << numSums << endl;
  for(int total = 1; total <= sum; total++) {
    if(sums[total][n-1]) {
      cout << total << " ";
    }
  }
  cout << endl;
  return 0;
}
