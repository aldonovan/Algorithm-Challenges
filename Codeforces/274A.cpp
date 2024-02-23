#include <bits/stdc++.h>

#include <iostream>
#include <unordered_set>
using namespace std;
// Largest k-multiple free subset
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  unordered_set<int> kfree;
  for (int i = 0; i < n; i++) {
    if (a[i] % k != 0 ||
        (a[i] % k == 0 && kfree.find(a[i] / k) == kfree.end())) {
      kfree.insert(a[i]);
    }
  }
  cout << kfree.size() << endl;
  return 0;
}
