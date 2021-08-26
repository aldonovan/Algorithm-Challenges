#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int numWays[100000];
vector<int> edges[100000];
int n;
int dfs(int currNumber) {
    if(numWays[currNumber] != -1) return numWays[currNumber];
    if(currNumber == (n - 1)) return 1;
    int sum = 0;
    for(int neighbor: edges[currNumber]) {
        sum = (sum + dfs(neighbor)) % 1000000007;
    }
    numWays[currNumber] = sum;
    return sum;
}

int main() {
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) numWays[i] = -1;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1-1].push_back(v2-1);
    }    
    cout << dfs(0) << endl;
    return 0;
}