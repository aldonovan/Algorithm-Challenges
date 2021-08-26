#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, cube;
  cin >> n;
  vector<int> towers;
  for(int i = 0; i < n; i++) {
    cin >> cube;
    auto it = upper_bound(towers.begin(), towers.end(), cube);
    if(it == towers.end()) {
      towers.push_back(cube);
    } else {
      towers[it-towers.begin()] = cube;
    }
  }
  cout << towers.size() << endl;
  return 0;
}
