#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s;
  std::cin >> s;
  std::vector<int> lps(s.length());
  for (int i = 1; i < lps.size(); ++i) {
    int j = lps[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = lps[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    lps[i] = j;
  }
  std::vector<int> border_lengths;
  int border = lps.back();
  while (border > 0) {
    border_lengths.push_back(border);
    border = lps[border - 1];
  }
  for (int i = border_lengths.size() - 1; i >= 0; --i) {
    std::cout << border_lengths[i] << " ";
  }
  std::cout << '\n';
}
