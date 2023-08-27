#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> characterCounts(26, 0);
    int numDistinct = 0;
    for (int i = 0; i < s.length(); i++) {
        if (characterCounts[s[i]-'a'] == 0) {
            numDistinct++;
        }
        characterCounts[s[i]-'a']++;
    }
    cout << numDistinct << endl;
    // Number of substrings with k letters = num strings <= k - num strings <= k - 1
    long long numPrevious = 0LL;
    for (int numLetters = 1; numLetters <= numDistinct; numLetters++) {
        int firstIndex = 0;
        vector<int> charCounts(26, 0);
        int numDifferent = 0;
        long long numSubstrings = 0;
        for (int lastIndex = 0; lastIndex < s.length(); lastIndex++) {
            if (charCounts[s[lastIndex]-'a'] == 0) {
                numDifferent++;
            }
            charCounts[s[lastIndex]-'a']++;
            while (numDifferent > numLetters) {
                charCounts[s[firstIndex]-'a']--;
                if (charCounts[s[firstIndex]-'a'] == 0) {
                    numDifferent--;
                }
                firstIndex++;
            }
            numSubstrings += lastIndex - firstIndex + 1;
        }
        cout << numSubstrings - numPrevious << endl;
        numPrevious = numSubstrings;
    }
    return 0;
}
