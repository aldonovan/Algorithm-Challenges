#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> values;
    BIT(int n) {
        values.assign(n+1, 0);
    }
    int sum(int right) {
        int total = 0;
        int index = right + 1;
        while(index >= 1) {
            total += values[index];
            index -= index & (-index);
        }
        return total;
    }

    int sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

    void add(int index, int delta) {
        int currIndex = index + 1;
        while(currIndex < values.size()) {
            values[currIndex] += delta;
            currIndex += (currIndex & (-currIndex));
        }
    }
};

int main() {
    int n;
    cin >> n;
    long long totalDelegations = 0;
    BIT bit(n);
    vector<int> lastOccurrence(n, -1);
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int lastPlace = 0;
        if (lastOccurrence[num - 1] != -1) {
            lastPlace = lastOccurrence[num - 1];
            bit.add(lastPlace, -1);
        }
        lastOccurrence[num - 1] = i;
        bit.add(i, 1);
        totalDelegations += bit.sum(lastPlace, i - 1);
    }
    cout << totalDelegations << endl;
    return 0;
}