#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int main() {
  //Unweighted undirected connected graph
  //Idea: Run BFS for all k goods -> O(n+m) since k <= 100
  int n, m, k, s, good, v1, v2, sum;
  cin >> n >> m >> k >> s;
  vector<int> goods[k+1];
  vector<int> adj[n+1];
  for(int i = 1; i <= n; i++) {
    cin >> good;
    goods[good].push_back(i);
  }
  for(int j = 0; j < m; j++) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  vector<int> closest[n+1];
  //BFS
  queue<int> q;
  for(int i = 1; i <= k; i++) {
    bool visited[n+1];
    for(int f = 1; f <= n; f++) {
      visited[f] = false;
    }
    for(int j = 0; j < goods[i].size(); j++) {
      q.push(goods[i][j]);
      visited[goods[i][j]] = true;
    }
    int distance = 0;
    while(!q.empty()) {
      int numTimes = q.size();
      for(int u = 0; u < numTimes; u++) {
        int node = q.front();
        q.pop();
        closest[node].push_back(distance);
        for(int t = 0; t < adj[node].size(); t++) {
          int vertex = adj[node][t];
          if(!visited[vertex]) {
            q.push(vertex);
            visited[vertex] = true;
          }
        }
      }
      distance++;
    }
  }
  int costs[n+1];
  for(int i = 1; i <= n; i++) {
    sort(closest[i].begin(), closest[i].end());
    sum = 0;
    for(int v = 0; v < s; v++) {
      sum += closest[i][v];
    }
    costs[i] = sum;
  }
  for(int i = 1; i < n; i++) {
    cout << costs[i] << " ";
  }
  cout << costs[n] << endl;
  return 0;
}
