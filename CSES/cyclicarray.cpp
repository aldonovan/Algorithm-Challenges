#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long k;
    cin >> n >> k;
    int last[n];
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    long long currSum = numbers[0];
    int firstIndex = 0;
    int lastIndex = 1;
    while (firstIndex < n) {
        currSum += numbers[lastIndex % n];
        while ((lastIndex == firstIndex + n || currSum > k) && firstIndex < n) {
            last[firstIndex] = lastIndex % n;
            currSum -= numbers[firstIndex];
            firstIndex++;
        }
        lastIndex++;
    }
    int index = 0;
    for (int i = 1; i <= n; i++) {
        index = last[index];
    }
    int numSubarrays = 0;
    int distance = 0;
    while (distance < n) {
        distance += last[index] - index;
        if (last[index] <= index) {
            distance += n;
        }
        index = last[index];
        numSubarrays++;
    }
    cout << numSubarrays << endl;
    return 0;
}
