#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (nums.size() == 0 || num != nums[nums.size() - 1]) {
            nums.push_back(num);
        }
    }
    int m = nums.size();
    int dp[m][m];
    for (int i = 0; i < m; i++) {
        dp[i][i] = 1;
    }
    for (int size = 2; size <= m; size++) {
        for (int start = 0; start + size - 1 < m; start++) {
            int end = start + size - 1;
            dp[start][end] = 1 + dp[start][end - 1];
            for (int prev = end - 2; prev >= start; prev--) {
                if (nums[prev] == nums[end]) {
                    dp[start][end] = min(dp[start][end], dp[prev+1][end-1] + dp[start][prev]);
                }
            }
        }
    }
    cout << dp[0][m-1] << endl;
    return 0;
}
