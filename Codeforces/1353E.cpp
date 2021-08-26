#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t; 
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int oneCount = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '1') {
                oneCount++;
            } 
        }
        int minMoves = 1e9;
        for(int rem = 0; rem <= k - 1; rem++) {
            int prefixSum = 0;
            int minPrefixSum = 0;
            int maxValue = 0;
            for(int currIndex = rem; currIndex < s.length(); currIndex += k) {
                if(s[currIndex] == '1') {
                    prefixSum++;
                    maxValue = max(maxValue, prefixSum - minPrefixSum);
                } else {
                    prefixSum--;
                    minPrefixSum = min(minPrefixSum, prefixSum);
                }
            }
            minMoves = min(minMoves, oneCount - maxValue);
        }
        cout << minMoves << endl;
    }
    return 0;
}
