#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, m, v1, v2;
  cin >> n >> m;
  vector<int> adj[n+1];
  for(int i = 0; i < m; i++) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  long long maxBeauty = adj[1].size();
  long long beauty[n+1];
  beauty[1] = adj[1].size();
  for(int vertex = 2; vertex <= n; vertex++) {
    long long maxCurr = 1;
    for(int i = 0; i < adj[vertex].size(); i++) {
      int v = adj[vertex][i];
      if(v < vertex) {
        long long tailLength = (adj[v].size() > 0) ? beauty[v]/adj[v].size() : 1;
        maxCurr = max(maxCurr, tailLength + 1);
      }
    }
    beauty[vertex] = maxCurr*adj[vertex].size();
    maxBeauty = max(beauty[vertex], maxBeauty);
  }
  cout << maxBeauty << endl;
  return 0;
}
