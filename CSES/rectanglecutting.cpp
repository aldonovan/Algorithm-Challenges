#include <iostream>
#include <climits>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int cuts[a+1][b+1];
  for(int i = 1; i <= a; i++) {
    for(int j = 1; j <=b; j++) {
      //Think about it, if a = b, then we need 0 cuts.
      //Given an a x b rectangle, consider the first cut.
      //It becomes two rectangles after the cut. These are either
      // (a-1)*b and 1*b, (a-2)*b, 2*b, ... or a*(b-1) and a*1, a*(b-2) and a*2
      // and so on.
      if(i == 1) {
        cuts[i][j] = j - 1;
      } else if(j == 1) {
        cuts[i][j] = i - 1;
      } else if(i == j) {
        cuts[i][j] = 0;
      } else {
        cuts[i][j] = INT_MAX;
        for(int k = 1; k <= j/2; k++) {
          cuts[i][j] = min(cuts[i][j], cuts[i][k] + cuts[i][j-k] + 1);
        }
        for(int k = 1; k <= i/2; k++) {
          cuts[i][j] = min(cuts[i][j], cuts[k][j] + cuts[i-k][j] + 1);
        }
      }
    }
  }
  cout << cuts[a][b] << endl;
  return 0;
}
