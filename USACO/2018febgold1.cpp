#include <bits/stdc++.h>
using namespace std;
int main() {
    // If we were to fix the max depth of the boots, then we need to get all of the indices <= that depth
    // Then we can go from 0 to n if the max difference between indices is at most d_i
    int n, b;
    cin >> n >> b;
    pair<int, int> depths[n];
    for (int i = 0; i < n; i++) {
        int depth;
        cin >> depth;
        depths[i] = make_pair(depth, i);
    }
    sort(depths, depths + n);
    pair<pair<int, int>, int> boots[b];
    for (int i = 0; i < b; i++) {
        int depth, step;
        cin >> depth >> step;
        boots[i] = make_pair(make_pair(depth, step), i);
    }
    sort(boots, boots + n);
    int maxDifferences[n];
    maxDifferences[0] = 0;
    for (int i = 1; i < n; i++) {
        maxDifferences[i] = max(maxDifferences[i-1], depths[i].first - depths[i-1].first);
    }
    set<int> indices;
    int depthsIndex = n - 1;
    int maxDiff = INT_MAX;
    int results[b];
    for (int i = b - 1; i >= 0; i--) {
        pair<pair<int, int>, int> boot = boots[i];
        while (depthsIndex >= 0 )
    }
    for (int i = 0; i < b; i++) {
        cout << results[i] << endl;
    }
    return 0;
}
