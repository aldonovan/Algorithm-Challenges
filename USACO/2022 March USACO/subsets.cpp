#include <iostream>
using namespace std;
int main() {
    string s, t;
    int q;
    cin >> s >> t >> q;
    bool compatibility[18][18];
    bool singleLetterCompatibility[18];
    for (int i = 0; i < 18; i++) {
        for (int j = i + 1; j < 18; j++) {
            char firstChar = 'a' + i;
            char secondChar = 'a' + j;
            // Check compatibility
            string s1 = "";
            for (int index = 0; index < s.length(); index++) {
                if (s[index] == firstChar || s[index] == secondChar) {
                    s1 += s[index];
                }
            }
            string s2 = "";
            for (int index = 0; index < t.length(); index++) {
                if (t[index] == firstChar || t[index] == secondChar) {
                    s2 += t[index];
                }
            }
            if (s1.compare(s2) == 0) {
                compatibility[i][j] = true;
                compatibility[j][i] = true;
            } else {
                compatibility[i][j] = false;
                compatibility[j][i] = false;
            }
        }
    }
    for (int i = 0; i < 18; i++) {
        char currLetter = 'a' + i;
        string s1 = "";
        for (int index = 0; index < s.length(); index++) {
            if (s[index] == currLetter) {
                s1 += currLetter;
            }
        }
        string s2 = "";
        for (int index = 0; index < t.length(); index++) {
            if (t[index] == currLetter) {
                s2 += currLetter;
            }
        }
        if (s1.compare(s2) == 0) {
            singleLetterCompatibility[i] = true;
        } else {
            singleLetterCompatibility[i] = false;
        }
    }
    for (int i = 0; i < q; i++) {
        string query;
        cin >> query;
        bool compatible = true;
        for (int index = 0; index < query.length(); index++) {
            if (!singleLetterCompatibility[query[index]-'a']) {
                compatible = false;
                break;
            }
        }
        if (compatible) {
            for (int index = 0; index < query.length() - 1; index++) {
                for (int secondIndex = index + 1; secondIndex < query.length(); secondIndex++) {
                    if (!compatibility[query[index]-'a'][query[secondIndex]-'a']) {
                        compatible = false;
                        break;
                    }
                }
            }
        }
        if (compatible) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    cout << "\n";
    return 0;
}
