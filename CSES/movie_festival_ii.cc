#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> intervals;
  for (int i = 0; i < n; ++i) {
    int start, end;
    cin >> start >> end;
    intervals.emplace_back(start, end);
  }
  sort(intervals.begin(), intervals.end(),
       [](const pair<int, int>& a, const pair<int, int>& b) {
         return a.second < b.second;
       });
  int result = 0;
  multiset<int> s;
  for (const auto& [start, end] : intervals) {
    auto it = s.lower_bound(start + 1);
    if (it != s.begin()) {
      --it;
      s.erase(it);
    }
    if (s.size() < k) {
      ++result;
      s.insert(end);
    }
  }
  cout << result << '\n';
}
