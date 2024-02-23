#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  int i = 0;
  std::vector<int> ids(26, -1);
  for (char c : s) {
    int index = c - 'a';
    if (ids[index] == -1) {
      ids[index] = i++;
    }
  }
  std::vector<int> counts(i, 0);
  std::map<std::vector<int>, int> counts_map = {{counts, 1}};
  int64_t result = 0;
  for (char c : s) {
    ++counts[ids[c - 'a']];
    int smallest = *std::min_element(counts.begin(), counts.end());
    if (smallest > 0) {
      for (int& count : counts) {
        count -= smallest;
      }
    }
    result += counts_map[counts];
    ++counts_map[counts];
  }
  std::cout << result << '\n';
}