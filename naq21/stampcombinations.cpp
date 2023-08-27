#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    int clusters[m];
    unordered_map<int, int> prefixSums;
    prefixSums[0] = -1;
    int runningSum = 0;
    for (int i = 0; i < m; i++) {
        cin >> clusters[i];
        runningSum += clusters[i];
        if (prefixSums.find(runningSum) == prefixSums.end()) {
            prefixSums[runningSum] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int currQuery;
        cin >> currQuery;
        if (prefixSums.count(currQuery)) {
            cout << "Yes" << endl;
        } else {
            int remainingTotal = currQuery;
            bool found = false;
            for (int index = m - 1; index > 0; index--) {
                remainingTotal -= clusters[index];
                if (prefixSums.find(remainingTotal) != prefixSums.end()) {
                    if(prefixSums[remainingTotal] < index) {
                        cout << "Yes" << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
