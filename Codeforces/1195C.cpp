#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int first[n];
  int second[n];
  for(int i = 0; i < n; i++) cin >> first[i];
  for(int i = 0; i < n; i++) cin >> second[i];
  long long int topdp[n];
  long long int bottomdp[n];
  topdp[0] = first[0];
  bottomdp[0] = second[0];
  for(int i = 1; i < n; i++) {
    topdp[i] = max(topdp[i-1], first[i] + bottomdp[i-1]);
    bottomdp[i] = max(bottomdp[i-1], second[i] + topdp[i-1]);
  }
  cout << max(topdp[n-1], bottomdp[n-1]) << endl;
  return 0;
}
