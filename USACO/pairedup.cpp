#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {
    int t, n, k;
    cin >> t >> n >> k;
    pair<long long, long long> cowPairs[n];
    for (int i = 0; i < n; i++) {
        long long x, weight;
        cin >> x >> weight;
        cowPairs[i] = make_pair(x, weight);
    }
    sort(cowPairs, cowPairs + n);
    vector<pair<long long, long long> > cows;
    long long totalCost = 0;
    for (int i = 0; i < n; i++) {
        if ((i > 0 && cowPairs[i-1].first >= cowPairs[i].first - k) 
            || (i < n - 1 && cowPairs[i+1].first <= cowPairs[i].first + k)) {
            cows.push_back(cowPairs[i]);
        } else {
            totalCost += cowPairs[i].second;
        }
    }
    if (cows.size() == 0) {
        cout << totalCost << endl;
        return 0;
    }
    long long val = (t == 1) ? LLONG_MAX : LLONG_MIN;
    vector<long long> dpWith(cows.size() + 1, val);
    vector<long long> dpWithout(cows.size() + 1, val);
    dpWith[0] = 0;
    dpWithout[0] = 0;
    int lastIndex = 0;
    for (int i = 1; i <= cows.size(); i++) {
        if (i > 1 && cows[i-1].first <= cows[i-2].first + k) {
            dpWithout[i] = (t == 1) ? min(dpWithout[i-2], dpWith[i-2]) : max(dpWithout[i-2], dpWith[i-2]);
            if (i > 2 && cows[i-1].first <= cows[i-3].first + k) {
                long long alternateValue = 0;
                int numRemoved = i - 3 - lastIndex;
                if (numRemoved % 2 == 0) {
                    long long val = (t == 1) ? min(dpWith[lastIndex], dpWithout[lastIndex]) : max(dpWith[lastIndex], dpWithout[lastIndex]);
                    alternateValue = cows[i-2].second + val;
                    dpWithout[i] = (t == 1) ? min(dpWithout[i], alternateValue) : max(dpWithout[i], alternateValue);
                } else if (lastIndex > 0 && cows[lastIndex].first <= cows[lastIndex - 1].first + k) {
                    alternateValue = cows[i-2].second + dpWithout[lastIndex + 1];
                    dpWithout[i] = (t == 1) ? min(dpWithout[i], alternateValue) : max(dpWithout[i], alternateValue);
                }
            }
        }

        while (cows[lastIndex].first < cows[i-1].first - k) {
            lastIndex++;
        }
        int numRemoved = i - 1 - lastIndex;
        if (numRemoved % 2 != 0) {
            if (lastIndex > 0 && cows[lastIndex].first <= cows[lastIndex - 1].first + k) {
                dpWith[i] = cows[i-1].second + dpWithout[lastIndex + 1];
            }
        } else {
            long long val = (t == 1) ? min(dpWith[lastIndex], dpWithout[lastIndex]) : max(dpWith[lastIndex], dpWithout[lastIndex]);
            dpWith[i] = cows[i-1].second + val;
        }
    }
    // for (int i = 1; i <= cows.size(); i++) {
    //     if (i > 1 && cows[i-1].first <= cows[i-2].first + k) {
    //         dpWithout[i] = (t == 1) ? min(dpWithout[i-2], dpWith[i-2]) : max(dpWithout[i-2], dpWith[i-2]);
    //         if (i > 2 && cows[i-1].first <= cows[i-3].first + k) {
    //             long long alternateValue = 0;
    //             int numRemoved = i - 3 - lastIndex;
    //             if (numRemoved % 2 == 0) {
    //                 long long val = (t == 1) ? min(dpWith[lastIndex], dpWithout[lastIndex]) : max(dpWith[lastIndex], dpWithout[lastIndex]);
    //                 alternateValue = cows[i-2].second + val;
    //                 dpWithout[i] = (t == 1) ? min(dpWithout[i], alternateValue) : max(dpWithout[i], alternateValue);
    //             } else if (lastIndex > 0 && cows[lastIndex].first <= cows[lastIndex - 1].first + k) {
    //                 alternateValue = cows[i-1].second + dpWithout[lastIndex + 1];
    //                 dpWithout[i] = (t == 1) ? min(dpWithout[i], alternateValue) : max(dpWithout[i], alternateValue);
    //             }
    //         }
    //     }

    //     while (cows[lastIndex].first < cows[i-1].first - k) {
    //         lastIndex++;
    //     }
    //     int numRemoved = i - 1 - lastIndex;
    //     if (numRemoved % 2 != 0) {
    //         if (lastIndex > 0 && cows[lastIndex].first <= cows[lastIndex - 1].first + k) {
    //             dpWith[i] = cows[i-1].second + dpWithout[lastIndex + 1];
    //         }
    //     } else {
    //         long long val = (t == 1) ? min(dpWith[lastIndex], dpWithout[lastIndex]) : max(dpWith[lastIndex], dpWithout[lastIndex]);
    //         dpWith[i] = cows[i-1].second + val;
    //     }
    // }
    val = (t == 1) ? min(dpWith[cows.size()], dpWithout[cows.size()]) :  max(dpWith[cows.size()], dpWithout[cows.size()]);
    long long answer = totalCost + val;
    cout << answer << endl;
    return 0;
}
