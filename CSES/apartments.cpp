#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int pref[n];
  int apartments[m];
  for(int i = 0; i < n; i++) {
    cin >> pref[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> apartments[i];
  }
  sort(pref, pref + n);
  sort(apartments, apartments + m);
  int assignments = 0;
  int prefIndex = 0;
  int apartmentIndex = 0;
  while(prefIndex < n && apartmentIndex < m) {
    if(abs(pref[prefIndex] - apartments[apartmentIndex]) <= k) {
      assignments++;
      prefIndex++;
      apartmentIndex++;
    } else if(pref[prefIndex] < apartments[apartmentIndex]) {
      prefIndex++;
    } else {
      apartmentIndex++;
    }
  }
  cout << assignments << endl;
  return 0;
}
