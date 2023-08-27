#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        int minSteps = INT_MAX;
        if (cd >= cb) {
            minSteps = min(minSteps, cd - cb);
        } else {
            minSteps = min(minSteps, 2*(m - cb) + cb - cd);
        }

        if (rd >= rb) {
            minSteps = min(minSteps, rd - rb);
        } else {
            minSteps = min(minSteps, 2*(n - rb) + rb - rd);
        }
        cout << minSteps << endl;
    }
    return 0;
}