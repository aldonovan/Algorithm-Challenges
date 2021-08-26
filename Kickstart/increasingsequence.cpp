#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
using namespace std;
int main() {
    cout << fixed << setprecision(12);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        long long n;
        cin >> n;
        cout << "Case #" << i << ": ";
        if (n <= 1000000) {
            double value = 1;
            for (int num = 2; num <= n; num++) {
                value += (1.0) / num;
            }
            cout << value << endl;
        } else {
            double value = log(n);
            value += 0.5772156649015328606065;
            value += (1.0) / (2*n) - (1.0) / (12*n*n);
            cout << value << endl;
        }
        
        // 4 3 2 1 5 -> 4 5
        // 3 1 5 2 4 -> 3 5
        // We can essentially disregard all cards less than first card
        // If first card is 1, expected value is 1 + E(N - 1)
        // If first card is 2, expected value is 1 + E(N - 2)
        // If first card is N - 1, expected value is 1 + E(1)
        // If first card is N, expected value is 1
        // E(N) = 1 + 1/N * (E(1) + E(2) + ... + E(N-1))
        // E(N-1) = 1 + (1/(N-1)*(E(1) + ... + E(N-2)))
        // E(N) = 1 + (E(N-1)-1)*((N-1)/N) + 1/N*(E(N-1))
        // E(N) = 1/N + E(N-1)
        // E(N) = 1 + 1/2 + ... + 1/N 
    }
    return 0;
}