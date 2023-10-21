#include <iostream>
#include <queue>
#include <vector>

void SolveCase() {
  int n, k;
  std::cin >> n >> k;
  std::vector<bool> marked(n, false);
  for (int i = 0; i < k; ++i) {
    int node;
    std::cin >> node;
    --node;
    marked[node] = true;
  }
  std::vector<std::vector<int>> neighbors(n);
  for (int i = 0; i < n - 1; ++i) {
    int first_node, second_node;
    std::cin >> first_node >> second_node;
    --first_node;
    --second_node;
    neighbors[first_node].push_back(second_node);
    neighbors[second_node].push_back(first_node);
  }
  int first_node = 0;
  std::vector<bool> visited(n, false);
  visited[0] = true;
  std::queue<int> q;
  q.push(0);
  int last_marked_node = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (marked[curr]) {
      last_marked_node = curr;
    }
    for (int neighbor : neighbors[curr]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }

  visited = std::vector<bool>(n, false);
  std::vector<int> prev_node(n, -1);
  q.push(last_marked_node);
  visited[last_marked_node] = true;
  int other_end = last_marked_node;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    if (marked[curr]) {
      other_end = curr;
    }
    for (int neighbor : neighbors[curr]) {
      if (!visited[neighbor]) {
        q.push(neighbor);
        prev_node[neighbor] = curr;
        visited[neighbor] = true;
      }
    }
  }
  std::vector<int> longest_path;
  int curr = other_end;
  while (true) {
    longest_path.push_back(curr);
    if (prev_node[curr] == -1) {
      break;
    }
    curr = prev_node[curr];
  }
  int result = longest_path.size() / 2;
  std::cout << result << '\n';
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    SolveCase();
  }
}
