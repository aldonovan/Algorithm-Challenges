#include <algorithm>
#include <iostream>
#include <vector>

int GetLeafNumbers(const int node, const int parent,
                   const std::vector<std::vector<int>>& neighbors,
                   std::vector<int>& leaf_numbers) {
  if (leaf_numbers[node] != 0) {
    return leaf_numbers[node];
  }
  int num_leaves = (neighbors[node].size() == 1) ? 1 : 0;
  for (const int child : neighbors[node]) {
    if (child == parent) {
      continue;
    }
    num_leaves += GetLeafNumbers(child, node, neighbors, leaf_numbers);
  }
  leaf_numbers[node] = num_leaves;
  return num_leaves;
}

int FindLeafCentroid(const int node, const int parent,
                     const std::vector<std::vector<int>>& neighbors,
                     const int num_leaves, std::vector<int>& leaf_numbers) {
  for (const int child : neighbors[node]) {
    if (child == parent) {
      continue;
    }
    if (GetLeafNumbers(child, node, neighbors, leaf_numbers) * 2 > num_leaves) {
      return FindLeafCentroid(child, node, neighbors, num_leaves, leaf_numbers);
    }
  }
  return node;
}

void RetrieveLeaves(const int node, const int parent,
                    const std::vector<std::vector<int>>& neighbors,
                    std::vector<int>& leaves) {
  if (neighbors[node].size() == 1) {
    leaves.push_back(node);
  }
  for (const int child : neighbors[node]) {
    if (child == parent) {
      continue;
    }
    RetrieveLeaves(child, node, neighbors, leaves);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> degrees(n);
  std::vector<std::vector<int>> neighbors(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    ++degrees[a];
    ++degrees[b];
    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }
  std::vector<int> leaf_numbers(n);
  int num_leaves = std::count(degrees.begin(), degrees.end(), 1);
  int leaf_centroid =
      FindLeafCentroid(0, -1, neighbors, num_leaves, leaf_numbers);
  std::vector<int> leaves;
  RetrieveLeaves(leaf_centroid, -1, neighbors, leaves);
  int num_pairs = num_leaves / 2;
  int num_connections = (num_leaves + 1) / 2;
  std::cout << num_connections << '\n';
  for (int i = 0; i < num_pairs; ++i) {
    std::cout << leaves[i] + 1 << " " << leaves[i + num_pairs] + 1 << '\n';
  }
  if (leaves.size() % 2 != 0) {
    std::cout << leaves.back() + 1 << " " << leaves.front() + 1 << '\n';
  }
}
