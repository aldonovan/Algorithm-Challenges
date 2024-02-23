// 1884C
#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

struct Point {
  int value;
  bool is_right;
  bool touches_left;
  bool touches_right;
};

void SolveTestCase() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Point> points;
  for (int i = 0; i < n; ++i) {
    int left, right;
    std::cin >> left >> right;
    bool touches_left = left == 1;
    bool touches_right = right == m;
    points.push_back(Point{left, false, touches_left, touches_right});
    points.push_back(Point{right, true, touches_left, touches_right});
  }
  std::sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    return std::tie(p1.value, p1.is_right) < std::tie(p2.value, p2.is_right);
  });
  std::unordered_map<int, int> num_segments;
  std::unordered_map<int, int> left_map;
  std::unordered_map<int, int> right_map;
  int running_count = 0;
  int touches_left_running_count = 0;
  int touches_right_running_count = 0;
  for (const Point& point : points) {
    if (!point.is_right) {
      ++running_count;
      if (point.touches_left) {
        ++touches_left_running_count;
      }
      if (point.touches_right) {
        ++touches_right_running_count;
      }
      num_segments[point.value] = running_count;
      left_map[point.value] = touches_left_running_count;
      right_map[point.value] = touches_right_running_count;
    } else {
      if (point.touches_left) {
        --touches_left_running_count;
      }
      if (point.touches_right) {
        --touches_right_running_count;
      }
      --running_count;
    }
  }
  int largest_difference = 0;
  for (const auto& [index, num] : num_segments) {
    int diff = num - std::min(left_map[index], right_map[index]);
    largest_difference = std::max(largest_difference, diff);
  }
  std::cout << largest_difference << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    SolveTestCase();
  }
}
