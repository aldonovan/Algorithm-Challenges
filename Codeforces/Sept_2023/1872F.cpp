#include <iostream>
#include <queue>
#include <vector>

void solve_test_case() {
  int n;
  std::cin >> n;
  std::vector<int> animals(n, 0);
  std::vector<int> indegree(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> animals[i];
    --animals[i];
    ++indegree[animals[i]];
  }
  std::vector<int> costs(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> costs[i];
  }
  std::queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  std::vector<bool> visited(n, false);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    visited[curr] = true;
    std::cout << curr + 1 << " ";
    --indegree[animals[curr]];
    if (indegree[animals[curr]] == 0) {
      q.push(animals[curr]);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (visited[i]) {
      continue;
    }
    std::vector<int> indices;
    int smallest_index = -1;
    int curr = i;
    while (!visited[curr]) {
      visited[curr] = true;
      if (smallest_index == -1 ||
          costs[curr] < costs[indices[smallest_index]]) {
        smallest_index = indices.size();
      }
      indices.push_back(curr);
      curr = animals[curr];
    }
    for (int index = smallest_index + 1; index < indices.size(); ++index) {
      std::cout << indices[index] + 1 << " ";
    }
    for (int index = 0; index <= smallest_index; ++index) {
      std::cout << indices[index] + 1 << " ";
    }
  }
  std::cout << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    solve_test_case();
  }
}
