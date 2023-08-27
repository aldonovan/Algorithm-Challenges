#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int predictions[n];
        for (int i = 0; i < n; i++) {
            cin >> predictions[i];
        }
        string s;
        cin >> s;
        vector<pair<int, int>> liked;
        vector<pair<int, int>> disliked;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                liked.push_back({predictions[i], i});
            } else {
                disliked.push_back({predictions[i], i});
            }
        }
        sort(liked.begin(), liked.end());
        sort(disliked.begin(), disliked.end());
        int newPredictions[n];
        int currValue = n;
        for(int i = liked.size() - 1; i >= 0; i--) {
            newPredictions[liked[i].second] = currValue;
            currValue--;
        }
        for (int i = disliked.size() - 1; i >= 0; i--) {
            newPredictions[disliked[i].second] = currValue;
            currValue--;
        }
        for (int i = 0; i < n; i++) {
            cout << newPredictions[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
