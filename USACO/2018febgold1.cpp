#include <algorithm>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;
int main() {
  // If we were to fix the max depth of the boots, then we need to get all of
  // the indices <= that depth Then we can go from 0 to n if the max difference
  // between indices is at most d_i
  int n, b;
  ifstream input("snowboots.in");
  input >> n >> b;
  vector<pair<int, int>> depths;
  vector<int> prev(n, -1);
  vector<int> next(n, -1);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      prev[i] = i - 1;
    }
    if (i < n - 1) {
      next[i] = i + 1;
    }
    int depth;
    input >> depth;
    depths.push_back({depth, i});
  }
  sort(depths.begin(), depths.end());
  vector<pair<pair<int, int>, int>> boots;
  for (int i = 0; i < b; i++) {
    int depth, step;
    input >> depth >> step;
    boots.push_back({{depth, step}, i});
  }
  sort(boots.begin(), boots.end());
  vector<int> results(b, 0);
  int depths_index = n - 1;
  int boots_index = b - 1;
  int largest_gap = 1;
  while (depths_index >= 0 && boots_index >= 0) {
    if (boots[boots_index].first.first >= depths[depths_index].first) {
      bool possible = (boots[boots_index].first.second >= largest_gap);
      results[boots[boots_index].second] = possible ? 1 : 0;
      --boots_index;
    } else {
      // Remove index i
      int index = depths[depths_index].second;
      if (index != 0 && index != n - 1) {
        int prev_index = prev[index];
        int next_index = next[index];
        largest_gap = max(largest_gap, next_index - prev_index);
        next[prev_index] = next_index;
        prev[next_index] = prev_index;
      }
      --depths_index;
    }
  }
  while (boots_index >= 0) {
    bool possible = (boots[boots_index].first.second >= largest_gap);
    results[boots[boots_index].second] = possible ? 1 : 0;
    --boots_index;
  }
  ofstream output("snowboots.out");
  for (int i = 0; i < b; ++i) {
    output << results[i] << '\n';
  }
  return 0;
}
