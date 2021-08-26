#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int slimes[n];
    long long prefixSums[n];
    for(int i = 0; i < n; i++) {
        cin >> slimes[i];
        prefixSums[i] = slimes[i];
        if(i > 0) prefixSums[i] += prefixSums[i-1];
    }
    long long costs[n][n];
    for(int i = 0; i < n; i++) {
        costs[i][i] = 0;
    }
    for(int length = 2; length <= n; length++) {
        for(int startIndex = 0; startIndex <= n-length; startIndex++) {
            long long minCost = 1e20;
            int endIndex = startIndex + length - 1;
            for(int splitIndex = startIndex; splitIndex < endIndex; splitIndex++) {
                minCost = min(minCost, costs[startIndex][splitIndex] + costs[splitIndex + 1][endIndex]);
            }
            minCost += prefixSums[endIndex];
            if(startIndex > 0) minCost -= prefixSums[startIndex - 1];
            costs[startIndex][endIndex] = minCost;
        }
    }
    cout << costs[0][n-1] << endl;
    return 0;
}
