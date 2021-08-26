#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int lcs[s.length() + 1][t.length() + 1];
    for(int i = 0; i <= t.length(); i++) lcs[0][i] = 0;
    for(int i = 0; i <= s.length(); i++) lcs[i][0] = 0;
    for(int i = 1; i <= s.length(); i++) {
        for(int j = 1; j <= t.length(); j++) {
            if(s[i-1] == t[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    string subseq = "";
    int remainingLength = lcs[s.length()][t.length()];
    int i = s.length(), j = t.length();
    while(i >= 1 && j >= 1) {
        if(s[i-1] == t[j-1]) {
            subseq += s[i-1];
            remainingLength--;
            i--;
            j--;
        } else {
            if(lcs[i-1][j] == remainingLength) {
                i--;
            } else {
                j--;
            }
        } 
    }
    reverse(subseq.begin(), subseq.end());
    cout << subseq << endl;
    return 0;
}