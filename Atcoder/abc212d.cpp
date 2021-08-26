#include <bits/stdc++.h>
using namespace std;
int main() {
    int q, queryType, number;
    long long runningSum = 0;
    cin >> q;
    priority_queue<long long, vector<long long>, greater<long long> > minNumbers;
    for(int i = 0; i < q; i++) {
        cin >> queryType;
        if (queryType == 3) {
            cout << minNumbers.top() + runningSum << endl;
            minNumbers.pop();
        } else { 
            cin >> number;
            if(queryType == 1) {
                minNumbers.push(number - runningSum);
            } else {
                // Query Type is 2, update running sum
                runningSum += number;
            }
        }
    }
    return 0;
}