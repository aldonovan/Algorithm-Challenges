#include <iostream>
#include <map>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  //Thought: We know there is a subarray with sum zero when
  // there is a duplicate prefix sum. I think we can use a hashmap
  // of prefix sum to index. Use two pointers.
  // When we encounter a prefix sum already in the
  // hashmap, we need to adjust the start index to prefixIndex + 1.
  // We also need to add (currIndex - prefixIndex) + (currIndex - prefixIndex + 1)
  // + ... + (currIndex - startIndex). This is an arithmetic sequence with
  // sum (currIndex - prefixIndex + currIndex - startIndex)*(prefixIndex-startIndex+1)/2
  map<long long, int> prefixSums;
  prefixSums[0] = -1;
  long long numGood = 0;
  long long startIndex = 0;
  long long currIndex = 0;
  long long sum = 0;
  while(currIndex < n) {
    sum += a[currIndex];
    if(prefixSums.find(sum) != prefixSums.end() &&
        prefixSums[sum] >= startIndex - 1) {
          long long lastIndex = prefixSums[sum] + 1; //-1
          numGood += (2*currIndex - lastIndex - startIndex)*(lastIndex - startIndex + 1)/2;
          startIndex = lastIndex + 1;
          if(a[startIndex] == 0) startIndex++;
        }
    prefixSums[sum] = currIndex;
    currIndex++;
  }
  long long numRemaining = n - startIndex;
  numGood += numRemaining*(numRemaining+1)/2;
  cout << numGood << endl;
  return 0;
}
