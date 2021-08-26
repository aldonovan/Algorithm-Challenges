#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
//Can also just do with DFS from each vertex
int main() {
    int n, m, vertex1, vertex2;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indeg(n+1, 0);
    for(int i = 0; i < m; i++) {
        cin >> vertex1 >> vertex2;
        adj[vertex2].push_back(vertex1);
        indeg[vertex1]++;
    }
    vector<int> topOrder;
    queue<int> q;
    for(int vertex = 1; vertex <= n; vertex++) {
        if(indeg[vertex] == 0) q.push(vertex);
    }
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        topOrder.push_back(vertex);
        for(int i = 0; i < adj[vertex].size(); i++) {
            int neighbor = adj[vertex][i];
            indeg[neighbor]--;
            if(indeg[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    unordered_set<int> nums[n+1];
    for(int i = 0; i < topOrder.size(); i++) {
        int vertex = topOrder[i];
        for(int i = 0; i < adj[vertex].size(); i++) {
            int neighbor = adj[vertex][i];
            for(int pre: nums[vertex]) {
                nums[neighbor].insert(pre);
            }
            nums[neighbor].insert(vertex);
        }
    }
    int result = 0;
    for(int i = 0; i < topOrder.size(); i++) {
        int vertex = topOrder[i];
        result += i - nums[vertex].size();
    }
    cout << result << endl;
    return 0;
}
