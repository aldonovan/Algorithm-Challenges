#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    // We have f(n) = n^2 + an + b
    // We have f(0) = b -> b must be prime. 
    // Then f(n+1) - f(n) = 2n + 1 + a -> this needs to be even, which implies a is odd.
    // Then n^2 + an = n(n + a) is always even. Thus, we must have b is an odd prime as well.

    vector<int> odd_primes_less_than_1000;
    unordered_set<int> primes = {2};
    for (int i = 3; i < 20000; i += 2) {
        const bool is_prime = std::none_of(primes.begin(), primes.end(), [&](const int prime) {
            return i % prime == 0;
        });
        if (is_prime) {
            primes.insert(i);
            if (i < 1000) {
                odd_primes_less_than_1000.push_back(i);
            }
        }
    }

    int maximum_number_of_primes = 0;
    int corresponding_a = 0;
    int corresponding_b = 0;
    for (int a = -999; a <= 999; a += 2) {
        for (int b : odd_primes_less_than_1000) {
            int curr_candidate = 1;
            while (true) {
                int value = curr_candidate * curr_candidate + a * curr_candidate + b;
                if (primes.contains(value)) {
                    ++curr_candidate;
                } else {
                    break;
                }
            }
            // We found prime values for n in 0 - (curr_candidate - 1), so curr_candidate primes in total 
            if (curr_candidate > maximum_number_of_primes) {
                maximum_number_of_primes = curr_candidate;
                corresponding_a = a;
                corresponding_b = b;
            }
        }
    }
    cout << maximum_number_of_primes << " primes from a = " << corresponding_a << ", b = " << corresponding_b << " is maximal number of primes\n";
    cout << "Product ab = " << corresponding_a*corresponding_b << '\n';
}
