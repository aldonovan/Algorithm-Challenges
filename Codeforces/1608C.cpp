#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int numPlayers;
        cin >> numPlayers;
        pair<int, int> strengths[numPlayers];
        pair<int, int> firstStrengths[numPlayers];
        pair<int, int> secondStrengths[numPlayers];
        bool canWin[numPlayers];
        int temp;
        for (int j = 0; j < numPlayers; j++) {
            cin >> temp;
            firstStrengths[j] = {temp, j};
            strengths[j] = make_pair(temp, 0);
            canWin[j] = false;
        }
        for (int j = 0; j < numPlayers; j++) {
            cin >> temp;
            secondStrengths[j] = {temp, j};
            strengths[j].second = temp;
        }
        sort(firstStrengths, firstStrengths + numPlayers);
        sort(secondStrengths, secondStrengths + numPlayers);
        int firstIndex = numPlayers - 1;
        int secondIndex = numPlayers - 1;
        int firstLimit = strengths[secondStrengths[secondIndex].second].first;
        int secondLimit = strengths[firstStrengths[firstIndex].second].second;
        while ((firstIndex >= 0 && firstStrengths[firstIndex].first >= firstLimit) ||
            (secondIndex >= 0 && secondStrengths[secondIndex].first >= secondLimit)) {
                if (firstIndex >= 0 && firstStrengths[firstIndex].first >= firstLimit) {
                    int currIndex = firstStrengths[firstIndex].second;
                    canWin[currIndex] = true;
                    secondLimit = min(secondLimit, strengths[currIndex].second);
                    firstIndex--;
                } else {
                    int currIndex = secondStrengths[secondIndex].second;
                    canWin[currIndex] = true;
                    firstLimit = min(firstLimit, strengths[currIndex].first);
                    secondIndex--;
                }
        }
        for (int j = 0; j < numPlayers; j++) {
            if (canWin[j]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
    return 0;
}
