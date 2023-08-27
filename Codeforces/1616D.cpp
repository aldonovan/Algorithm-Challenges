#include <bits/stdc++.h>
using namespace std;
int main() {
    // Nums - we can subtract x from each number in the array
    // Then the problem becomes choosing so that a_l + ... + a_r >= 0
    // We can greedily select the longest possible segment that qualifies for the last value
    // A given subarray works if the prefix sums are increasing at a distance of two or greater
    // If at some point we have currPrefixSum < maxPrefixSum(start, i-2) -> we cannot do the interval
    // There is an O(n log n) solution with sparse table and two pointers here
    // Can we use a deque for this in O(n)?
    // Store indices in the deque and pop off prefix sums that are less than current 
    // When finding the max prefix sum, we simply take the last value in the deque 
    // If this value is too big, then we pop off the back prefix sum until we find one that is compatible 
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n;
        int numbers[n];
        long long prefixSums[n+1];
        int maxElements[n+1];
        int mostElements = 1;
        deque<int> indices;
        int startIndex = 0;
        prefixSums[0] = 0;
        maxElements[0] = 0;
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        cin >> x;
        for (int i = 1; i <= n; i++) {
            prefixSums[i] = prefixSums[i-1] + numbers[i-1] - x;
            if (i >= 2) {
                while (!indices.empty() && prefixSums[indices.front()] <= prefixSums[i-2]) {
                    indices.pop_front();
                }
                indices.push_front(i-2);
                while(!indices.empty() && (prefixSums[indices.back()] > prefixSums[i] ||
                 indices.back() < startIndex)){
                    startIndex = max(startIndex, indices.back() + 1);
                    indices.pop_back();
                }
            }
            maxElements[i] = i - startIndex;
            if (startIndex > 0) {
                maxElements[i] += maxElements[startIndex - 1];
            }
            mostElements = max(mostElements, maxElements[i]);
        }
        cout << mostElements << endl;
    }

    return 0;
}
