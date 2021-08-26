#include <iostream>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long runningProduct = 1;
  int numbers[n];
  long long numWays[m+1];
  long long newWays[m+1];
  for(int i = 0; i < n; i++) {
    cin >> numbers[i];
  }
  for(int i = 0; i < n; i++) {
    if(numbers[i] == 0) {
      if(i == 0) {
        for(int j = 1; j < m+1; j++) {
          numWays[j] = 1;
        }
      } else if(numbers[i-1] == 0){
        for(int j = 1; j < m+1; j++) {
          newWays[j] = 0;
          for(int k = max(j-1, 1); k <= min(m, j+1); k++) {
            newWays[j] += numWays[k];
          }
          newWays[j] = newWays[j] % 1000000007;
        }
        for(int i = 1; i <= m; i++) {
          numWays[i] = newWays[i];
        }
      } else {
        for(int j = 1; j < m+1; j++) {
          if(abs(numbers[i-1]-j) <= 1) {
            numWays[j] = 1;
          } else {
            numWays[j] = 0;
          }
        }
      }
    } else if(i > 0){
      if(numbers[i-1] == 0) {
        int numSegments = 0;
        for(int k = max(numbers[i]-1, 1); k <= min(numbers[i]+1, m); k++) {
          numSegments += numWays[k];
          numSegments = numSegments % 1000000007;
        }
        runningProduct *= numSegments;
        runningProduct = runningProduct % 1000000007;
      } else if(abs(numbers[i-1]-numbers[i]) > 1) {
        runningProduct = 0;
        break;
      }
    }
  }
  if(numbers[n-1] == 0) {
    int sumNumbers = 0;
    for(int i = 1; i <= m; i++) {
      sumNumbers += numWays[i];
      sumNumbers = sumNumbers % 1000000007;
    }
    runningProduct *= sumNumbers;
    runningProduct = runningProduct % 1000000007;
  }
  cout << runningProduct << endl;
  return 0;
}
