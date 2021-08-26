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
    freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
    int n;
    cin >> n;
    // Count pairs where firstTime[i] < firstTime[j] < secondTime[i] < secondTime[j]
    // We can sort by firstTime[i] and then use a binary indexed tree
    int numCrossings = 0;
    vector<pair<int, int> > crossingPoints(n, make_pair(-1, -1));
    for (int i = 0; i < 2*n; i++) {
        int cowNumber;
        cin >> cowNumber;
        if(crossingPoints[cowNumber - 1].first == -1) {
            crossingPoints[cowNumber - 1].first = i;
        } else {
            crossingPoints[cowNumber - 1].second = i;
        }
    }
    sort(crossingPoints.begin(), crossingPoints.end());
    BIT bit(2*n);
    for (int i = 0; i < n; i++) {
        numCrossings += bit.sum(crossingPoints[i].first + 1, crossingPoints[i].second - 1);
        bit.add(crossingPoints[i].second, 1);
    }
    cout << numCrossings << endl;
    return 0;
}
