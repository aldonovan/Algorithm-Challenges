#include <iostream>
#include <unordered_set>
using namespace std;

/*Use binary search on the number of moves to find last
  time when p is a subsequence of the string
*/
int verify(string t, string p, int moves, int a[]) {
  unordered_set<int> removed;
  for(int i = 0; i < moves; i++) {
    removed.insert(a[i]-1);
  }
  //Check if p is subsequence of remaining string
  int j = 0;
  for(int i = 0; i < t.length() && j < p.length(); i++) {
    if(removed.find(i) == removed.end()) {
      if(t[i] == p[j]) j++;
    }
  }
  return j == p.length();
}

int main() {
  string t, p;
  cin >> t >> p;
  int a[t.length()];
  for(size_t i = 0; i < t.length(); i++) {
    cin >> a[i];
  }
  int low = 0;
  int high = t.length() - 1;
  int answer = -1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(verify(t, p, mid, a)) {
      answer = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << answer << endl;
  return 0;
}
