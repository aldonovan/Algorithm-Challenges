#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  //Thought Process: 3 is upper bound, casework
  int q, n, num, lastNum;
  cin >> q;
  while(q--) {
    cin >> n;
    int colors[n];
    int t[n];
    cin >> t[0];
    int firstSame = -1;
    int numDiff = 0;
    for(int i = 1; i < n; i++) {
      cin >> t[i];
      if(t[i] != t[i-1]) {
        numDiff++;
      } else {
        if(firstSame == -1) {
          firstSame = i;
        }
      }
    }
    if(t[0] == t[n-1]) {
      if(numDiff == 0) {
        cout << 1 << endl;
        for(int i = 0; i < n; i++) {
          cout << 1 << " ";
        }
      } else {
        cout << 2 << endl;
        cout << 1 << " ";
        int last = 1;
        for(int i = 1; i < n; i++) {
          if(t[i] == t[i-1]) {
            cout << last << " ";
          } else {
            cout << -1*last + 3 << " ";
            last = -1*last + 3;
          }
        }
      }
    } else {
        if(numDiff % 2 != 0) {
        cout << 2 << endl;
        cout << 1 << " ";
        int last = 1;
        for(int i = 1; i < n; i++) {
          if(t[i] == t[i-1]) {
            cout << last << " ";
          } else {
            cout << -1*last + 3 << " ";
            last = -1*last + 3;
          }
        }
      } else {
        if(firstSame == -1) {
          cout << 3 << endl;
          cout << 1 << " ";
          int last = 1;
          for(int i = 1; i < n - 1; i++) {
            if(t[i] == t[i-1]) {
              cout << last << " ";
            } else {
              cout << -1*last + 3 << " ";
              last = -1*last + 3;
            }
          }
          cout << 3;
        } else {
          cout << 2 << endl;
          cout << 1 << " ";
          int last = 1;
          for(int i = 1; i < firstSame; i++) {
            if(t[i] == t[i-1]) {
              cout << last << " ";
            } else {
              cout << -1*last + 3 << " ";
              last = -1*last + 3;
            }
          }
          cout << -1*last + 3 << " ";
          last = -1*last + 3;
          for(int i = firstSame + 1; i < n; i++) {
            if(t[i] == t[i-1]) {
              cout << last << " ";
            } else {
              cout << -1*last + 3 << " ";
              last = -1*last + 3;
            }
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
