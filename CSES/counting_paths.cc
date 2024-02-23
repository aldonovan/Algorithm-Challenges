#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// Use small-to-large merging

using namespace std;

void DfsTour(const vector<vector<int>>& neighbors, const int curr_vertex,
             const int parent_vertex, const int curr_depth, vector<int>& id_map,
             vector<int>& depths, vector<int>& ordered) {
  id_map[curr_vertex] = depths.size();
  depths.push_back(curr_depth);
  ordered.push_back(curr_vertex);
  for (int neighbor : neighbors[curr_vertex]) {
    if (neighbor == parent_vertex) continue;
    DfsTour(neighbors, neighbor, curr_vertex, curr_depth + 1, id_map, depths,
            ordered);
    depths.push_back(curr_depth);
    ordered.push_back(curr_vertex);
  }
}

int ComputeResults(const int curr_vertex, const int parent_vertex,
                   const vector<vector<int>>& neighbors,
                   const vector<int>& upward, const vector<int>& downward,
                   vector<int>& results) {
  int total = upward[curr_vertex];
  for (int neighbor : neighbors[curr_vertex]) {
    if (neighbor == parent_vertex) continue;
    total += ComputeResults(neighbor, curr_vertex, neighbors, upward, downward,
                            results);
  }
  results[curr_vertex] += total;
  return total - downward[curr_vertex];
}

// pair<unordered_map<int, int>, int> ComputeResults(
//     const vector<pair<unordered_map<int, int>, int>>& changed_paths,
//     const vector<vector<int>>& neighbors, const int curr_vertex,
//     const int parent_vertex, vector<int>& results) {
//   unordered_map<int, int> r = changed_paths[curr_vertex].first;
//   int total = changed_paths[curr_vertex].second;
//   for (int neighbor : neighbors[curr_vertex]) {
//     if (neighbor == parent_vertex) continue;
//     auto [neighbor_results, num_paths] = ComputeResults(
//         changed_paths, neighbors, neighbor, curr_vertex, results);
//     total += num_paths;
//     if (r.size() < neighbor_results.size()) {
//       for (const auto& [a, b] : r) {
//         neighbor_results[a] += b;
//       }
//       r = std::move(neighbor_results);
//     } else {
//       for (const auto& [a, b] : neighbor_results) {
//         r[a] += b;
//       }
//     }
//   }
//   results[curr_vertex] = total;
//   if (auto it = r.find(curr_vertex); it != r.end()) {
//     total -= it->second;
//     r.erase(it);
//   }
//   return {move(r), total};
// }

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> neighbors(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }
  vector<pair<int, int>> paths;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    paths.emplace_back(a, b);
  }
  // cout << "\n";

  vector<int> id_map(n);
  vector<int> depths;
  vector<int> ordered;
  DfsTour(neighbors, 0, -1, 0, id_map, depths, ordered);

  // for (int ord : ordered) {
  //   cout << ord << " ";
  // }
  // cout << '\n';

  vector<int> power_of_2(depths.size() + 1);
  power_of_2[1] = 0;
  int curr_power = 1;
  int curr_exponent = 0;
  for (int i = 2; i <= depths.size(); ++i) {
    if (curr_power * 2 == i) {
      curr_power *= 2;
      ++curr_exponent;
    }
    power_of_2[i] = curr_exponent;
  }

  int max_exponent = power_of_2[depths.size()];
  vector<vector<int>> results(ordered.size(), vector<int>(max_exponent + 1));
  for (int i = 0; i < ordered.size(); ++i) {
    results[i][0] = i;
  }
  for (int exponent = 1; exponent <= max_exponent; ++exponent) {
    for (int i = 0; i + (1 << exponent) <= ordered.size(); ++i) {
      int first_node = results[i][exponent - 1];
      int second_node = results[i + (1 << (exponent - 1))][exponent - 1];
      if (depths[first_node] < depths[second_node]) {
        results[i][exponent] = first_node;
      } else {
        results[i][exponent] = second_node;
      }
    }
  }

  // for (auto r : results) {
  //   for (auto t : r) {
  //     cout << t << " ";
  //   }
  //   cout << '\n';
  // }

  // for (int ord : ordered) {
  //   cout << ord << " ";
  // }
  // cout << "\n\n\n";

  // vector<pair<unordered_map<int, int>, int>> changed_paths(n);
  vector<int> final_counts(n);
  vector<int> upward(n);
  vector<int> downward(n);

  for (const auto& [a, b] : paths) {
    int first_id = id_map[a];
    int second_id = id_map[b];
    if (first_id > second_id) {
      swap(first_id, second_id);
    }
    int length = second_id - first_id + 1;
    int exponent = power_of_2[length];
    // cout << first_id << " " << second_id << " " << exponent << "\n\n";
    int lca = results[first_id][exponent];
    int lca2 = results[second_id - (1 << exponent) + 1][exponent];
    // cout << lca << "  " << lca2 << "\n";
    if (depths[lca2] < depths[lca]) {
      lca = lca2;
    }
    lca = ordered[lca];
    if (lca == a) {
      ++upward[b];
      ++downward[a];
      // ++changed_paths[b].first[a];
      // ++changed_paths[b].second;
    } else if (lca == b) {
      ++upward[a];
      ++downward[b];
      // ++changed_paths[a].first[b];
      // ++changed_paths[b].second;
    } else {
      ++upward[a];
      ++upward[b];
      downward[lca] += 2;
      // Adjust for overcounting
      final_counts[lca] -= 1;
      // ++changed_paths[a].first[lca];
      // ++changed_paths[a].second;
      // ++changed_paths[b].first[lca];
      // ++changed_paths[b].second;
      // ++overcounted[lca];
    }
    // cout << a << " " << b << " " << lca << "\n";
  }
  // cout << "\n";

  ComputeResults(0, -1, neighbors, upward, downward, final_counts);
  for (int count : final_counts) {
    cout << count << " ";
  }
  cout << '\n';

  // vector<int> final_results(n);
  // ComputeResults(changed_paths, neighbors, 0, -1, final_results);
  // for (int i = 0; i < n; ++i) {
  //   cout << final_results[i] - overcounted[i] << " ";
  // }
  // cout << '\n';

  // vector<pair<int, int>> paths_sorted_by_first = paths;
  // sort(paths_sorted_by_first.begin(), paths_sorted_by_first.end());
  // vector<pair<int, int>> paths_sorted_by_second = paths;
  // sort(paths_sorted_by_second.begin(), paths_sorted_by_second.end(),
  //      [](const pair<int, int>& p1, const pair<int, int>& p2) {
  //        return p1.second < p2.second;
  //      });
  // for (const auto& [a, b] : paths_sorted_by_second) {
  //   cout << b << "\n";
  // }
  // cout << "\n";

  // vector<int> results(n, m);
  // for (int i = 0; i < n; ++i) {
  //   const auto& [start_id, end_id] = id_map[i];
  //   auto it = upper_bound(
  //       paths_sorted_by_second.begin(), paths_sorted_by_second.end(),
  //       start_id - 1,
  //       [](const int val, const pair<int, int>& p) { return val < p.second;
  //       });
  //   int num_end_before = distance(paths_sorted_by_second.begin(), it);
  //   it = upper_bound(
  //       paths_sorted_by_first.begin(), paths_sorted_by_first.end(), end_id,
  //       [](const int val, const pair<int, int>& p) { return val < p.first;
  //       });
  //   int num_start_after = distance(it, paths_sorted_by_first.end());
  //   results[i] -= num_end_before + num_start_after;
  //   cout << results[i] << " ";
  //   // cout << "Node " << i << " num_end_before " << num_end_before
  //   //      << " num_start_after " << num_start_after << "\n";
  // }

  // for (const auto& [a, b] : id_map) {
  //   const auto& [start_id, end_id] = b;
  //   cout << a << " " << start_id << " " << end_id << "\n";
  // }
  // cout << "Done\n";
}
