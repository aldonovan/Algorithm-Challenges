#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int numbers[2*n-1];
  int smallest = INT_MAX;
  int sum = 0;
  int numNegative = 0;
  for(int i = 0; i < 2*n-1; i++) {
    cin >> numbers[i];
    sum += abs(numbers[i]);
    smallest = min(smallest, abs(numbers[i]));
    if(numbers[i] < 0) numNegative++;
  }
  if(n % 2 == 0 && numNegative % 2 != 0) {
    cout << sum - 2*smallest << endl;
  } else {
    cout << sum << endl;
  }
  return 0;
}
