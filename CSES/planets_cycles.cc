#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> next_planet(n);
  for (int i = 0; i < n; ++i) {
    cin >> next_planet[i];
    --next_planet[i];
  }
  vector<int> num_teleports(n, -1);
  for (int i = 0; i < n; ++i) {
    if (num_teleports[i] != -1) {
      continue;
    }
    vector<int> path = {i};
    unordered_map<int, int> visited;
    visited[i] = 0;
    while (true) {
      int next = next_planet[path.back()];
      path.push_back(next);
      if (num_teleports[next] != -1) {
        int path_length = num_teleports[next] + 1;
        for (int i = path.size() - 2; i >= 0; --i) {
          num_teleports[path[i]] = path_length;
          ++path_length;
        }
        break;
      } else if (visited.contains(next)) {
        int path_cycle_start = visited[next];
        int cycle_length = path.size() - 1 - path_cycle_start;
        for (int index = path_cycle_start; index < path.size() - 1; ++index) {
          num_teleports[path[index]] = cycle_length;
        }
        int path_length = cycle_length + 1;
        for (int i = path_cycle_start - 1; i >= 0; --i) {
          num_teleports[path[i]] = path_length;
          ++path_length;
        }
        break;
      } else {
        visited[next] = path.size() - 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << num_teleports[i] << " ";
  }
  cout << '\n';
}
