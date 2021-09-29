#include <bits/stdc++.h>
using namespace std;

int findDistance(int p1, int p2, int n) {
    return min(abs(p2 - p1), n - abs(p2 - p1));
}

int main() {
    int n, p;
    string s;
    cin >> n >> p >> s;
    p--;
    int numberOfVerticalPresses = 0;
    int lowestChangedIndex = n;
    int highestChangedIndex = 0;
    bool isPalindrome = true;
    for (int i = 0; i < s.length() / 2; i++) {
        int firstLetter = s[i] - 'a';
        int correspondingLetter = s[n - 1 - i] - 'a';
        int distance = abs (firstLetter - correspondingLetter);
        distance = min(distance, 26 - distance);
        numberOfVerticalPresses += distance;
        if (distance > 0) {
            isPalindrome = false;
            lowestChangedIndex = min(lowestChangedIndex, i);
            highestChangedIndex = i;
        }
    }
    if (isPalindrome) {
        cout << 0 << endl;
    } else {
        int alternateHighestChangedIndex = n - 1 - lowestChangedIndex;
        int alternateLowestChangedIndex = n - 1 - highestChangedIndex;
        int minDistance = min(findDistance(p, lowestChangedIndex, n), findDistance(p, highestChangedIndex, n));
        minDistance = min(minDistance, min(findDistance(p, alternateLowestChangedIndex, n), findDistance(p, alternateHighestChangedIndex, n)));
        int minHorizontalPresses = minDistance + highestChangedIndex - lowestChangedIndex;
        cout << numberOfVerticalPresses + minHorizontalPresses << endl;
    }
    return 0;
}