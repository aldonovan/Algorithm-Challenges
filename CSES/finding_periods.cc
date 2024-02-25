#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> z(s.length());
  int l = 0;
  int r = 0;
  for (int i = 1; i < s.length(); ++i) {
    if (i < r) {
      z[i] = std::min(r - i, z[i - l]);
    }
    while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  std::vector<int> period_lengths = {static_cast<int>(s.length())};
  for (int i = s.length() - 1; i >= 1; --i) {
    if (i + z[i] >= s.length()) {
      period_lengths.push_back(i);
    }
  }
  for (int i = period_lengths.size() - 1; i >= 0; --i) {
    std::cout << period_lengths[i] << " ";
  }
  std::cout << '\n';
}
