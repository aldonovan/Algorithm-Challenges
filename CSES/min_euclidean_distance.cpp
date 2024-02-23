#include <stdint.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int64_t, int64_t>> points(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    points[i] = {x, y};
  }
  std::sort(points.begin(), points.end());
  int64_t min_distance = (points[1].first - points[0].first) *
                             (points[1].first - points[0].first) +
                         (points[1].second - points[0].second) *
                             (points[1].second - points[0].second);
  std::set<std::pair<int64_t, int64_t>> current_points;
  int first_index = 0;
  for (const auto& [x, y] : points) {
    int64_t d = std::round(std::sqrt(min_distance)) + 1;
    while (points[first_index].first + d < x) {
      current_points.erase(
          {points[first_index].second, points[first_index].first});
      ++first_index;
    }
    // [y-d, y+d]
    auto it = current_points.lower_bound({y - d, LLONG_MIN});
    while (it != current_points.end()) {
      const auto& [prev_y, prev_x] = *it;
      if (y + d < prev_y) {
        break;
      }
      int64_t curr_distance =
          (x - prev_x) * (x - prev_x) + (y - prev_y) * (y - prev_y);
      min_distance = std::min(min_distance, curr_distance);
      ++it;
    }
    current_points.emplace(y, x);
  }
  std::cout << min_distance << '\n';
}
