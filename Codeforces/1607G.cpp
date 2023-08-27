#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        long long n, m, a, b;
        cin >> n >> m;
        long long overallBalance = 0;
        long long minimumA = 0;
        long long maximumA = 0;
        for(int j = 0; j < n; j++) {
            cin >> a >> b;
            overallBalance += a - b;
            minimumA += max(0LL, m - b);
            maximumA += min(m, a);
        }
        long long minimumB = m*n - maximumA;
        long long maximumB = m*n - minimumA;
        long long firstExtreme = overallBalance + minimumA - maximumB;
        long long secondExtreme = overallBalance + maximumA - minimumB;
        if ((secondExtreme <= 0 && firstExtreme <= 0) || (secondExtreme >= 0 && firstExtreme >= 0)) {
            if (abs(firstExtreme) < abs(secondExtreme)) {
                // Return firstExtreme
                cout << firstExtreme;
            } else {
                // Return secondExtreme
                cout << secondExtreme;
            }
        } else {
            // Can get close to 0
        }
    }
    return 0;
}
