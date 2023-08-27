#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k, d;
    cin >> n >> k >> d;
    int pencils[n];
    for (int i = 0; i < n; i++) {
        cin >> pencils[i];
    }
    sort(pencils, pencils + n);
    queue<int> possible;
    possible.push(-1);
    int lastPossible = 0;
    while(!possible.empty()) {
        int currIndex = possible.front();
        possible.pop();
        lastPossible = max(lastPossible, currIndex + k);
        while (lastPossible < n && (pencils[lastPossible] - pencils[currIndex + 1] <= d)) {
            possible.push(lastPossible);
            if (lastPossible == n - 1) {
                cout << "YES" << endl;
                return 0;
            }
            lastPossible++;
        }
    }
    cout << "NO" << endl;
    return 0;
}
