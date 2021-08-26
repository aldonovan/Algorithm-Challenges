#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
  int n;
  string comparisons;
  cin >> n >> comparisons;
  int minToffee[n];
  for(int i = 0; i < n; i++) minToffee[i] = 0;
  int index = 0;
  while(index < n - 1) {
    char comparison = comparisons[index];
    if(comparison == 'R' || index == n - 2) {
      if(index == n-2 && comparison != 'R') index++;
      minToffee[index] = 1;
      int i = index - 1;
      while(i >= 0 && comparisons[i] != 'R') {
        if(comparisons[i] == 'L') {
          minToffee[i] = max(minToffee[i], minToffee[i+1]+1);
        } else {
          minToffee[i] = max(minToffee[i], minToffee[i+1]);
        }
        i--;
      }
      i = index;
      while(i < n - 1 && comparisons[i] != 'L') {
        minToffee[i+1] = minToffee[i];
        if(comparisons[i] == 'R') minToffee[i+1]++;
        i++;
      }
      index = max(i, index+1);
    } else {
      index++;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << minToffee[i] << " ";
  }
  return 0;
}
