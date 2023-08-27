#include <iostream>
#include <map>
using namespace std;
int main () {
  int n, id;
  cin >> n;
  int longest = 0;
  int start = 0;
  map<int, int> ids;
  for(int i = 0; i < n; i++) {
    cin >> id;
    if(ids.count(id) && ids[id] >= start) {
      longest = max(longest, i - start);
      start = ids[id] + 1;
    }
    ids[id] = i;
  }
  longest = max(longest, n - start);
  cout << longest << endl;
  return 0;
}
