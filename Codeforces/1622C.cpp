#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        long long numbers[n];
        long long sum = 0LL;
        for (int j = 0; j < n; j++) {
            cin >> numbers[j];
            sum += numbers[j];
        }
        sort(numbers, numbers + n);
        long long minOperations = max(sum - k, 0LL);
        sum -= numbers[0];
        for (int numSwaps = 1; numSwaps <= n - 1; numSwaps++) {
            sum -= numbers[n - numSwaps];
            long long remainingValues = k - sum;
            if (remainingValues % (numSwaps + 1) != 0 && remainingValues < 0) {
                remainingValues = (remainingValues / (numSwaps + 1)) - 1;
            } else {
                remainingValues = remainingValues / (numSwaps + 1);
            }
            long long numOperations = max (numbers[0] - remainingValues, 0LL) + numSwaps;
            minOperations = min(minOperations, numOperations);
        }
        cout << minOperations << endl;
    }
    return 0;
}
