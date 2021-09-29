#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    pair<long long, long long> friends[n];
    for (int i = 0; i < n; i++) {
        long long m, s;
        cin >> m >> s;
        friends[i] = make_pair(m, s);
    }
    sort(friends, friends + n);
    long long maximumMoney = 0;
    long long currMoney = 0;
    int leftIndex = 0;
    for (int rightIndex = 0; rightIndex < n; rightIndex++) {
        currMoney += friends[rightIndex].second;
        while (friends[leftIndex].first <= friends[rightIndex].first - d) {
            currMoney -= friends[leftIndex].second;
            leftIndex++;
        }
        maximumMoney = max(maximumMoney, currMoney);
    }
    cout << maximumMoney << endl;
    return 0;
}
