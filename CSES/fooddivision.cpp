#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int firstList[n];
    for (int i = 0; i < n; i++) {
        cin >> firstList[i];
    }
    long long prefixSums[n];
    cin >> prefixSums[0];
    prefixSums[0] = firstList[0] - prefixSums[0];
    for (int i = 1; i < n; i++) {
        int secondListNum;
        cin >> secondListNum;
        prefixSums[i] = prefixSums[i-1] + firstList[i] - secondListNum;
    }
    sort (prefixSums, prefixSums + n);
    int prefixSumMedian = prefixSums[((n + 1) / 2) - 1];
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += abs(prefixSums[i] - prefixSumMedian);
    }
    cout << answer << endl;
    return 0;
}
