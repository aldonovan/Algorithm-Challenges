#include <iostream>
#include <set>
using namespace std;
int main() {
  int n, x, weight;
  cin >> n >> x;
  multiset<int> weights;
  for(int i = 0; i < n; i++) {
    cin >> weight;
    weights.insert(weight);
  }
  int minGondolas = 0;
  while(weights.size() > 0) {
    auto it = weights.upper_bound(x - *weights.rbegin());
    if(it != weights.begin() && it != weights.end()) {
      it--;
      weights.erase(it);
    }
    if(it == weights.end() && weights.size() > 1) {
      it--;
      it--;
      weights.erase(it);
    }
    weights.erase(--weights.end());
    minGondolas++;
  }
  cout << minGondolas << endl;
  return 0;
}
