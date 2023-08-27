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
        int maxElements[n+1];
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        cin >> x;
        maxElements[0] = 0;
        maxElements[1] = 1;
        for (int i = 2; i <= n; i++) {
            int difference = numbers[i-1] - x;
            if (difference >= 0) {
                maxElements[i] = maxElements[i-1] + 1;
            } else {
                if (numbers[i-1] + numbers[i-2] < 0) {
                    
                }
            }
        }
        cout << mostElements << endl;
    }

    return 0;
}
