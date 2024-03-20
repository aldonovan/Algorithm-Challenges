#include <algorithm>
#include <climits>
#include <iostream>

struct Point {
  int64_t x;
  int64_t y;
};

int FindSign(int64_t value) {
  if (value < 0) return -1;
  if (value == 0) return 0;
  return 1;
}

int64_t Cross(const Point& seg_start, const Point& seg_end, const Point& p) {
  // (p.x - seg_start.x, p.y - seg_start.y)
  // (seg_end.x - seg_start.x, seg_end.y - seg_start.y)

  // Return ad - bc
  return (p.x - seg_start.x) * (seg_end.y - seg_start.y) -
         (p.y - seg_start.y) * (seg_end.x - seg_start.x);
}

// Return -1 if no intersection, 0 if p4 is on (p1, p2), 1 if otherwise
// intersection
int FindAnswer(const Point& p1, const Point& p2, const Point& p3,
               const Point& p4) {
  if (Cross(p1, p2, p4) == 0 &&
      (p4.x >= std::min(p1.x, p2.x) && p4.x <= std::max(p1.x, p2.x) &&
       p4.y >= std::min(p1.y, p2.y) && p4.y <= std::max(p1.y, p2.y))) {
    return 0;
  }

  // Check that p1 and p2 are on opposite sides of p3 and p4, then
  // check the converse as well.
  int result1 = FindSign(Cross(p1, p2, p3)) * FindSign(Cross(p1, p2, p4));
  if (result1 == 1) {
    return -1;
  }
  int result2 = FindSign(Cross(p3, p4, p1)) * FindSign(Cross(p3, p4, p2));
  if (result2 == 1) {
    return -1;
  }
  int x1 = std::min(p1.x, p2.x);
  int x2 = std::max(p1.x, p2.x);
  int y1 = std::min(p1.y, p2.y);
  int y2 = std::max(p1.y, p2.y);
  int x3 = std::min(p3.x, p4.x);
  int x4 = std::max(p3.x, p4.x);
  int y3 = std::min(p3.y, p4.y);
  int y4 = std::max(p3.y, p4.y);
  if (x3 > x2 || x1 > x4 || y3 > y2 || y1 > y4) {
    return -1;
  }
  if (p2.x <= p4.x && p2.y == p4.y) {
    return p1.y > p4.y ? 1 : -1;
  } else if (p1.x <= p4.x && p1.y == p4.y) {
    return p2.y > p4.y ? 1 : -1;
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Point> points;
  int64_t min_x = INT_MAX;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    points.push_back({.x = x, .y = y});
    min_x = std::min(min_x, static_cast<int64_t>(x));
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    Point point = {.x = x, .y = y};
    Point ref_point = {.x = min_x - 1, .y = y};
    bool boundary = false;
    int num_intersections = 0;
    for (int j = 0; j < points.size(); ++j) {
      int value = FindAnswer(points[j], points[(j + 1) % points.size()],
                             ref_point, point);
      if (value == 0) {
        boundary = true;
        break;
      } else if (value == 1) {
        ++num_intersections;
      }
    }
    if (boundary) {
      std::cout << "BOUNDARY" << std::endl;
    } else if (num_intersections % 2 == 0) {
      std::cout << "OUTSIDE" << std::endl;
    } else {
      std::cout << "INSIDE" << std::endl;
    }
  }
}
