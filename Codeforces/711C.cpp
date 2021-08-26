#include <iostream>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int colors[n];
  for(int i = 0; i < n; i++) {
    cin >> colors[i];
  }
  int costs[n][m];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> costs[i][j];
    }
  }

  return 0;
}
