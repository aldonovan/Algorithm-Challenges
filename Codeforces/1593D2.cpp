#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// We return -1 if there is a majority element of the array
// We aim to find the maximum value that can be gcd of at most half of the array
// We start at each possible starting index and find absolute differences of remaining elements
// We create a divisor count using the O(sqrt n) divisor algorithm and keep a running maximum
// of our largest possible gcd that includes at least half of the array 
// Runtime is O(n^2*sqrt(MAX_NUMBER_IN_ARRAY))
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int numbers[n];
        int maximumNum = 0;
        unordered_map<int, int> numCounts;
        bool atLeastHalfSame = false;
        for(int j = 0; j < n; j++) {
            cin >> numbers[j];
            numCounts[numbers[j]]++;
            if (numCounts[numbers[j]] >= n/2) {
                atLeastHalfSame = true;
            }
            maximumNum = max(maximumNum, numbers[j]);
        }
        if (atLeastHalfSame) {
            cout << -1 << endl;
            continue;
        }
        int maximumResult = 0;
        for(int startIndex = 0; startIndex <= (n/2); startIndex++) {
            int threshold = (n/2) - numCounts[numbers[startIndex]];
            unordered_map<int, int> divisorCounts;
            for (int currIndex = startIndex + 1; currIndex != startIndex; currIndex = (currIndex + 1) % n) {
                int difference = abs(numbers[currIndex] - numbers[startIndex]);
                for (int potentialDivisor = 1; potentialDivisor * potentialDivisor <= difference; potentialDivisor++) {
                    if (difference % potentialDivisor == 0) {
                        divisorCounts[potentialDivisor]++;
                        if (potentialDivisor * potentialDivisor != difference) {
                            divisorCounts[difference / potentialDivisor]++;
                        }
                        if (divisorCounts[potentialDivisor] >= threshold) {
                            maximumResult = max(maximumResult, potentialDivisor);
                        }
                        if (divisorCounts[difference / potentialDivisor] >= threshold) {
                            maximumResult = max(maximumResult, difference / potentialDivisor);
                        }
                    }
                }
            }
        }
        cout << maximumResult << endl;
    }
    return 0;
}
