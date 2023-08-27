#include <iostream>
#include <vector>

// Be careful

int main() {
    int num_coins = 4;
    // int num_coins = 2798; // 3886
    std::vector<std::vector<long long>> num_ways(num_coins+1, std::vector<long long>(num_coins + 1, 1));
    while (true) {
        // All of the sums up to num_coins - 1 can be reused
        for (int number = 2; number <= num_coins; ++number) {
            int lower_bound = (num_coins == 4) ? 0 : num_coins;
            for (int total = num_coins; total >= lower_bound; --total) {
                num_ways[number][total] = num_ways[number-1][total];
                for (int current_contributed = number; current_contributed <= total; current_contributed += number) {
                    num_ways[number][total] = (num_ways[number][total] + num_ways[number-1][total - current_contributed]) % 1'000'000;
                }
            }
        }
        // for (int number = 2; number <= num_coins; ++number) {
        //     for (int total = num_coins; total >= lower_bound; --total) {
        //         for (int current_contributed = number; current_contributed <= total; current_contributed += number) {
        //             num_ways[total] = (num_ways[total] + num_ways[total - current_contributed]) % 1'000'000;
        //         }
        //     }
        // }
        std::cout << num_ways[num_coins][num_coins] << " " << num_coins << '\n';
        if (num_ways[num_coins][num_coins] == 0) {
            std::cout << "The answer is " << num_coins << '\n';
            break;
        }
        // if (num_coins > 10) {
        //     break;
        // }
        ++num_coins;
        num_ways.push_back(num_ways.back());
        for (int number = 1; number <= num_coins; ++number) {
            num_ways[number].push_back(1);
        }
        // num_ways.push_back(1);
    }
}
