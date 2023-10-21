#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
#include <vector>

void SolveCase() {
  int n, a, b;
  std::cin >> n >> a >> b;
  --a;
  --b;
  std::vector<std::vector<int>> edges(n);
  for (int i = 0; i < n; ++i) {
    int v1, v2;
    std::cin >> v1 >> v2;
    --v1;
    --v2;
    edges[v1].push_back(v2);
    edges[v2].push_back(v1);
  }
  std::queue<std::tuple<int, int, int>> q;
  std::set<std::tuple<int, int, int>> losing_states;
  std::map<std::tuple<int, int, int>, int> indegree;
  for (int i = 0; i < n; ++i) {
    losing_states.emplace(i, i, 1);
    losing_states.emplace(i, i, 2);
    q.emplace(i, i, 1);
    q.emplace(i, i, 2);
    edges[i].push_back(i);
  }
  while (!q.empty()) {
    auto [player_one_vertex, player_two_vertex, current_player] = q.front();
    if (player_one_vertex == b && player_two_vertex == a) {
      std::cout << "NO\n";
      return;
    }
    q.pop();
    int changed_vertex =
        (current_player == 1) ? player_two_vertex : player_one_vertex;
    for (int neighbor : edges[changed_vertex]) {
      std::tuple state = (current_player == 1)
                             ? std::tuple{player_one_vertex, neighbor, 2}
                             : std::tuple{neighbor, player_two_vertex, 1};
      if (losing_states.contains(state)) {
        continue;
      }
      int in_edges = ++indegree[state];
      if (in_edges == edges[neighbor].size() || current_player == 1) {
        losing_states.insert(state);
        q.push(state);
      }
    }
  }
  std::cout << "YES\n";
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    SolveCase();
  }
}
