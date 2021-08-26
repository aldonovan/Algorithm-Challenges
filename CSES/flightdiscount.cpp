#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll distFromStart[100001];
ll distFromEnd[100001];
vector<pair<int, int>> graph[100001];
vector<pair<int, int>> flippedGraph[100001];
int n, m;

void dijkstra(int src, bool start) {
    if(start) {
        for(int i = 1; i <= n; i++) distFromStart[i] = LLONG_MAX;
    } else {
        for(int i = 1; i <= n; i++) distFromEnd[i] = LLONG_MAX;
    }
    using T = pair<ll, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, src});
    if(start) distFromStart[src] = 0;
    if(!start) distFromEnd[src] = 0;
    while(!pq.empty()) {
        ll distance; int node;
        tie(distance, node) = pq.top();
        pq.pop();
        ll trueDistance = (start) ? distFromStart[node] : distFromEnd[node];
        if(trueDistance != distance) continue;
        vector<pair<int, int>> edges = (start) ? graph[node] : flippedGraph[node];
        for(pair<int, int> edge: edges) {
            ll nextDistance = (start) ? distFromStart[edge.first] : distFromEnd[edge.first];
            if(distance + edge.second < nextDistance) {
                pq.push({distance + edge.second, edge.first});
                if(start) {
                    distFromStart[edge.first] = distance + edge.second;
                } else {
                    distFromEnd[edge.first] = distance + edge.second;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2, price;
        cin >> v1 >> v2 >> price;
        graph[v1].push_back({v2, price});
        flippedGraph[v2].push_back({v1, price});
    }
    dijkstra(1, true);
    dijkstra(n, false);
    ll cheapestRoute = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        for(pair<int, int> edge: graph[i]) {
            cheapestRoute = min(cheapestRoute, edge.second / 2 + distFromStart[i] + distFromEnd[edge.first]);
        }
    }
    cout << cheapestRoute << endl;
    return 0;
}
