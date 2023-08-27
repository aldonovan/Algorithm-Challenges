#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main() {
    long long n;
    cin >> n;
    long long newN = n;
    vector<int> digits;
    bool used[10] = {false, false, false, false, false, false, false, false, false, false};
    int totalUsed = 0;
    while (newN > 0) {
        digits.push_back(newN % 10);
        if (used[newN%10] == false) {
            totalUsed++;
        }
        used[newN % 10] = true;
        newN /= 10;
    }
    if (totalUsed == 10) {
        cout << "Impossible" << endl;
        return 0;
    }
    int biggestUnused = 0;
    for (int i = 1; i <= 9; i++) {
        if (used[i] == false) {
            biggestUnused = i;
        }
    }
    int smallestUnused = 9;
    for (int i = 8; i >= 0; i--) {
        if (used[i] == false) {
            smallestUnused = i;
        }
    }
    int smallestUnusedGreaterThanZero = 10;
    for (int i = 8; i > 0; i--) {
        if (used[i] == false) {
            smallestUnusedGreaterThanZero = i;
        }
    }
    long long lesserNumber = -2;
    long long greaterNumber = -2;
    int firstDigit = digits[digits.size() - 1];
    int firstCompatible = firstDigit - 1;
    int numDigits = digits.size();
    while(firstCompatible >= 0 && used[firstCompatible]) {
        firstCompatible--;
    }
    if (firstCompatible <= 0) {
        if (n < 10) {
            cout << n - 1 << " " << n + 1 << endl;
            return 0;
        } else {
            long long result = 0;
            for (int i = 0; i < numDigits - 1; i++) {
                result = (10*result) + biggestUnused;
            }
            lesserNumber = result;
        }
    } else {
        long long result = firstCompatible;
        for (int i = 0; i < numDigits - 1; i++) {
            result = (10*result) + biggestUnused;
        }
        lesserNumber = result;
    }

    int firstGreaterCompatible = firstDigit + 1;
    while (firstGreaterCompatible <= 9 && used[firstGreaterCompatible]) {
        firstGreaterCompatible++;
    }
    if (firstGreaterCompatible > 9) {
        long long result = smallestUnusedGreaterThanZero;
        if (result == 10) {
            greaterNumber = LLONG_MAX;
        } else {
            for (int i = 0; i < numDigits; i++) {
                result = (10*result) + smallestUnused;
             }
            greaterNumber = result;
        }
    } else {
        long long result = firstGreaterCompatible;
        for (int i = 0; i < numDigits - 1; i++) {
            result = (10*result) + smallestUnused;
        }
        greaterNumber = result;
    }
    long long firstDiff = abs(n - lesserNumber);
    long long secondDiff = abs(greaterNumber - n);
    if (firstDiff == secondDiff) {
        cout << lesserNumber << " " << greaterNumber << endl;
    } else if (firstDiff < secondDiff) {
        cout << lesserNumber << endl;
    } else {
        cout << greaterNumber << endl;
    }
    return 0;
}
