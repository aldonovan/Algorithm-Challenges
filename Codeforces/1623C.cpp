#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int numHeaps;
        cin >> numHeaps;
        int heaps[numHeaps];
        for (int i = 0; i < numHeaps; i++) {
            cin >> heaps[i];
        }
        int low = 0;
        int high = heaps[numHeaps-1];
        int maxSmallest = heaps[numHeaps-1];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int onePrev = 0;
            int twoPrev = 0;
            bool possible = true;
            for (int index = numHeaps - 1; index >= 2; index--) {
                int currStones = heaps[index] + onePrev;
                if (currStones < mid) {
                    possible = false;
                    break;
                } else {
                    int d = min(currStones - mid, heaps[index]) / 3;
                    onePrev = twoPrev + d;
                    twoPrev = 2*d;
                }
            }
            if (heaps[1] + onePrev < mid || heaps[0] + twoPrev < mid) {
                possible = false;
            }
            if (possible) {
                maxSmallest = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << maxSmallest << endl;
    }
    return 0;
}