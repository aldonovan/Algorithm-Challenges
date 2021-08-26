#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        int highestPossible = 0;
        int low = 1;
        int high = (x + y) / (a + b);
        int diff = b - a;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int red = mid * a;
            int blue = mid * b;
            int remainingRed = x - red;
            int overusedBlue = blue - y;
            if(red <= x && (blue <= y || ((b > a) && (remainingRed / diff) >= ceil((overusedBlue + 0.0) / diff) &&
                ceil((overusedBlue + 0.0) / diff) <= mid))) {
                highestPossible = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << highestPossible << endl;
    }
    return 0;
}
