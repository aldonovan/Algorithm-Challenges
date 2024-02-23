#include <iostream>
#include <vector>

using namespace std;
int main() {
  // Multiset length t has l_1 + ... + l_n <= t <= r_1 + ... + r_m
  // If any of these appears 0 times -> then we just need to make it that length
  // Otherwise, the possible range of lengths is going to be at most 10^5
  // For each element, we have a minimum number of times we must take it.
  // We should store the remaining capacity in the multiset, the number of
  // additional can be taken without taking the element.

  // Then for a given candidate length, we know the minimum times it must be
  // taken, the minimum sum of lengths, and the number of additional can be
  // taken without taking the element. If this is at least the candidate length,
  // then we simply use the minimum times it can be taken as the candidate
  // anti-beauty. If less, then we add the difference as additional times it
  // must be taken to get the anti-beauty. Then we can try out all candidate
  // length
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      int64_t n, l, r;
      cin >> n >> l >> r;
      vector<int> a(n);
      for (int k = 0; k < n; ++k) {
        cin >> a[k];
      }
      vector<int> c(n);
      int64_t total_elements = 0;
      for (int k = 0; k < n; ++k) {
        cin >> c[k];
        total_elements += c[k];
      }
    }
  }
}
