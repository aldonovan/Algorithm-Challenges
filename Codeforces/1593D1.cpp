#include <bits/stdc++.h>
using namespace std;

int gcd(int first, int second) {
    if (first <= second) {
        if (second % first == 0) {
            return first;
        }
        return gcd(second % first, first);
    }
    return gcd(second, first);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        bool allSame = true;
        int divisor = -1;
        int firstValue = 0;
        for(int j = 0; j < n; j++) {
            if (j == 0) {
                cin >> firstValue;
            } else {
                int currValue;
                cin >> currValue;
                if (currValue != firstValue) {
                    if (allSame) {
                        divisor = abs(currValue - firstValue);
                        allSame = false;
                    } else {
                        divisor = gcd(divisor, abs(currValue - firstValue));
                    }
                }
            }
        }
        cout << divisor << endl;
    }
    return 0;
}
