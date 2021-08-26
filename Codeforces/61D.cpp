#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
void dfs(int i, vector<pii> adj[], bool visited[], ll returnLength[], ll visitLength[]) {
  visited[i] = true;
  ll biggest = -1;
  for(int j = 0; j < adj[i].size(); j++) {
    int vertex = adj[i][j].first;
    int weight = adj[i][j].second;
    if(!visited[vertex]) {
      dfs(vertex, adj, visited, returnLength, visitLength);
      returnLength[i] += returnLength[vertex] + 2*weight;
      biggest = max(biggest, weight + returnLength[vertex] - visitLength[vertex]);
    }
  }
  visitLength[i] = returnLength[i];
  if(biggest != -1) {
    visitLength[i] -= biggest;
  }
}

int main() {
  int n, v1, v2, weight;
  cin >> n;
  vector<pii> adj[n+1];
  bool visited[n+1];
  ll returnLength[n+1];
  ll visitLength[n+1];
  for(int i = 0; i <= n; i++) {
    returnLength[i] = 0;
    visitLength[i] = 0;
    visited[i] = false;
  }
  for(int i = 0; i < n - 1; i++) {
    cin >> v1 >> v2 >> weight;
    adj[v1].push_back(pii(v2, weight));
    adj[v2].push_back(pii(v1, weight));
  }
  dfs(1, adj, visited, returnLength, visitLength);
  cout << visitLength[1] << endl;
  return 0;
}
