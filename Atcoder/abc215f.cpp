#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<int, int> points[n];
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    sort(points, points + n);
    int low = 0;
    int high = 1000000000;
    int maxDistance = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int left = 0;
        int right = 1;
        int minY = points[0].second;
        int maxY = points[0].second;
        bool distanceFound = false;
        while (right < n) {
            while(points[left + 1].first <= points[right].first - mid) {
                left++;
                minY = min(minY, points[left].second);
                maxY = max(maxY, points[left].second);
            }
            if(points[left].first <= points[right].first - mid 
            && (minY <= points[right].second - mid || 
                maxY >= points[right].second + mid)) {
                distanceFound = true;
                maxDistance = mid;
                break;
            }
            right++;
        }
        if (distanceFound) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << maxDistance << endl;
    return 0;
}