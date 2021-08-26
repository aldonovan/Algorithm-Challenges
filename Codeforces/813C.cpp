#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(queue<int> nodes, int distanceArray[], bool visited[], vector<int> adj[]) {
  int distance = 1;
  while(!nodes.empty()) {
    int numElements = nodes.size();
    for(int s = 0; s < numElements; s++) {
      int node = nodes.front();
      nodes.pop();
      for(int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if(!visited[next]) {
          visited[next] = true;
          nodes.push(next);
          distanceArray[next] = distance;
        }
      }
    }
    distance++;
  }
}

int main() {
  int n, x, v1, v2;
  cin >> n >> x;
  vector<int> adj[n+1];
  for(int i = 1; i < n; i++) {
    cin >> v1 >> v2;
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
  }
  int aliceDistance[n+1];
  int bobDistance[n+1];
  aliceDistance[1] = 0;
  bobDistance[x] = 0;
  queue<int> nodes;
  nodes.push(1);
  bool visited[n+1];
  for(int i = 1; i <= n; i++) visited[i] = false;
  visited[1] = true;
  bfs(nodes, aliceDistance, visited, adj);
  for(int i = 1; i <= n; i++) visited[i] = false;
  visited[x] = true;
  nodes.push(x);
  bfs(nodes, bobDistance, visited, adj);
  int maxTime = 0;
  for(int i = 1; i <= n; i++) {
    if(aliceDistance[i] > bobDistance[i]) maxTime = max(maxTime, aliceDistance[i]);
  }
  cout << 2*maxTime << endl;
  return 0;
}
