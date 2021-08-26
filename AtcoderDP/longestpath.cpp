#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    vector<int> indeg(n, 0);
    for(int i = 0; i < m; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        adj[vertex1-1].push_back(vertex2-1);
        indeg[vertex2-1]++;
    }
    vector<int> top;
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int vertex = q.front();
        top.push_back(vertex);
        q.pop();
        for(int i = 0; i < adj[vertex].size(); i++) {
            int neighbor = adj[vertex][i];
            indeg[neighbor]--;
            if(indeg[neighbor] == 0) q.push(neighbor);
        }
    }
    int longest = 1;
    int longestPaths[n];
    longestPaths[n - 1] = 0;
    for(int i = top.size() - 1; i >= 0; i--) {
        int currLongest = 0, currVertex = top[i];
        for(int i = 0; i < adj[currVertex].size(); i++) {
            int neighbor = adj[currVertex][i];
            currLongest = max(currLongest, longestPaths[neighbor] + 1);
        }
        longestPaths[currVertex] = currLongest;
        longest = max(longest, currLongest);
    }
    cout << longest << endl;
    return 0;
}
