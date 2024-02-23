#include <math.h>

#include <iostream>

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    int n, k;
    std::cin >> n >> k;
    if (k * k < n) {
      std::cout << "IMPOSSIBLE\n";
    } else {
      int length = k;
      int largest_value = 0;
      int remaining_elements = n;
      while (remaining_elements > 0) {
        if (remaining_elements >= length) {
          largest_value += length;
          for (int value = largest_value; value >= largest_value - length + 1;
               --value) {
            std::cout << value << " ";
          }
          remaining_elements -= length;
        } else {
          largest_value = n;
          while (remaining_elements > 0) {
            std::cout << largest_value << " ";
            --largest_value;
            --remaining_elements;
          }
        }
      }
      std::cout << '\n';
    }
  }
}
