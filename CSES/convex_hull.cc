#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Point {
  int64_t x;
  int64_t y;
};

// Returns negative value if p2 is above (ref_point, p1), positive if below, 0
// if along line
int64_t ComparePoints(const Point& ref_point, const Point& p1,
                      const Point& p2) {
  return (p2.x - ref_point.x) * (p1.y - ref_point.y) -
         (p2.y - ref_point.y) * (p1.x - ref_point.x);
}

void Solve(std::vector<Point>& points) {
  // Find point with lowest y coordinate and lowest x coordinate if there are
  // ties.
  auto it = std::min_element(
      points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return std::make_pair(p1.x, p1.y) < std::make_pair(p2.x, p2.y);
      });
  Point ref_point = Point{.x = it->x, .y = it->y};
  points.erase(it);
  std::sort(points.begin(), points.end(),
            [&](const Point& p1, const Point& p2) {
              // Compare (ref_point, p2) to (ref_point, p1)
              int64_t value = ComparePoints(ref_point, p1, p2);
              if (value != 0) {
                return value < 0;
              }
              return (p1.x - ref_point.x) * (p1.x - ref_point.x) +
                         (p1.y - ref_point.y) * (p1.y - ref_point.y) <
                     (p2.x - ref_point.x) * (p2.x - ref_point.x) +
                         (p2.y - ref_point.y) * (p2.y - ref_point.y);
            });
  int index = points.size() - 2;
  while (index >= 0 &&
         ComparePoints(ref_point, points[index], points.back()) == 0) {
    --index;
  }
  std::reverse(points.begin() + index + 1, points.end());

  points.insert(points.begin(), ref_point);
  std::vector<Point> convex_hull;
  for (const Point& point : points) {
    while (convex_hull.size() > 1) {
      const Point& last_point = convex_hull.back();
      const Point& second_to_last_point = convex_hull[convex_hull.size() - 2];
      if (ComparePoints(second_to_last_point, last_point, point) > 0) {
        convex_hull.pop_back();
      } else {
        break;
      }
    }
    convex_hull.push_back(point);
  }

  std::cout << convex_hull.size() << '\n';
  for (const auto& [x, y] : convex_hull) {
    std::cout << x << " " << y << '\n';
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> points;
  for (int i = 0; i < n; ++i) {
    int p1, p2;
    std::cin >> p1 >> p2;
    points.push_back(Point{.x = p1, .y = p2});
  }
  Solve(points);
}
