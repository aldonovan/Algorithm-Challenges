#include <iostream>
#include <utility>

// Edge case to think about: (1, 1) (2, 2), (3, 3) (4, 4)
// Second edge case to think about: (2, 1) (2, 2), (2, 3) (2, 4)

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

bool FindAnswer(const Point& p1, const Point& p2, const Point& p3,
                const Point& p4) {
  // Check that p1 and p2 are on opposite sides of p3 and p4, then
  // check the converse as well.
  int result1 = FindSign(Cross(p1, p2, p3)) * FindSign(Cross(p1, p2, p4));
  if (result1 == 1) {
    return false;
  }
  int result2 = FindSign(Cross(p3, p4, p1)) * FindSign(Cross(p3, p4, p2));
  if (result2 == 1) {
    return false;
  }
  if (result1 != 0 || result2 != 0) {
    return true;
  }
  int x1 = std::min(p1.x, p2.x);
  int x2 = std::max(p1.x, p2.x);
  int y1 = std::min(p1.y, p2.y);
  int y2 = std::max(p1.y, p2.y);
  int x3 = std::min(p3.x, p4.x);
  int x4 = std::max(p3.x, p4.x);
  int y3 = std::min(p3.y, p4.y);
  int y4 = std::max(p3.y, p4.y);
  return !(x3 > x2 || x1 > x4 || y3 > y2 || y1 > y4);
}

void Solve() {
  Point p1, p2, p3, p4;
  int x, y;
  std::cin >> x >> y;
  p1 = Point{.x = x, .y = y};
  std::cin >> x >> y;
  p2 = Point{.x = x, .y = y};
  std::cin >> x >> y;
  p3 = Point{.x = x, .y = y};
  std::cin >> x >> y;
  p4 = Point{.x = x, .y = y};
  bool result = FindAnswer(p1, p2, p3, p4);
  std::cout << (result ? "YES" : "NO") << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    Solve();
  }
}
