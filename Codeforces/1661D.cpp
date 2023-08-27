#include <iostream>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    long long b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long numBlocks[n];
    for (int i = 0; i < n; i++) {
        numBlocks[i] = 0;
    }
    long long totalOperations = 0;
    long long currNumCoverings = 0;
    long long currValueTotal = 0;
    for (int i = n - 1; i >= k; i--) {
        currValueTotal -= currNumCoverings;
        currNumCoverings -= numBlocks[i];
        long long remaining = b[i] - currValueTotal;
        if (remaining > 0) {
            long long added = remaining / k;
            if (remaining % k != 0) {
                added++;
            }
            currNumCoverings += added;
            totalOperations += added;
            if (i >= k) {
                numBlocks[i - k] += added;
            }
            currValueTotal += k*added;
        }
    }
    long long mostOperations = INT_MIN;
    for (int i = k - 1; i >= 0; i--) {
        currValueTotal -= currNumCoverings;
        currNumCoverings -= numBlocks[i];
        long long remaining = b[i] - currValueTotal;
        if (remaining > 0) {
            long long numOperations = remaining / (i + 1);
            if (remaining % (i + 1) != 0) {
                numOperations++;
            }
            mostOperations = max(mostOperations, numOperations);
        }
    }
    if (mostOperations > 0) {
        totalOperations += mostOperations;
    }
    cout << totalOperations << endl;
    return 0;
}
