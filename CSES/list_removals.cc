#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

class BIT {
public:
  explicit BIT(int n) : counts(n + 1, 0) {}
  explicit BIT(const std::vector<int> &elements) {
    counts = std::vector<int>(elements.size() + 1, 0);
    for (int i = 1; i <= elements.size(); ++i) {
      counts[i] += elements[i - 1];
      int next_index = i + (i & -i);
      if (next_index < counts.size()) {
        counts[next_index] += counts[i];
      }
    }
  }
  void add(int index, int val) {
    if (val == 0) {
      return;
    }
    ++index;
    while (index < counts.size()) {
      counts[index] += val;
      index += (index & -index);
    }
  }
  int total(int index) {
    ++index;
    int sum = 0;
    while (index > 0) {
      sum += counts[index];
      index -= (index & -index);
    }
    return sum;
  }
  // Sum for [a, b]
  int query(int a, int b) {
    int result = total(b);
    if (a > 0) {
      result -= total(a - 1);
    }
    return result;
  }

  int IndexWithPrefixSum(int prefix_sum) {
    int highest_power = std::ceil(std::log2(counts.size()));
    int sum = 0;
    int index = 0;
    for (int power = highest_power; power >= 0; --power) {
      if ((index + (1 << power)) < counts.size() &&
          sum + counts[index + (1 << power)] < prefix_sum) {
        sum += counts[index + (1 << power)];
        index += (1 << power);
      }
    }
    return index + 1;
  }

private:
  std::vector<int> counts;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> numbers(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
  }
  BIT tree(std::vector<int>(n, 1));
  std::vector<int> results;
  for (int i = 0; i < n; ++i) {
    int position;
    std::cin >> position;
    int index = tree.IndexWithPrefixSum(position) - 1;
    assert(index >= 0 && index < n);
    results.push_back(numbers[index]);
    tree.add(index, -1);
  }
  for (int num : results) {
    std::cout << num << " ";
  }
  std::cout << '\n';
}
