#include <iostream>
#include <climits>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        long long x[n];
        long long prefixSums[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            prefixSums[i] = x[i];
            if (i < n - 1) {
                prefixSums[i] += prefixSums[i+1];
            }
        }
        long long minCost = prefixSums[0]*b;
        long long incurredCost = 0;
        for (int i = 0; i < n; i++) {
            long long currIncurredCost = x[i];
            if (i > 0) {
                currIncurredCost -= x[i-1];
            }
            currIncurredCost *= b;
            incurredCost += currIncurredCost;
            long long currCost = incurredCost + a*x[i];
            if (i < n - 1) {
                currCost += b*(prefixSums[i + 1] - (n-1-i)*x[i]);
            }
            if (currCost < minCost) {
                minCost = currCost;
            }
        }
        cout << minCost << endl;
    }
    return 0;
}
