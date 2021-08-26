#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, k, p;
  cin >> n >> k >> p;
  int people[n];
  for(int i = 0; i < n; i++) {
    cin >> people[i];
  }
  int keys[k];
  for(int i = 0; i < k; i++) {
    cin >> keys[i];
  }
  sort(people, people + n);
  sort(keys, keys + k);
  int minTime = INT_MAX;
  int start = 0;
  while(start + n <= k) {
    int maxDistance = 0;
    for(int i = start; i < start + n; i++) {
      maxDistance = max(maxDistance, abs(people[i - start] - keys[i]) + abs(keys[i] - p));
    }
    minTime = min(minTime, maxDistance);
    start++;
  }
  cout << minTime << endl;
  return 0;
}
