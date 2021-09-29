#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int nums[n][m];
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> nums[j][k];
            }
        }
        bool success = true;
        for (int j = 0; j < n; j++) {
            if (!success) {
                break;
            }
            for(int k = 0; k < m; k++) {
                int numNeighbors = 0;
                if (k < m - 1) {
                    numNeighbors++;
                }
                if (k > 0) {
                    numNeighbors++;
                }
                if (j > 0) {
                    numNeighbors++;
                }
                if (j < n - 1) {
                    numNeighbors++;
                }
                if (numNeighbors < nums[j][k]) {
                    cout << "NO" << endl;
                    success = false;
                    break;
                } else {
                    nums[j][k] = numNeighbors;
                }
            }
        }
        if (success) {
            cout << "YES" << endl;
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++) {
                    cout << nums[j][k] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}