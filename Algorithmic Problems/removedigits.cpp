#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, j, digit;
  cin >> n;
  vector<int> steps(n + 1);
  for (int i = 1; i <= n; i++) {
    if (i < 10) {
      steps[i] = 1;
    } else {
      j = i;
      int fewestSteps = INT_MAX;
      while (j > 0) {
        digit = j % 10;
        j /= 10;
        if (digit > 0) {
          fewestSteps = min(fewestSteps, steps[i - digit] + 1);
        }
      }
      steps[i] = fewestSteps;
    }
  }
  cout << steps[n] << endl;
  return 0;
}
