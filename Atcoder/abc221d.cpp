#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<int, int> times[2*n];
    for (int i = 0; i < n; i++) {
        int start, numDays;
        cin >> start >> numDays;
        times[2*i] = make_pair(start, 1);
        times[2*i + 1] = make_pair(start + numDays, -1);
    }
    sort(times, times + 2*n);
    int daysKLoggedIn[n+1];
    for(int i = 0; i < n + 1; i++) {
        daysKLoggedIn[i] = 0;
    }
    int numLoggedIn = 0;
    int lastTime = 1;
    for (int i = 0; i < 2*n; i++) {
        if (i > 0 && times[i].first != times[i-1].first) {
            daysKLoggedIn[numLoggedIn] += times[i].first - lastTime;
        }
        numLoggedIn += times[i].second;
        lastTime = times[i].first;
    }
    for (int users = 1; users <= n; users++) {
        cout << daysKLoggedIn[users] << " ";
    }
    cout << '\n';
    return 0;
}
