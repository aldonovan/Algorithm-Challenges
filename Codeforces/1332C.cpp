#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
  int t, n, k;
  string word;
  cin >> t;
  while(t--) {
    cin >> n >> k >> word;
    int repeats = n / k;
    int answer = 0;
    int first = 0;
    int last = k - 1;
    while(first <= last) {
      int start = first;
      int end = last;
      unordered_map<char,int> letterCounts;
      int most = 0;
      while(start < n && end < n) {
        letterCounts[word[start]]++;
        letterCounts[word[end]]++;
        start += k;
        end += k;
      }
      for(auto& kv: letterCounts) {
        most = max(most, kv.second);
      }
      if(first != last) {
        answer += 2*repeats - most;
      } else {
        answer += repeats - most/2;
      }
      first++;
      last--;
    }
    cout << answer << endl;
  }
  return 0;
}
