#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int heights[n];
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    sort(heights, heights + n);
    int longestCircle = 0;
    int firstIndex = 0;
    int lastIndex = 0;
    int lastOne = 0;
    int index = 0;
    while (index < n) {
        if (index > 0 && heights[index - 1] < heights[index] - 1) {
            lastOne = index;
        }
        int currCount = 1;
        while (index < n - 1 && heights[index + 1] == heights[index]) {
            currCount++;
            index++;
        }
        if (index - lastOne + 1 > longestCircle) {
            firstIndex = lastOne;
            lastIndex = index;
            longestCircle = index - lastOne + 1;
        }
        if (currCount == 1) {
            lastOne = index;
        }
        index++;
    }
    cout << longestCircle << endl;
    int currIndex = firstIndex;
    while (currIndex == firstIndex || (currIndex < n && heights[currIndex] == heights[currIndex - 1])) {
        cout << heights[currIndex] << " ";
        currIndex++;
    }
    stack<int> lastOnes;
    while (currIndex <= lastIndex) {
        lastOnes.push(heights[currIndex]);
        currIndex++;
        while(currIndex < lastIndex && heights[currIndex] == heights[currIndex-1]) {
            cout << heights[currIndex] << " ";
            currIndex++;
        }
    }
    while(!lastOnes.empty()) {
        cout << lastOnes.top() << " ";
        lastOnes.pop();
    }
    cout << endl;
    return 0;
}
