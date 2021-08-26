#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, q;
  cin >> n;
  long long a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> q;
  sort(a, a + n);
  long long diffs[n-1];
  long long sumDiffs[n-1];
  long long maxDiff = 0;
  for(int i = 0; i < n - 1; i++) {
    diffs[i] = a[i+1] - a[i] - 1;
    maxDiff = max(maxDiff, diffs[i]);
  }
  sort(diffs, diffs + n - 1);
  sumDiffs[n-2] = diffs[n-2];
  for(int i = n - 3; i >= 0; i--) {
    sumDiffs[i] = sumDiffs[i+1] + diffs[i];
  }
  long long smallest = a[0];
  long long largest = a[n-1];
  long long l, r;
  for(int i = 0; i < q; i++) {
    cin >> l >> r;
    long long difference = r - l;
    long long distinct = largest + difference - smallest + 1;
    //Binary search for first index with diff greater than difference
    if(difference < maxDiff) {
      int low = 0;
      int high = n - 2;
      int firstGreater = 0;
      while(low <= high) {
        int mid = low + (high - low)/2;
        if(diffs[mid] <= difference) {
          low = mid + 1;
        } else {
          firstGreater = mid;
          high = mid - 1;
        }
      }
      long long missedElements = sumDiffs[firstGreater] - difference*(n-1-firstGreater);
      distinct -= missedElements;
    }
    cout << distinct << " ";
  }
  return 0;
}
