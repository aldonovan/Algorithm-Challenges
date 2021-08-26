#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int maze[n][m];
  pair<int, int> lastCell;
  int count = 0;
  for(int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for(int j = 0; j < m; j++) {
      if(row[j] == '#') {
        maze[n][m] = 0;
      } else {
        count++;
        maze[n][m] = 1;
        lastCell.first = n;
        lastCell.second = m;
      }
    }
  }
  //Run BFS from lastCell until we have count - k cells
  int visitedCells = 1;
  queue<pair<int, int> > cells;
  cells.push(lastCell);
  map<pair<int, int>, int> visited;
  visited[lastCell] = 1;
  pair<int, int> directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
  while(visitedCells < count - k) {
    pair<int, int> currCell = cells.pop();
    for(pair<int, int> direction : directions) {
      pair<int, int> newCell;
      newCell.first = currCell.first + direction.first;
      newCell.second = currCell.second + direction.second;
      if(newCell.first >= 0 && newCell.first < m && newCell.second >= 0 && newCell.second < n) {
        if(visited[newCell] == 0 && visitedCells < count - k && maze[n][m] == 1) {
          visited[newCell] = 1;
          visitedCells++;
          cells.push(newCell);
        }
      }
    }
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(maze[n][m] == 0) {
        cout << "#";
      } else {
        pair<int, int> cell;
        cell.first = i;
        cell.second = j;
        if(visited[cell] == 1) {
          cout << "X";
        } else {
          cout << ".";
        }
      }
    }
    cout << endl;
  }
  return 0;
}
