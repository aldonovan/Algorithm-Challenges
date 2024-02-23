#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> units(m, 0);
  std::vector<std::vector<int>> num_ways(n + 2, std::vector<int>(m + 2, 0));
  std::vector<std::vector<int>> width_adjusted(n + 2,
                                               std::vector<int>(m + 2, 0));
  for (int i = 0; i < n; ++i) {
    std::string row;
    std::cin >> row;
    std::stack<int> indices;
    for (int j = 0; char c : row) {
      if (c == '.') {
        ++units[j];
      } else {
        units[j] = 0;
      }
      while (!indices.empty() && units[indices.top()] > units[j]) {
        int index = indices.top();
        indices.pop();
        if (!indices.empty() && units[indices.top()] == units[index]) {
          continue;
        }
        int start_index = indices.empty() ? 0 : indices.top() + 1;
        int min_height = units[j] + 1;
        if (!indices.empty()) {
          min_height = std::max(min_height, units[indices.top()] + 1);
        }
        // std::cout << j - start_index + 1 << '\n';
        // start_index to i - 1, height units[i] + 1 to units[index]
        // units[i] + 1 <= height <= units[index]
        // 1 <= width <= i - start_index
        // Counted i - start_index - width + 1 times
        num_ways[min_height][1] += j - start_index + 1;
        num_ways[min_height][j - start_index + 1] -= j - start_index + 1;
        num_ways[units[index] + 1][1] -= j - start_index + 1;
        num_ways[units[index] + 1][j - start_index + 1] += j - start_index + 1;

        width_adjusted[min_height][1] += -1;
        width_adjusted[min_height][j - start_index + 1] -= -1;
        width_adjusted[units[index] + 1][1] -= -1;
        width_adjusted[units[index] + 1][j - start_index + 1] += -1;
      }
      indices.push(j);
      ++j;
    }
    // Process remaining values
    int j = m;
    while (!indices.empty() && units[indices.top()] > 0) {
      int index = indices.top();
      indices.pop();
      if (!indices.empty() && units[indices.top()] == units[index]) {
        continue;
      }
      int start_index = indices.empty() ? 0 : indices.top() + 1;
      int min_height = indices.empty() ? 1 : units[indices.top()] + 1;
      // start_index to i - 1, height units[i] + 1 to units[index]
      //  <= height <= units[index]
      // 1 <= width <= i - start_index
      // Counted i - start_index - width + 1 times
      num_ways[min_height][1] += j - start_index + 1;
      num_ways[min_height][j - start_index + 1] -= j - start_index + 1;
      num_ways[units[index] + 1][1] -= j - start_index + 1;
      num_ways[units[index] + 1][j - start_index + 1] += j - start_index + 1;

      width_adjusted[min_height][1] += -1;
      width_adjusted[min_height][j - start_index + 1] -= -1;
      width_adjusted[units[index] + 1][1] -= -1;
      width_adjusted[units[index] + 1][j - start_index + 1] += -1;
    }
  }
  std::vector<std::vector<int>> results(n + 2, std::vector<int>(m + 2, 0));
  std::vector<int> running_array(m + 2);
  for (int i = 1; i <= n; ++i) {
    int running_sum = 0;
    for (int j = 1; j <= m; ++j) {
      //   std::cout << num_ways[i][j] << '\n';
      running_array[j] += num_ways[i][j];
      running_sum += running_array[j];
      results[i][j] += running_sum;
      //   std::cout << results[i][j] << " ";
    }
    // std::cout << '\n';
  }

  std::vector<int> width_running_array(m + 2);
  for (int i = 1; i <= n; ++i) {
    int running_sum = 0;
    for (int j = 1; j <= m; ++j) {
      //   std::cout << width_adjusted[i][j] << '\n';
      width_running_array[j] += width_adjusted[i][j];
      running_sum += width_running_array[j];
      results[i][j] += running_sum * j;
      std::cout << results[i][j] << " ";
    }
    std::cout << '\n';
  }
}
