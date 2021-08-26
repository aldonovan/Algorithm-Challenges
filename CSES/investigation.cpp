#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<pair<int, int>> graph[100000];
vector<pair<int, int>> inEdges[100000];
pair<int, int> minMaxEdges[100000];
ll distances[100000];
int numPaths[100000];
int n;

//We could also have just tracked min edges and max edges during Dijkstra as well
void dijkstra(int addToEdge) {
    numPaths[0] = 1;
    distances[0] = 0;
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0LL, 0});
    for(int i = 1; i < n; i++) {
        distances[i] = LLONG_MAX;
        numPaths[i] = 0;
    }
    while(!pq.empty()) {
        ll distance; int node;
        tie(distance, node) = pq.top();
        pq.pop();
        if(distances[node] != distance) continue;
        for(pair<int, int> edge: graph[node]) {
            int edgeLength = edge.second + addToEdge;
            if(distance + edgeLength == distances[edge.first]) {
                numPaths[edge.first] = (numPaths[edge.first] + numPaths[node]) % 1000000007;
            } else if(distance + edgeLength < distances[edge.first]) {
                distances[edge.first] = distance + edgeLength;
                pq.push({distance + edgeLength, edge.first});
                numPaths[edge.first] = numPaths[node];
            }
        }
    }
}

pair<int, int> dfs(ll minPrice, int curr) {
    if(curr == 0) return {0, 0};
    if(minMaxEdges[curr] != make_pair(-1, -1)) return minMaxEdges[curr];
    pair<int, int> minMaxDistances(INT_MAX, -1);
    for(pair<int, int> edge: inEdges[curr]) {
        ll newDistance = minPrice - edge.second;
        if(newDistance == distances[edge.first]) {
            pair<int, int> neighborDistances = dfs(newDistance, edge.first);
            minMaxDistances.first = min(neighborDistances.first + 1, minMaxDistances.first);
            minMaxDistances.second = max(neighborDistances.second + 1, minMaxDistances.second);
        }
    }
    minMaxEdges[curr] = minMaxDistances;
    return minMaxDistances;
}

int main() {
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2, price;
        cin >> v1 >> v2 >> price;
        graph[v1-1].push_back(make_pair(v2-1, price));
        inEdges[v2-1].push_back(make_pair(v1-1, price));
    }
    dijkstra(0);
    ll minPrice = distances[n - 1];
    int numMinPriceRoutes = numPaths[n-1];

    for(int i = 0; i < n; i++) minMaxEdges[i] = make_pair(-1, -1);
    pair<int, int> minMaxNumEdges = dfs(minPrice, n - 1);

    cout << minPrice << " " << numMinPriceRoutes << " " << minMaxNumEdges.first << " " << minMaxNumEdges.second << endl;
    return 0;
}
