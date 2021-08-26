#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  //Using recursion, comb(n) = comb(n-1) + comb(n-2) + ... + comb(n-6)
  int comb[n+1];
  comb[0] = 1;
  int runningSum = 1;
  for(int i = 1; i <= n; i++) {
    comb[i] = runningSum;
    runningSum += comb[i];
    if(i >= 6) {
      runningSum -= comb[i-6];
    }
    runningSum = runningSum % 1000000007;
    if(runningSum < 0) runningSum += 1000000007;
  }
  cout << comb[n] << endl;
  return 0;
}
