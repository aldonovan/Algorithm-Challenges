#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) {
    if(n < m) return gcd(n, m);
    if(n % m == 0) return m;
    return gcd(n%m, m);
}

int main() {
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> s;
        map<pair<int, int>, int> letterCounts;
        int dCount = 0;
        int kCount = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'D') {
                dCount++;
            } else {
                kCount++;
            }
            if(dCount == 0 || kCount == 0) {
                cout << max(dCount, kCount) << " ";
            } else {
                int divisor = gcd(dCount, kCount);
                int dSimplified = dCount / divisor;
                int kSimplified = kCount / divisor;
                pair<int, int> ratio = make_pair(dSimplified, kSimplified);
                letterCounts[ratio]++;
                cout << letterCounts[ratio] << " ";
            }
            if(j == (n - 1)) {
                cout << endl;
            }
        }
    }
    return 0;
}
