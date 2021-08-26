#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n;
    int a[2*n];
    int runningSum = 0;
    unordered_map<int, int> balance;
    balance[0] = -1;
    for(int j = 0; j < 2*n; j++) {
      int num;
      cin >> num;
      if(num == 1) {
        runningSum++;
      } else {
        runningSum--;
      }
      if(j < n) balance[runningSum] = j;
      a[j] = runningSum;
    }
    int difference = a[2*n-1];
    int shortest = INT_MAX;
    for(int i = n - 1; i < 2*n; i++) {
      if(balance.count(a[i]-difference)) {
        shortest = min(shortest, i - balance[a[i]-difference]);
      }
    }
    cout << shortest << endl;
  }
  return 0;
}
