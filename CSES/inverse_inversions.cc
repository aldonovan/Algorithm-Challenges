#include <iostream>

int main() {
  int n;
  int64_t k;
  std::cin >> n >> k;
  int64_t remaining_inversions = k;
  int highest_remaining = n;
  int lowest_remaining = 1;
  int skip = -1;
  for (int i = 0; i < n; ++i) {
    if (remaining_inversions >= highest_remaining - 1) {
      std::cout << highest_remaining << " ";
      --highest_remaining;
      remaining_inversions -= highest_remaining;
    } else if (remaining_inversions > 0) {
      std::cout << remaining_inversions + 1 << " ";
      skip = remaining_inversions + 1;
      remaining_inversions = 0;
    } else {
      if (lowest_remaining == skip) {
        ++lowest_remaining;
      }
      std::cout << lowest_remaining << " ";
      ++lowest_remaining;
    }
  }
  std::cout << '\n';
}