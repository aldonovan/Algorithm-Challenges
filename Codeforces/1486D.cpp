#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int numbers[n];
  int smallest = INT_MAX;
  int largest = INT_MIN;
  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
    smallest = min(smallest, numbers[i]);
    largest = max(largest, numbers[i]);
  }
  int low = smallest;
  int high = largest;
  int answer = 0;
  while(low <= high) {
    int mid = low + (high - low)/2;
    int minBalance[n];
    int balance = 0;
    int lowestBalance = 0;
    bool canGetMedian = false;
    for(int i = 0; i < n; i++) {
      if(numbers[i] >= mid) {
        balance += 1;
      } else {
        balance -= 1;
      }
      lowestBalance = min(lowestBalance, balance);
      minBalance[i] = lowestBalance;
      if((i == k - 1 && balance > 0) || (i >= k && balance > minBalance[i-k])) {
        canGetMedian = true;
        break;
      }
    }
    if(canGetMedian) {
      answer = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << answer << endl;
  return 0;
}
