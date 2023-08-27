#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n;
        cin >> n;
        pair<int, int> ranges[n];
        for (int i = 0; i < n; i++) {
            int first, second; 
            cin >> first >> second;
            ranges[i] = {first, second};
        }
        for (int i = 0; i < n; i++) {
            cout << ranges[i].first << " " << ranges[i].second << " ";
            if (ranges[i].first == ranges[i].second) {
                cout << ranges[i].first << endl;
            } else {
                bool firstCase = false;
                bool secondCase = false;
                int firstValue = INT_MIN;
                int secondValue = INT_MAX;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        if (ranges[j].first == ranges[i].first && ranges[j].second < ranges[i].second) {
                            firstCase = true;
                            firstValue = max(firstValue, ranges[j].second + 1);
                        } else if (ranges[j].second == ranges[i].second && ranges[j].first > ranges[i].first) {
                            secondCase = true;
                            secondValue = min(secondValue, ranges[j].first - 1);
                        }
                    }
                }
                if (firstCase) {
                    cout << firstValue << endl;
                } else {
                    cout << secondValue << endl;
                }
            }
        }
    }
    return 0;
}
