#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
#include <limits.h>
#include <vector>
using namespace std;
int main() {
    int strings[6];
    for(int i = 0; i < 6; i++) {
        cin >> strings[i];
    }
    vector<pair<int, int> > noteCombinations;
    int n, currNote;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> currNote;
        for(int j = 0; j < 6; j++) {
            noteCombinations.push_back(make_pair(currNote - strings[j], i));
        }
    }
    sort(noteCombinations.begin(), noteCombinations.end());
    int minDifference = INT_MAX;
    int startIndex = 0;
    unordered_map<int, int> notes;
    for(int endIndex = 0; endIndex < noteCombinations.size(); endIndex++) {
        notes[noteCombinations[endIndex].second]++;
        while(notes.size() == n) {
            minDifference = min(minDifference, noteCombinations[endIndex].first - noteCombinations[startIndex].first);
            int firstNote = noteCombinations[startIndex].second;
            notes[firstNote]--;
            if(notes[firstNote] == 0) notes.erase(firstNote);
            startIndex++;
        }
    }
    cout << minDifference << endl;
    return 0;
}
