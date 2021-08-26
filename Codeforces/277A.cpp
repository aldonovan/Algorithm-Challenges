#include <iostream>
#include <vector>
using namespace std;

void dfs(int v, vector<int> adj[], int visited[]) {
  visited[v] = 1;
  for(int i = 0; i < adj[v].size(); i++) {
    int x = adj[v][i];
    if(!visited[x]) {
      dfs(x, adj, visited);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n+m+1];
  int totalLanguages = 0;
  for(int i = 1; i <= n; i++) {
    int numLanguages;
    cin >> numLanguages;
    totalLanguages += numLanguages;
    for(int j = 0; j < numLanguages; j++) {
      int language;
      cin >> language;
      adj[i].push_back(language + n);
      adj[language + n].push_back(i);
    }
  }

  int numConnectedComponents = 0;
  int visited[n+m+1];
  for(int i = 0; i <= n+m; i++) visited[i] = 0;
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      numConnectedComponents++;
      dfs(i, adj, visited);
    }
  }

  if(totalLanguages == 0) {
    cout << n << endl;
  } else {
    cout << numConnectedComponents - 1 << endl;
  }
  return 0;
}
