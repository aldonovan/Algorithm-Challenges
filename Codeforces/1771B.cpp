#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<int> min_indexes(n, n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            std::cin >> x >> y;
            --x;
            --y;
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            min_indexes[x] = std::min(min_indexes[x], y);
        }
        long long result = 0;
        int min_index = n;
        for (int i = n - 1; i >= 0; --i) {
            min_index = std::min(min_index, min_indexes[i]);
            result += min_index - i;
        }
        std::cout << result << '\n';
    }
}
