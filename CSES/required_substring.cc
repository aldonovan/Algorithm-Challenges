#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void solve(const int n, std::string& s) {
  int64_t num_possible_strings = 1;
  for (int i = 1; i <= n; ++i) {
    num_possible_strings = (num_possible_strings * 26) % 1'000'000'007;
  }
  std::vector<int> lps(s.size());
  std::vector<std::unordered_map<int, int>> updates(s.size());
  for (int i = 1; i < lps.size(); ++i) {
    char prev = s[i];
    for (char c = 'A'; c <= 'Z'; ++c) {
      if (c == prev) {
        if (i < lps.size() - 1) {
          updates[i][i + 1] = 1;
        }
        continue;
      }
      int j = lps[i - 1];
      s[i] = c;
      while (j > 0 && s[i] != s[j]) {
        j = lps[j - 1];
      }
      if (s[i] == s[j]) {
        ++j;
      }
      ++updates[i][j];
    }
    s[i] = prev;
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = lps[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    lps[i] = j;
  }
  updates[0][1] = 1;
  updates[0][0] = 25;
  std::vector<int64_t> counts(s.size());
  counts[0] = 1;
  for (int i = 1; i <= n; ++i) {
    std::vector<int64_t> new_counts(s.size());
    for (int j = 0; j < s.size(); ++j) {
      for (const auto& [key, val] : updates[j]) {
        new_counts[key] = (new_counts[key] + val * counts[j]) % 1'000'000'007;
      }
    }
    counts = new_counts;
  }

  int64_t result = num_possible_strings;
  for (int count : counts) {
    result -= count;
    if (result < 0) {
      result += 1'000'000'007;
    }
  }
  std::cout << result << '\n';
}

int main() {
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  solve(n, s);
}
