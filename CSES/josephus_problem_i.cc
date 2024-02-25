#include <iostream>

int CalculateAnswer(const int n, const int k) {
  if (n == 1) {
    return 0;
  }
  if (2 * k <= n) {
    return 2 * k - 1;
  }
  int index = CalculateAnswer(n - n / 2, k - n / 2);
  if (index == 0 && n % 2 != 0) {
    return n - 1;
  }
  if (n % 2 != 0) {
    --index;
  }
  return 2 * index;
}

int main() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cout << CalculateAnswer(n, i) + 1 << " ";
  }
  std::cout << '\n';
}
