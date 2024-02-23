#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
int main() {
  string s;
  cin >> s;
  // Feels recursive backtracking
  vector<vector<int64_t>> grid(7, vector<int64_t>(7, 0));
  grid[6][0] = 1;
  for (int i = 1; i <= 24; ++i) {
    vector<vector<int64_t>> new_grid(7, vector<int64_t>(7, 0));
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 7; ++k) {
        for (const auto& [dj, dk] : {pair{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
          int diff_j = j + dj;
          int diff_k = k + dk;
          if (diff_j >= 0 && diff_j < 7 && diff_k >= 0 && diff_k < 7) {
            new_grid[diff_j][diff_k] += grid[j][k];
          }
        }
      }
    }
    grid = new_grid;
  }
  cout << grid[0][0] << endl;
  // This might just be brute force
}