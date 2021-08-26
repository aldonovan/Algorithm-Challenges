#include <iostream>
#include <map>
using namespace std;
int main() {
  int t, n;
  string path;
  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> n >> path;
    int l = 0;
    int r = n;
    map<pair<int, int>, int> visited;
    pair<int, int> current;
    current.first = 0;
    current.second = 0;
    visited[current] = 0;
    for(int j = 1; j <= n; j++) {
      if(path[j-1] == 'L') current.first--;
      if(path[j-1] == 'R') current.first++;
      if(path[j-1] == 'U') current.second++;
      if(path[j-1] == 'D') current.second--;
      if(visited.count(current)) {
        if(j - visited[current] < r - l + 1) {
          l = visited[current] + 1;
          r = j;
        }
      }
      visited[current] = j;
    }
    if(l == 0) {
      cout << -1 << endl;
    } else {
      cout << l << " " << r << endl;
    }
  }
  return 0;
}
