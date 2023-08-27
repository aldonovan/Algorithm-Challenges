#include <iostream>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    int runningH = 0;
    int runningG = 0;
    int prevRunningH = 0;
    int prevRunningG = 0;
    int prevH[n];
    int prevG[n];
    for (int i = 0; i < n; i++) {
        prevH[i] = 0;
        prevG[i] = 0;
    }
    prevH[0] = 1;
    prevG[0] = 1;
    long long totalLonelyPhotos = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') {
            runningH++;
        } else {
            runningG++;
        }
        if (i >= 3) {
            if (s[i-3] == 'H') {
                prevRunningH++;
            } else {
                prevRunningG++;
            }
            prevH[prevRunningH]++;
            prevG[prevRunningG]++;
        }
        if (i >= 2) {
            if (runningH > 0) {
                totalLonelyPhotos += prevH[runningH - 1];
            }
            if (runningG > 0) {
                totalLonelyPhotos += prevG[runningG - 1];
            }
        }
    }
    cout << totalLonelyPhotos << endl;
    return 0;
}
