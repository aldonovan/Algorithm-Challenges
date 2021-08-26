#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int palCharacteristic[s.length()][s.length()];
    vector<int> numPalCharacteristics(s.length(), 0);
    numPalCharacteristics[0] = s.length();
    for (int i = 0; i < s.length(); i++) {
        palCharacteristic[i][i] = 1;
        if (i > 0) {
            palCharacteristic[i-1][i] = (s[i] == s[i-1]) ? 2 : 0;
            numPalCharacteristics[palCharacteristic[i-1][i] - 1]++;
        }
    }
    for (int offset = 2; offset < s.length(); offset++) {
        for (int start = 0; start <= s.length() - 1 - offset; start++) {
            if (s[start] != s[start + offset] || palCharacteristic[start + 1][start + offset - 1] == 0) {
                palCharacteristic[start][start+offset] = 0;
            } else {
                int mid = ceil((start + 0.0 + start + offset) / 2.0) - 1;
                palCharacteristic[start][start+offset] = palCharacteristic[start][mid] + 1;
                numPalCharacteristics[palCharacteristic[start][start+offset]-1]++;
            }
        }
    }
    for (int characteristic = s.length() - 2; characteristic >= 0; characteristic--) {
        numPalCharacteristics[characteristic] += numPalCharacteristics[characteristic + 1];
    }
    for (int characteristic = 0; characteristic < s.length(); characteristic++) {
        cout << numPalCharacteristics[characteristic] << " ";
    }
    cout << endl;
    return 0;
}