#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int nums[n];
        int smallestNumberInArray = INT_MAX;
        for (int j = 0; j < n; j++) {
            cin >> nums[j];
            smallestNumberInArray = min(smallestNumberInArray, nums[j]);
        }
        vector<int> divisibleByMinValue;
        for (int j = 0; j < n; j++) {
            if (nums[j] % smallestNumberInArray == 0) {
                divisibleByMinValue.push_back(nums[j]);
            }
        }
        sort(divisibleByMinValue.begin(), divisibleByMinValue.end());
        int previousValue = INT_MIN;
        int sortedIndex = 0;
        bool success = true;
        for (int j = 0; j < n; j++) {
            if (nums[j] % smallestNumberInArray == 0) {
                int newNumber = divisibleByMinValue[sortedIndex];
                sortedIndex++;
                if (newNumber < previousValue) {
                    success = false;
                    break;
                } else {
                    previousValue = newNumber;
                }
            } else {
                if (nums[j] < previousValue) {
                    success = false;
                    break;
                } else {
                    previousValue = nums[j];
                }
            }
        }
        if (success) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}
