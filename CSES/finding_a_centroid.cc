#include <iostream>
#include <vector>

int GetSubtreeSize(const int node, const int parent,
                   const std::vector<std::vector<int>>& neighbors,
                   std::vector<int>& subtree_sizes) {
  if (subtree_sizes[node] != 0) {
    return subtree_sizes[node];
  }
  int subtree_size = 1;
  for (const int child : neighbors[node]) {
    if (child == parent) {
      continue;
    }
    subtree_size += GetSubtreeSize(child, node, neighbors, subtree_sizes);
  }
  subtree_sizes[node] = subtree_size;
  return subtree_size;
}

int FindCentroid(const int node, const int parent,
                 const std::vector<std::vector<int>>& neighbors,
                 std::vector<int>& subtree_sizes) {
  for (const int child : neighbors[node]) {
    if (child == parent) {
      continue;
    }
    if (GetSubtreeSize(child, node, neighbors, subtree_sizes) * 2 >=
        static_cast<int>(neighbors.size())) {
      return FindCentroid(child, node, neighbors, subtree_sizes);
    }
  }
  return node;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> neighbors(n);
  std::vector<int> subtree_sizes(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }
  std::cout << FindCentroid(0, -1, neighbors, subtree_sizes) + 1 << '\n';
}
