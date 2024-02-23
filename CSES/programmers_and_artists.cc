#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
  int a, b, n;
  std::cin >> a >> b >> n;
  std::vector<std::pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int num1, num2;
    std::cin >> num1 >> num2;
    v.emplace_back(num1, num2);
  }
  std::sort(v.begin(), v.end());
  int64_t result = 0;
  int64_t running_sum = 0;
  std::vector<int64_t> results(v.size(), 0);
  std::set<std::pair<int, int>> s;
  for (int elem = 0; elem < a + b; ++elem) {
    int index = v.size() - 1 - elem;
    s.emplace(v[index].first - v[index].second, index);
    running_sum += v[index].first;
    if (static_cast<int>(s.size()) > a) {
      auto& [diff, index] = *s.begin();
      running_sum -= diff;
      s.erase(s.begin());
    }
    if (elem >= a - 1) {
      results[v.size() - elem - 1] = running_sum;
    }
  }
  s.clear();
  std::set<std::pair<int, int>> backup_set;
  int64_t curr_sum = 0;
  for (int index = 0; index + a < v.size(); ++index) {
    s.emplace(v[index].second, index);
    curr_sum += v[index].second;
    int biggest_size =
        std::max(1, index - (static_cast<int>(v.size()) - a - b - 1));
    if (static_cast<int>(s.size()) > biggest_size) {
      auto& [value, index] = *s.begin();
      curr_sum -= value;
      backup_set.emplace(value, index);
      s.erase(s.begin());
    }
    // Compare the top and bottom
    if (!backup_set.empty()) {
      auto& [value, index1] = *backup_set.rbegin();
      auto& [curr_min, index2] = *s.begin();
      if (value > curr_min) {
        curr_sum += value - curr_min;
        backup_set.emplace(curr_min, index2);
        s.erase(s.begin());
        s.emplace(value, index1);
        backup_set.erase(--backup_set.end());
      }
    }
    if (index >= v.size() - a - b && index < v.size() - 1) {
      results[index + 1] += curr_sum;
    }
  }
  std::cout << *std::max_element(results.begin(), results.end()) << '\n';
}
