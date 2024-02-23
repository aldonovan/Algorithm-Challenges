#include <iostream>
#include <utility>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> dp(s.length());
  std::vector<int> length_counts(s.length() + 1);
  for (int i = 1; i < s.length(); ++i) {
    int j = dp[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = dp[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    dp[i] = j;
    ++length_counts[j];
  }
  length_counts[s.length()] = 1;
  for (int j = s.length(); j > 0; --j) {
    length_counts[dp[j - 1]] += length_counts[j];
  }
  int j = s.length();
  std::vector<std::pair<int, int>> results;
  while (j > 0) {
    results.emplace_back(j, length_counts[j]);
    j = dp[j - 1];
  }
  std::cout << results.size() << '\n';
  for (int i = results.size() - 1; i >= 0; --i) {
    std::cout << results[i].first << " " << results[i].second << '\n';
  }
}
