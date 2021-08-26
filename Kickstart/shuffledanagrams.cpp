#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        string s;
        vector<pair<int, int> > letterCounts;
        for(int j = 0; j < 26; j++) {
            letterCounts.push_back(make_pair(0, j));
        }
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            letterCounts[s[j]-'a'].first++;
        }
        sort(letterCounts.begin(), letterCounts.end());
        cout << "Case #" << i << ": ";
        if (2*letterCounts[25].first > s.length()) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            string sorted = "";
            for(int j = 0; j < 26; j++) {
                for(int count = 0; count < letterCounts[j].first; count++) {
                    sorted += 'a' + letterCounts[j].second;
                }
            }
            vector<vector<int> > mappedCharacters(26);
            int offset = letterCounts[25].first;
            for(int index = sorted.length() - 1; index >= 0; index--) {
                int mapped = index - offset;
                if (mapped < 0) {
                    mapped += sorted.length();
                }
                mappedCharacters[sorted[index]-'a'].push_back(sorted[mapped]-'a');
            }
            string shuffled = "";
            for(int index = 0; index < s.length(); index++) {
                int letter = s[index]-'a';
                shuffled += 'a' + mappedCharacters[letter][mappedCharacters[letter].size() - 1];
                mappedCharacters[letter].pop_back();
            }
            cout << shuffled << endl;
        }
    }
    return 0;
}