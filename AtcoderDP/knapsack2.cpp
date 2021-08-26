#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n, w;
    cin >> n >> w;
    long long minWeight[100001];
    minWeight[0] = 0;
    for(int weight = 1; weight <= 100000; weight++) minWeight[weight] = INT_MAX;
    for(int i = 0; i < n; i++) {
        int currWeight, currValue;
        cin >> currWeight >> currValue;
        for(int value = 100000; value >= 1; value--) {
            minWeight[value] = min(minWeight[value], minWeight[max(0, value - currValue)] + currWeight);
        }
    }
    for(int value = 1; value <= 100000; value++) {
        if(minWeight[value] > w) {
            cout << value - 1 << endl;
            return 0;
        }
    }
    cout << 100000 << endl;
    return 0;
}