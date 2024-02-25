#include <iostream>

std::string duval(const std::string& s) {
  int n = s.size();
  int i = 0;
  int answer = 0;
  while (i < n / 2) {
    answer = i;
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j]) {
        k = i;
      } else {
        ++k;
      }
      ++j;
    }
    while (i <= k) {
      i += j - k;
    }
  }
  return s.substr(answer, n / 2);
}

int main() {
  std::string s;
  std::cin >> s;
  s += s;
  std::cout << duval(s) << '\n';
}
