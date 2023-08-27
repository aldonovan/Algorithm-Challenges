#include <iostream>

int main() {
    long long sum = 1;
    int current_value = 1;
    int current_add = 2;
    // 2000 additional values on the diagonals
    for (int i = 0; i < 500; ++i) {
        for (int j = 0; j < 4; j++) {
            current_value += current_add;
            sum += current_value;
        }
        current_add += 2;
    }
    std::cout << sum << '\n';
}
