// For a given index, want to find the range of x that results in HiLo ending at index
// Can add changes to hiloSums
// To find interval that forms hilo, we need for the current index to be lo
// and the last stated value to be lo. To be lo, we need x >= currVal and 
// x < nextGreatestVal, where nextGreatestVal is the closest value greater than 
// than currVal in sorted order that appears earlier in the list. 
// 
// 5 1 2 4 3 ->  [1, 4] -> skip -> skip -> [3, 3] -> 0, 1, 1, 2, 1, 0
// 5 3 4 1 2 ->  [3, 4] -> skip -> [1, 2] -> skip -> 0, 1, 1, 1, 1, 0

// Algorithm: For each index starting at the second, find the index of the 
// of the value that is next in sorted order (behind in the list) and 
// the value that is before in sorted order (behind in the list). 
// If it is the biggest value, skip. Otherwise, if the index of the first
// is greater than of the second (or the second doesn't exist), then
// we add [currVal, nextGreaterVal -  1] as an interval. Then we do the interval counting trick

// We can keep an array that stores mappings from value to index -> this is for index lookups
// We can use an ordered set I guess for the value lookups

#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int hiloSums[n+1];
    for (int i = 0; i < n + 1; i++) {
        hiloSums[i] = 0;
    }

    int valueToIndex[n + 1];
    set<int> seenValues;
    for (int i = 0; i < n; i++) {
        auto it = seenValues.upper_bound(numbers[i]);
        if (it != seenValues.end()) {
            int nextLargerValue = *it;
            if (it == seenValues.begin()) {
                hiloSums[numbers[i]]++;
                hiloSums[nextLargerValue]--;
            } else {
                it--;
                int nextSmallerValue = *it;
                int nextSmallerIndex = valueToIndex[nextSmallerValue];
                int nextLargerIndex = valueToIndex[nextLargerValue];
                if (nextLargerIndex > nextSmallerIndex) {
                    hiloSums[numbers[i]]++;
                    hiloSums[nextLargerValue]--;
                }
            }
        }
        valueToIndex[numbers[i]] = i;
        seenValues.insert(numbers[i]);
    }

    int runningTotal = 0;
    for (int x = 0; x <= n; x++) {
        runningTotal += hiloSums[x];
        cout << runningTotal << endl;
    }

    return 0;
}

