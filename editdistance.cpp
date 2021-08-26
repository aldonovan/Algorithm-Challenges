#include <iostream>
#include <vector>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  vector<vector<int> > distance(s1.length() + 1, vector<int>(s2.length() + 1, 0));
  for(int i = 1; i <= s2.length(); i++) {
    distance[0][i] = i;
  }
  for(int i = 1; i <= s1.length(); i++) {
    distance[i][0] = i;
  }
  for(int i = 1; i <= s1.length(); i++) {
    for(int j = 1; j <= s2.length(); j++) {
      if(s1[i-1] == s2[j-1]) {
        distance[i][j] = distance[i-1][j-1];
      } else {
        distance[i][j] = 1 + min(distance[i-1][j-1], min(distance[i-1][j], distance[i][j-1]));
      }
    }
  }
  cout << distance[s1.length()][s2.length()] << endl;
  return 0;
}
