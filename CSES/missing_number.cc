#include <iostream>

int main() {
  int64_t n;
  std::cin >> n;
  int64_t sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    int num;
    std::cin >> num;
    sum += num;
  }
  std::cout << n * (n + 1) / 2 - sum << '\n';
}
