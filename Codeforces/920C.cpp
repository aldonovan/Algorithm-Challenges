#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  string canSwap;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> canSwap;
  int largestSoFar = -1;
  bool swap = true;
  for(int i = 0; i < n; i++) {
    largestSoFar = max(largestSoFar, a[i]);
    if(i + 1 < largestSoFar && canSwap[i] == '0') {
      swap = false;
      break;
    }
  }
  if(swap) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
