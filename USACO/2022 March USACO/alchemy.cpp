#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int metalCounts[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> metalCounts[i];
    }
    vector<int> recipes[n + 1];
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, m;
        cin >> l >> m;
        vector<int> recipe;
        for (int j = 0; j < m; j++) {
            int recipeMetal;
            cin >> recipeMetal;
            recipe.push_back(recipeMetal);
        }
        recipes[l] = recipe;
    }
    int maxUnits = metalCounts[n];
    int low = maxUnits + 1;
    int high = 1000000;
    while (low <= high) {
        int mid = low + ((high - low)/2);
        vector<int> countsRequired(n+1, 0);
        countsRequired[n] = mid;
        bool possible = true;
        // Check if mid is possible
        for (int metal = n; metal >= 1; metal--) {
            int remaining = countsRequired[metal] - metalCounts[metal];
            if (remaining > 0) {
                if (recipes[metal].size() == 0) {
                    possible = false;
                    break;
                }
                for (int recipeMetal : recipes[metal]) {
                    countsRequired[recipeMetal] += remaining;
                }
            }
        }
        if (possible) {
            maxUnits = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << maxUnits << endl;
    return 0;
}
