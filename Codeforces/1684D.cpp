#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int values[n];
        pair<int, int> arr[n];
        for (int i = 0; i < n; i++) {
            cin >> values[i];
            arr[i] = make_pair(values[i] + i, i);
        }
        sort(arr, arr + n);
        bool jumpedOver[n];
        for (int i = 0; i < n; i++) {
            jumpedOver[i] = false;
        }
        for (int i = n - 1; i > n - 1 - k; i--) {
            jumpedOver[arr[i].second] = true;
        }
        long long totalDamage = 0;
        int bonusDamage = 0;
        for (int i = 0; i < n; i++) {
            if (jumpedOver[i]) {
                bonusDamage++;
            } else {
                totalDamage += values[i] + bonusDamage;
            }
        }
        cout << totalDamage << endl;
    }
    return 0;
}
