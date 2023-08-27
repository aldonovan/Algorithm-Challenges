#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    // In how many ways can twenty 12-sided dice (sides numbered 1 to 12) be rolled so that the top ten sum to 70?

    // First variable: lowest number in the top 10
    // Second variable: number of times this lowest number appears in the top 10
    // Third variable: number of times this lowest number appears below the top 10

    // Given (x, y, z) -> we must also have z = 10 if x = 1
    // Given (x, y, z) -> the number of solutions to this 
    // is (20 choose y + z) * (20 - y - z choose 10 - z) * (max(1,x-1))^(10 - z) * (dp(10 - y, x+1, 70 - xy))
    // Where dp(a, b, c) is the number of ways to choose a variables each >= b that sum to c

    // We have 0 <= a <= 9, 2 <= b <= 12, 0 <= c <= 70

    // (20 choose k) = (20 choose k - 1) * (20 - k + 1) / k 

    vector<vector<vector<long long>>> dp (10, vector<vector<long long>>(13, vector<long long>(71)));
    for (int b = 0; b <= 12; ++b) {
        dp[0][b][0] = 1;
    }
    for (int fixed_b = 2; fixed_b <= 12; ++fixed_b) {
        for (int a = 1; a <= 9; ++a) {
            for (int sum = 70; sum >= 0; --sum) {
                for (int last_variable = fixed_b; last_variable <= min(sum, 12); ++last_variable) {
                    dp[a][fixed_b][sum] += dp[a-1][fixed_b][sum - last_variable];
                }
            }
        }
    }

    vector<vector<int>> combinations(21);
    combinations[0].push_back(1);
    for (int top = 1; top <= 20; ++top) {
        combinations[top].push_back(1);
        for (int k = 1; k <= top; ++k) {
            combinations[top].push_back(combinations[top].back() * (top - k + 1) / k);
        }
    }

    long long total_combinations = 0;
    for (int lowest_number = 1; lowest_number <= 7; ++lowest_number) {
        for (int num_in_top_10 = 1; num_in_top_10 <= 10; ++num_in_top_10) {
            for (int num_in_bottom_10 = 0; num_in_bottom_10 <= 10; ++num_in_bottom_10) {
                if (lowest_number == 1 && num_in_bottom_10 != 10) {
                    continue;
                }
                long long num_ways = combinations[20][num_in_top_10 + num_in_bottom_10] * combinations[20-num_in_top_10-num_in_bottom_10][10 - num_in_top_10];
                num_ways *= llround(pow(max(1, lowest_number - 1), 10 - num_in_bottom_10))*dp[10-num_in_top_10][lowest_number + 1][70 - lowest_number*num_in_top_10];
                total_combinations += num_ways;
            }
        }
    }
    cout << total_combinations << '\n';
}

