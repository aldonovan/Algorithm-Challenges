#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> dish1, vector<int> dish2) {
    return dish1[1] < dish2[1];
}

int main() {
    // Subproblem - Solve for specific sum a_i + b_i - m_i
    // Then the final a_i amount is in the interval [max(0, a_i - m_i), a_i - max(0, m_i - b_i)]
    // Then we are choosing the minimum number of arrows to hit every interval
    int t, n, a, b, m, sum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        int a[n];
        int b[n];
        int m[n];
        unordered_map<int, vector<vector<int> > > sumToDishes;
        for (int j = 0; j < n; j++) {
            cin >> a[j] >> b[j] >> m[j];
            sum = a[j] + b[j] - m[j];
            // Need to store [a, b, id]
            if (sumToDishes.find(sum) != sumToDishes.end()) {
                sumToDishes[sum].push_back({max(0, a[j] - m[j]), a[j] - max(0, m[j] - b[j]), j});
            } else {
                sumToDishes[sum] = {{max(0, a[j] - m[j]), a[j] - max(0, m[j] - b[j]), j}};
            }
        }
        int variety = 0;
        int x[n];
        int y[n];
        for (auto it = sumToDishes.begin(); it != sumToDishes.end(); it++) {
            vector<vector<int> > dishes = it->second;
            sort(dishes.begin(), dishes.end(), cmp);
            int numDistinct = 1;
            int endPoint = dishes[0][1];
            int firstIndex = dishes[0][2];
            x[firstIndex] = a[firstIndex] - endPoint;
            y[firstIndex] = m[firstIndex] - x[firstIndex];
            for (int j = 1; j < dishes.size(); j++) {
                if (dishes[j][0] > endPoint) {
                    numDistinct++;
                    endPoint = dishes[j][1];
                }
                int index = dishes[j][2];
                x[index] = a[index] - endPoint;
                y[index] = m[index] - x[index];
            }
            variety += numDistinct;
        }
        cout << variety << endl;
        for (int j = 0; j < n; j++) {
            cout << x[j] << " " << y[j] << endl;
        }
    }
    return 0;
}
