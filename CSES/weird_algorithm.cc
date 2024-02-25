#include <iostream>

int main() {
  int64_t n;
  std::cin >> n;
  while (true) {
    std::cout << n << " ";
    if (n == 1) {
      break;
    }
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
  std::cout << '\n';
}