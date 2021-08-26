#include <iostream>
#include <queue>
#include <set>
using namespace std;
int main() {
  //Find maximum area of fragment after horizontal, vertical cuts
  set<int> hCuts;
  set<int> vCuts;
  int w, h, n;
  cin >> w >> h >> n;
  hCuts.insert(0);
  vCuts.insert(0);
  hCuts.insert(h);
  vCuts.insert(w);
  multiset<int> widths, heights;
  heights.insert(h);
  widths.insert(w);
  char dir;
  int position;
  set<int>::iterator it;
  for(int i = 0; i < n; i++) {
    cin >> dir >> position;
    if(dir == 'H') {
      auto firstLarger = it = hCuts.upper_bound(position);
      it--;
      int gap = *firstLarger - *it;
      heights.insert(*firstLarger - position);
      heights.insert(position - *it);
      heights.erase(heights.find(gap));
      hCuts.insert(position);
    } else {
      auto firstLarger = it = vCuts.upper_bound(position);
      it--;
      int gap = *firstLarger - *it;
      widths.insert(*firstLarger - position);
      widths.insert(position - *it);
      widths.erase(widths.find(gap));
      vCuts.insert(position);
    }
    cout << (long long)(*widths.rbegin())*(long long)(*heights.rbegin()) << endl;
  }
  return 0;
}
