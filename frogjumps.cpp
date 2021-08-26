#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int numCases = 0;
  cin >> numCases;
  for(int i = 0; i < numCases; i++) {
    string cells;
    cin >> cells;
    int jumps = 1;
    int curr = -1;
    for(int j = 0; j < cells.length(); j++) {
      if(cells[j] == 'R') {
        jumps = max(jumps, j - curr);
        curr = j;
      }
    }
    jumps = max(jumps, (int)(cells.length()) - curr);
    cout << jumps << endl;
  }
  return 0;
}
