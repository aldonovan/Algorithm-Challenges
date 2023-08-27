#include <iostream>
#include <vector>

// In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

// 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
// It is possible to make £2 in the following way:

// 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
// How many different ways can £2 be made using any number of coins?

int main() {
    const std::vector<int> coin_values = {1, 2, 5, 10, 20, 50, 100, 200};
    std::vector<int> num_ways(201, 1);
    for (int value : coin_values) {
        if (value == 1) {
            continue;
        }
        for (int total = 200; total >= 0; --total) {
            for (int current_contribution = value; current_contribution <= total; current_contribution += value) {
                num_ways[total] += num_ways[total - current_contribution];
            }
        }
    }
    std::cout << "The number of different ways is " << num_ways[200] << '\n';
}
