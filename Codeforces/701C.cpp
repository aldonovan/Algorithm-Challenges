#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  unordered_set<char> letters;
  for(int i = 0; i < s.length(); i++) {
    letters.insert(s[i]);
  }
  int numLetters = letters.size();
  int shortest = s.length();
  unordered_set<char> currLetters;
  unordered_map<char, int> letterCount;
  int start = 0;
  int end = 0;
  //Proceed with sliding window approach
  while(start < s.length()) {
    while(currLetters.size() < numLetters && end < s.length()) {
      currLetters.insert(s[end]);
      letterCount[s[end]]++;
      end++;
    }
    if(currLetters.size() == numLetters) {
      shortest = min(shortest, end - start);
    }
    if(letterCount[s[start]] == 1) currLetters.erase(s[start]);
    letterCount[s[start]]--;
    start++;
  }
  cout << shortest << endl;
  return 0;
}
