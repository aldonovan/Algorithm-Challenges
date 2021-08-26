#include <iostream>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int numbers[n];
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    int startIndex = 0;
    int maxOccurrences = 1;
    int maxOccurringNumber = numbers[0];
    long long usedOperations = 0;
    for(int endIndex = 1; endIndex < n; endIndex++) {
        long long difference = numbers[endIndex] - numbers[endIndex - 1];
        usedOperations += (endIndex - startIndex) * difference;
        while(usedOperations > k) {
            usedOperations -= (numbers[endIndex] - numbers[startIndex]);
            startIndex++;
        }
        int numOccurrences = endIndex - startIndex + 1;
        if(numOccurrences > maxOccurrences) {
            maxOccurrences = numOccurrences;
            maxOccurringNumber = numbers[endIndex];
        }
    }
    cout << maxOccurrences << " " << maxOccurringNumber << endl;
    return 0;
}