#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a > b;
  };
  set<pair<int, int>, decltype(cmp)> rows_num_squares;
  for (int i = 0; i < n; ++i) {
    int num_squares;
    cin >> num_squares;
    rows_num_squares.emplace(num_squares, i);
  }
  set<pair<int, int>, decltype(cmp)> cols_num_squares;
  for (int i = 0; i < n; ++i) {
    int num_squares;
    cin >> num_squares;
    cols_num_squares.emplace(num_squares, i);
  }

  vector<vector<char>> grid(n, vector<char>(n, '.'));
  bool possible = true;
  for (const auto& [num_squares, col] : cols_num_squares) {
    if (num_squares == 0) {
      continue;
    }
    int num_remaining_squares = num_squares;
    vector<pair<int, int>> updated_info;
    for (auto it = rows_num_squares.begin();
         num_remaining_squares > 0 && it != rows_num_squares.end();) {
      const auto& [row_squares, row] = *it;
      if (row_squares == 0) {
        possible = false;
        break;
      }
      grid[row][col] = 'X';
      updated_info.emplace_back(row_squares - 1, row);
      --num_remaining_squares;
      it = rows_num_squares.erase(it);
    }
    if (!possible) {
      break;
    }
    rows_num_squares.insert(make_move_iterator(updated_info.begin()),
                            make_move_iterator(updated_info.end()));
  }
  if (rows_num_squares.begin()->first != 0) {
    possible = false;
  }
  if (!possible) {
    cout << "-1" << '\n';
  } else {
    for (const auto& row : grid) {
      for (const auto& num : row) {
        cout << num;
      }
      cout << '\n';
    }
  }
}
