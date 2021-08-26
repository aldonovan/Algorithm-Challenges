#include <bits/stdc++.h>
using namespace std;
int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int n, k, temperature;
        cin >> n >> k;
        int conditionerPositions[k];
        int conditioners[n];
        for(int j = 0; j < n; j++) conditioners[j] = -1;
        for(int j = 0; j < k; j++) {
            cin >> conditionerPositions[j];
        }
        for(int j = 0; j < k; j++) {
            cin >> conditioners[conditionerPositions[j] - 1];
        }
        int temperatures[n];
        int minTemp = INT_MAX;
        for(int j = 0; j < n; j++) {
            if(conditioners[j] != -1) {
                minTemp = min(minTemp, conditioners[j]);
            }
            temperatures[j] = minTemp;
            if(minTemp < INT_MAX) {
                minTemp++;
            }
        }
        minTemp = INT_MAX;
        for(int j = n - 1; j >= 0; j--) {
            if(conditioners[j] != -1) {
                minTemp = min(minTemp, conditioners[j]);
            }
            temperatures[j] = min(temperatures[j], minTemp);
            if(minTemp < INT_MAX) {
                minTemp++;
            }
        }
        for(int j = 0; j < n; j++) {
            cout << temperatures[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
