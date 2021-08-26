#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int a[n];
        int mapValueToIndex[2*n];
        for(int j = 0; j < 2*n; j++) {
            mapValueToIndex[j] = -1;
        }
        for(int j = 0; j < n; j++) {
            cin >> a[j];
            mapValueToIndex[a[j] - 1] = j + 1;
        }
        int numPairs = 0;
        for(int product = 1; product <= 2*n - 1; product++) {
            for(int factor = 1; factor < sqrt(product); factor++) {
                if(product % factor == 0) {
                    int firstIndex = mapValueToIndex[factor - 1];
                    int secondIndex = mapValueToIndex[product / factor - 1];
                    if(firstIndex != -1 && secondIndex != -1 && firstIndex + secondIndex == product) numPairs++;
                }
            }
        }
        cout << numPairs << endl;
    }
    return 0;
}
