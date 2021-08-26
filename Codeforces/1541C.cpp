#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int d[n];
        long long prefixSum[n];
        long long sum = 0;
        for(int j = 0; j < n; j++) {
            cin >> d[j];
        }
        sort(d, d + n);
        prefixSum[0] = d[0];
        for(int j = 1; j < n; j++) {
            prefixSum[j] = prefixSum[j-1] + d[j];
        }
        long long cost = d[n-1];
        for(int index = 1; index < n; index++) {
            long long currCost = d[index];
            currCost *= index;
            currCost -= prefixSum[index - 1];
            cost -= currCost;
        }
        cout << cost << endl;
    }
    return 0;
}
