#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int a[n];
        vector<pair<long long, int>> sums;
        cin >> a[0];
        sums.push_back(make_pair((long long)a[0], 0));
        long long sum = a[0];
        for(int j = 1; j < n; j++) {
            cin >> a[j];
            sum += a[j];
            if(sum > sums[sums.size() - 1]) {
                sums.push_back(make_pair(sum, j));
            }
        }
        for(int j = 0; j < m; j++) {
            int size;
            cin >> size;
        }
    }
    return 0;
}