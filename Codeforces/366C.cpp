#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int tastes[n];
  int calories[n];
  for(int i = 0; i < n; i++) {
    cin >> tastes[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> calories[i];
  }

  return 0;
}
