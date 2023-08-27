#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int p[n];
    int differences[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        differences[i] = p[i] - temp;
    }
    long long totalChanges = abs (differences[0]);
    for (int i = 1; i < n; i++) {
        if (differences[i] < 0) {
            int last = min (differences[i-1], 0);
            totalChanges += max (last - differences[i], 0);
        } else {
            int last = max (differences[i-1], 0);
            totalChanges += max (differences[i] - last, 0);
        }
    }
    cout << totalChanges << endl;
    return 0;
}