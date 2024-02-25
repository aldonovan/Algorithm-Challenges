#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string n;
  std::string m;
  std::cin >> n >> m;
  std::string combined = m + "#" + n;
  std::vector<int> lps(combined.length());
  int num_matches = 0;
  for (int i = 1; i < lps.size(); ++i) {
    int j = lps[i - 1];
    while (j > 0 && combined[i] != combined[j]) {
      j = lps[j - 1];
    }
    if (combined[i] == combined[j]) {
      ++j;
    }
    if (j == m.length()) {
      ++num_matches;
    }
    lps[i] = j;
  }
  std::cout << num_matches << '\n';
}