#include <iostream>
using namespace std;
int main() {
    int n; 
    cin >> n;
    int a[n], b[n], c[n];
    int happiness[n][3];
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    for(int i = 0; i < n; i++) {
        happiness[i][0] = a[i];
        happiness[i][1] = b[i];
        happiness[i][2] = c[i]; 
        if(i > 0) {
            happiness[i][0] += max(happiness[i-1][1], happiness[i-1][2]);
            happiness[i][1] += max(happiness[i-1][0], happiness[i-1][2]);
            happiness[i][2] += max(happiness[i-1][0], happiness[i-1][1]);
        }
    }
    cout << max(max(happiness[n-1][0], happiness[n-1][1]), happiness[n-1][2]) << endl;
    return 0;
}