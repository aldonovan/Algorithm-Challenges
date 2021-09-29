#include <bits/stdc++.h>
using namespace std;
int main() {
    // 26! * N is too slow
    // Fewest number of times that we have s[k] < s[k-1] ---- we can fully encapsulate problem with just length 2 substrings
    // Then given an ordering, we can check in O(26^2) how many times the alphabet is said --- takes length out of equation
    // This improves solution to 26! * 26^2 which is still too slow
    // How can we do this without looping over permutations? 
    // Bitmask DP in O(2^n*n^2), can also optimize to O(2^n*n)
    string s;
    cin >> s;
    vector<int> ids(26, -1);
    int id = 0;
    for (int i = 0; i < s.length(); i++) {
        if (ids[s[i]-'a'] == -1) {
            ids[s[i]-'a'] = id;
            id++;
        }
    }
    int n = id;
    vector<vector<int> > numSubstrings(n, vector<int>(n, 0));
    for (int i = 0; i < s.length() - 1; i++) {
        numSubstrings[ids[s[i]-'a']][ids[s[i+1]-'a']]++;
    }
    vector<int> sums(1 << n, INT_MAX);
    sums[0] = 1;
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int bit = 0; bit < n; bit++) {
            if ((mask & (1 << bit)) != 0) {
                int added = sums[mask ^ (1 << bit)];
                for (int index = 0; index < n; index++) {
                    if ((mask & (1 << index)) != 0) {
                        added += numSubstrings[index][bit];
                    }
                }
                sums[mask] = min(sums[mask], added);
            }
        }
    }
    cout << sums[(1 << n) - 1] << endl;
    return 0;
}