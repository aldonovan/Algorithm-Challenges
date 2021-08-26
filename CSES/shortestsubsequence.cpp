#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int counts[26];
int main() {
    string seq;
    cin >> seq;
    for(int i = 0; i < 26; i++) counts[i] = 0;
    string shortestNotPresent = "";
    int currIndex = 0;
    int numChars = 0;
    while(currIndex < seq.length()) {
        if(counts[seq[currIndex]-'A'] == 0) {
            numChars++;
            counts[seq[currIndex]-'A']++;
        }
        if(numChars == 4) {
            shortestNotPresent += seq[currIndex];
            counts[0] = counts[2] = counts[6] = counts[19] = 0;
            numChars = 0;
        }
        currIndex++;
    }
    char letters[4] = {'A', 'C', 'G', 'T'};
    for(char letter: letters) {
        if(counts[letter - 'A'] == 0) {
            shortestNotPresent += letter;
            break;
        }
    }
    cout << shortestNotPresent << endl;
    return 0;
}
