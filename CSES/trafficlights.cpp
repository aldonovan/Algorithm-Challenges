#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
  int x, n;
  cin >> x >> n;
  set<int> positions;
  multiset<int> lengths;
  lengths.insert(x);
  positions.insert(0);
  positions.insert(x);
  int newPos, leftVal, rightVal;
  for(int i = 0; i < n; i++) {
    cin >> newPos;
    auto it = positions.lower_bound(newPos);
    rightVal = *it;
    it--;
    leftVal = *it;
    int splitLength = rightVal - leftVal;
    int leftLength = newPos - leftVal;
    int rightLength = rightVal - newPos;
    auto foundLength = lengths.find(splitLength);
    lengths.erase(foundLength);
    lengths.insert(leftLength);
    lengths.insert(rightLength);
    positions.insert(newPos);
    cout << *lengths.rbegin() << " ";
  }
  cout << endl;
  return 0;
}
