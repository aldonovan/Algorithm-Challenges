#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int twoBeforeCost = 0, twoBefore, oneBeforeCost, oneBefore;
    cin >> twoBefore >> oneBefore;
    oneBeforeCost = abs(oneBefore - twoBefore);
    for(int i = 0; i < n - 2; i++) {
        int currNumber, currCost;
        cin >> currNumber;
        currCost = min(abs(currNumber - twoBefore) + twoBeforeCost, abs(currNumber - oneBefore) + oneBeforeCost);
        twoBeforeCost = oneBeforeCost;
        twoBefore = oneBefore;
        oneBeforeCost = currCost;
        oneBefore = currNumber;
    }
    cout << oneBeforeCost << endl;
    return 0;
}