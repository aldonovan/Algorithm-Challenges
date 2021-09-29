#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int totalOperations = 0;
    for (int i = n - x; i < n; i++) {
        if (i == n - 1 - y) {
            if (s[i] == '0') {
                totalOperations++;
            }
        } else if (s[i] != '0') {
            totalOperations++;
        }
    }
    cout << totalOperations << endl;
    return 0;
}