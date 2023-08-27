#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
  int n, number;
  cin >> n;
  long long numSequences = 0;
  unordered_map<int, int> sums;
  sums[0] = 1;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    cin >> number;
    sum = (sum + number) % n;
    if(sum < 0) sum += n;
    numSequences += sums[sum];
    sums[sum]++;
  }
  cout << numSequences << endl;
}
