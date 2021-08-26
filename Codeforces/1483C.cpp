#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    int heights[n];
    int beauties[n];
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> beauties[i];
    }
    vector<long long> maxBeauty(n, INT_MIN);
    vector<int> lastLess(n, -1);
    stack<long long> inc;
    stack<long long> sub;
    //Not convinced this works with stacks, although segment trees work for sure
    long long largestBeautySoFar = 0;
    for(int i = 0; i < n; i++) {
        long long maxBeauties = (i == 0) ? 0 : maxBeauty[i-1];
        while(!inc.empty() && heights[inc.top()] >= heights[i]) {
            inc.pop();
            maxBeauties = max(maxBeauties, sub.top());
            sub.pop();
        }
        if(!inc.empty()) {
            lastLess[i] = inc.top();
            maxBeauties = max(maxBeauties, sub.top());
        } else {
            maxBeauties = largestBeautySoFar;
        }
        
        long long currMaxBeauty = maxBeauties + beauties[i];
        if(lastLess[i] != -1) {
            currMaxBeauty = max(currMaxBeauty, maxBeauty[lastLess[i]]);
        }
        maxBeauties = max(maxBeauties, currMaxBeauty);
        largestBeautySoFar = max(largestBeautySoFar, maxBeauties);
        if(!inc.empty()) {
            sub.pop();
            sub.push(maxBeauties);
        }
        inc.push(i);
        sub.push(currMaxBeauty);
        maxBeauty[i] = currMaxBeauty;
    }
    cout << maxBeauty[n - 1] << endl;
    return 0;
}
