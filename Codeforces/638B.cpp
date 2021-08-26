#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

string dfs(char c, unordered_map<char, char> outEdges, string answer) {
    if(outEdges.find(c) == outEdges.end()) return answer;
    answer += outEdges[c];
    return dfs(outEdges[c], outEdges, answer);
}

int main() {
  int n;
  cin >> n;
  unordered_map<char, char> outEdges;
  unordered_set<char> hasInEdge;
  unordered_set<char> characters;
  string word, answer;
  for(int i = 0; i < n; i++) {
    cin >> word;
    for(int j = 0; j < word.length(); j++) {
      characters.insert(word[j]);
      if(j >= 1) {
        outEdges[word[j-1]] = word[j];
        hasInEdge.insert(word[j]);
      }
    }
  }
  for(auto& c: characters) {
    if(hasInEdge.find(c) == hasInEdge.end()) {
      answer += c;
      answer = dfs(c, outEdges, answer);
    }
  }
  cout << answer << endl;
  return 0;
}
