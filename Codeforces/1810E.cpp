#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// Store number of nodes in the component
class DSU {
 public:
  DSU(int n)
      : parents(n + 1, 0), number_of_nodes(n + 1, 1), is_valid(n + 1, false) {
    for (int i = 1; i <= n; ++i) {
      parents[i] = i;
    }
  }
  int find_parent(int vertex) {
    if (vertex == parents[vertex]) {
      return vertex;
    }
    return parents[vertex] = find_parent(parents[vertex]);
  }
  void merge(int vertex1, int vertex2) {
    int parent1 = find_parent(vertex1);
    int parent2 = find_parent(vertex2);
    if (parent1 == parent2) {
      return;
    }
    int rank1 = number_of_nodes[parent1];
    int rank2 = number_of_nodes[parent2];
    if (rank1 > rank2) {
      swap(parent1, parent2);
    }
    parents[parent1] = parent2;
    number_of_nodes[parent2] += number_of_nodes[parent1];
  }
  int get_number_of_nodes(int vertex) {
    return number_of_nodes[find_parent(vertex)];
  }
  bool get_validity(int vertex) { return is_valid[find_parent(vertex)]; }
  void set_validity(int vertex, bool validity) {
    is_valid[find_parent(vertex)] = validity;
  }
  bool solve() { return get_validity(1); }

 private:
  vector<int> parents;
  vector<int> number_of_nodes;
  vector<bool> is_valid;
};

int main() {
  // For any connected component adjacent, it must have all nodes less than or
  // equal to curr It either is navigable, in which case curr node is reachable
  // if <= 1 + size. Or it is not navigable, in which case it will still not be
  // navigable when adding new node. If at least one neighbor is navigable, they
  // all become navigable
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> dangers;
    for (int i = 1; i <= n; ++i) {
      int curr_danger;
      cin >> curr_danger;
      dangers.emplace_back(curr_danger, i);
    }
    vector<vector<int>> edges(n + 1);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
    sort(dangers.begin(), dangers.end());
    DSU vertices(n);
    vector<bool> visited(n + 1, false);
    for (const auto& [danger, index] : dangers) {
      if (danger == 0) {
        vertices.set_validity(index, true);
      }
      bool now_valid = false || danger == 0;
      for (int neighbor : edges[index]) {
        if (!visited[neighbor]) {
          continue;
        }
        if (vertices.get_validity(neighbor) &&
            vertices.get_number_of_nodes(neighbor) >= danger) {
          now_valid = true;
          break;
        }
      }
      // cout << "Index " << index << " " << now_valid << "\n";
      for (int neighbor : edges[index]) {
        if (!visited[neighbor]) {
          continue;
        }
        vertices.merge(index, neighbor);
      }
      vertices.set_validity(index, now_valid);
      visited[index] = true;
    }
    bool is_valid = vertices.solve() && vertices.get_number_of_nodes(1) == n;
    cout << ((is_valid) ? "YES\n" : "NO\n");
  }
}
