#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  int numbers[n];
  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  sort(numbers, numbers + n);
  int medianIndex = n/2;
  long long smallestCost = (n % 2 == 0) ? numbers[medianIndex]: 0;
  for(int i = 0; i < medianIndex; i++) {
    smallestCost -= numbers[i];
  }
  for(int i = medianIndex + 1; i < n; i++) {
    smallestCost += numbers[i];
  }
  cout << smallestCost << endl;
  return 0;
}
