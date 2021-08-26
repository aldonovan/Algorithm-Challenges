#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> edges[200000];

pair<int, int> dfs(int root, int parent) {
    pair<int, int> maxEdges(0, 0);
    int largestAdded = 0;
    for(int neighbor: edges[root]) {
        if(neighbor != parent) {
            pair<int, int> neighborEdges = dfs(neighbor, root);
            maxEdges.first += neighborEdges.second;
            largestAdded = max(largestAdded, 1 + neighborEdges.first - neighborEdges.second);
        }
    }
    maxEdges.second = maxEdges.first + largestAdded;
    return maxEdges;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1-1].push_back(v2-1);
        edges[v2-1].push_back(v1-1);
    }
    pair<int, int> matchingEdges = dfs(0, -1);
    cout << matchingEdges.second << endl;
    return 0;
}
