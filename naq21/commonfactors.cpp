#include <iostream>
using namespace std;

long long gcd (long long a, long long b) {
    long long temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    long long n;
    cin >> n;
    long long currentProduct = 1LL;
    long long numerator = 1LL;
    long long denominator = 1LL;
    int primes[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    for (int i = 0; i < 16; i++) {
        if (currentProduct <= n && (currentProduct*primes[i] <= n) && (currentProduct < 1e17)) {
            currentProduct *= primes[i];
            numerator *= (primes[i]- 1);
            denominator *= primes[i];
        }
    }
    numerator = denominator - numerator;
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    cout << numerator << '/' << denominator << endl;
    return 0;
}


// (p-1) / p
// 1 -  product (1 - 1/p)
// 2, 3, 5, 7
// 1 - 1/2 = 1/2 -> 1/2
// 1 - 1/3 = 2/3 -> 1/3
// 1 - 1/5 = 4/5 -> 1/5
// 1 - 1/7 = 6/7 -> 1/7
// 1 - (1/2*2/3) = 2/3 -> answer is 2/3 
// 1 - (1/2*2/3*4/5) = 22/30 -> answer is 11/15