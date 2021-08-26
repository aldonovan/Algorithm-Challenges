#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int pie[n];
  for(int i = 0; i < n; i++) {
    cin >> pie[i];
  }
  int optimalAmount = pie[n-1];
  int suffixSum = pie[n-1];
  for(int i = n - 2; i >= 0; i--) {
    optimalAmount = max(optimalAmount, pie[i] + suffixSum - optimalAmount);
    suffixSum += pie[i];
  }
  cout << suffixSum - optimalAmount << " " << optimalAmount << endl;
  return 0;
}
