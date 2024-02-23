#include <iostream>
#include <vector>

using namespace std;

int dfs(const int curr_vertex, const vector<vector<int>>& neighbors,
        const int n, vector<int>& longest, vector<int>& next_vertices) {
  if (longest[curr_vertex] != -1) {
    return longest[curr_vertex];
  }
  if (curr_vertex == n - 1) {
    longest[curr_vertex] = 1;
    return 1;
  }
  int longest_path = 0;
  int next_vertex = -1;
  for (int neighbor : neighbors[curr_vertex]) {
    const int curr_path = dfs(neighbor, neighbors, n, longest, next_vertices);
    if (curr_path != 0 && curr_path + 1 > longest_path) {
      longest_path = curr_path + 1;
      next_vertex = neighbor;
    }
  }
  longest[curr_vertex] = longest_path;
  next_vertices[curr_vertex] = next_vertex;
  return longest_path;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> neighbors(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    neighbors[a].push_back(b);
  }
  vector<int> longest(n, -1);
  vector<int> next_vertices(n, -1);
  int longest_path = dfs(0, neighbors, n, longest, next_vertices);
  if (longest_path == 0) {
    cout << "IMPOSSIBLE" << endl;
  } else {
    cout << longest_path << '\n';
    int curr_vertex = 0;
    for (int i = 0; i < longest_path; ++i) {
      cout << curr_vertex + 1 << " ";
      curr_vertex = next_vertices[curr_vertex];
    }
    cout << '\n';
  }
}
