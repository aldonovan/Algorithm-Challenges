#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  string t;
  cin >> s >> t;
  if (t.length() > s.length()) {
    cout << 0 << '\n';
    return 0;
  }
  string combined = t + "#" + s;
  vector<int> lps(combined.length());
  vector<int> matches;
  for (int i = 1; i < combined.length(); ++i) {
    int j = lps[i - 1];
    while (j > 0 && (combined[i] != combined[j] &&
                     (combined[i] != '?' || combined[j] == '#'))) {
      j = lps[j - 1];
    }
    if ((combined[i] == combined[j] || combined[i] == '?') && j != t.length()) {
      ++j;
    }
    if (j == t.length()) {
      matches.push_back(i - 2 * t.length());
    }
    lps[i] = j;
  }
  for (int x : matches) {
    cout << x << " ";
  }
  int longest_proper_prefix = lps[t.length() - 1];
  int result = 0;
  int low_limit = 0;
  for (int match : matches) {
    if (match >= low_limit) {
      ++result;
      low_limit = match + t.length() - longest_proper_prefix;
    }
  }
  cout << result << '\n';
}
