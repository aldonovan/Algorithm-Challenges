#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int stones[n];
    int distances[n];
    cin >> stones[0];
    distances[0] = 0;
    for(int i = 1; i < n; i++) {
        cin >> stones[i];
        int smallestDistance = INT_MAX;
        for(int j = i - 1; j >= i - k && j >= 0; j--) {
            smallestDistance = min(smallestDistance, distances[j] + abs(stones[i] - stones[j]));
        }
        distances[i] = smallestDistance;
    }
    cout << distances[n-1] << endl;
    return 0;
}