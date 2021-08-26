#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long low = 1;
    long long high = n*n;
    long long numGreater = (n*n - 1) / 2 + 1;
    long long middle = 0;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        long long numLessThanOrEqual = 0;
        for(int i = 1; i <= sqrt(mid); i++) {
            numLessThanOrEqual += 2*(min((mid / i), n) - i) + 1;
        }
        if(numLessThanOrEqual >= numGreater) {
            middle = mid;
            high = mid - 1;
        } else if(numLessThanOrEqual < numGreater) {
            low = mid + 1;
        }
    }
    cout << middle << endl;
    return 0;
}