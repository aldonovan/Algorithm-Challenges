#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool visited[600001];
// First find the connected components
void findComponent(long long currValue, vector<vector<long long>> &adj, vector<long long> &component) {
    if(visited[currValue]) return;
    visited[currValue] = true;
    component.push_back(currValue);
    for (long long neighbor : adj[currValue]) {
        findComponent(neighbor, adj, component);
    }
}

int main() {
    long long t;
    cin >> t;
    for (long long testCase = 0; testCase < t; testCase++) {
        long long n, m;
        cin >> n >> m;
        vector<vector<long long>> adj(n + 1, vector<long long>(0));
        for (long long i = 0; i < m; i++) {
            long long field1, field2;
            cin >> field1 >> field2;
            adj[field1].push_back(field2);
            adj[field2].push_back(field1);
        }
        for (long long i = 1; i <= n; i++) {
            visited[i] = false;
        }
        vector<vector<long long>> connectedComponents;
        for (long long i = 1; i <= n; i++) {
            if (!visited[i]) {
                vector<long long> newComponent;
                findComponent(i, adj, newComponent);
                sort(newComponent.begin(), newComponent.end());
                connectedComponents.push_back(newComponent);
            }
        }
        long long startComponent = 0;
        long long endComponent = -1;
        for (long long i = 0; i < connectedComponents.size(); i++) {  
            for (long long value : connectedComponents[i]) {
                if (value == n) {
                    endComponent = i;
                }
            }
        }
        
        if (startComponent == endComponent) {
            cout << 0 << endl;
            continue;
        }
        
        vector<long long> distancesFromClosestInFirst(n+1, LLONG_MAX);
        vector<long long> distancesFromClosestInLast(n+1, LLONG_MAX);
        long long firstIndex = 0;
        long long lastIndex = 0;
        vector<long long> start = connectedComponents[startComponent];
        vector<long long> last = connectedComponents[endComponent];
        for (long long vertex = 1; vertex <= n; vertex++) {
            while (start[firstIndex] <= vertex && firstIndex < start.size() - 1) {
                firstIndex++;
            }
            while (last[lastIndex] <= vertex && lastIndex < last.size() - 1) {
                lastIndex++;
            }
            distancesFromClosestInFirst[vertex] = abs (start[firstIndex] - vertex);
            if (firstIndex > 0) {
                distancesFromClosestInFirst[vertex] = min (distancesFromClosestInFirst[vertex], abs(start[firstIndex-1]-vertex));
            }
            distancesFromClosestInLast[vertex] = abs (last[lastIndex] - vertex);
            if (lastIndex > 0) {
                distancesFromClosestInLast[vertex] = min(distancesFromClosestInLast[vertex], abs(last[lastIndex-1]-vertex));
            }
        }

       
        vector<long long> distancesFromFirst(connectedComponents.size(), LLONG_MAX);
        vector<long long> distancesFromLast(connectedComponents.size(), LLONG_MAX);
        for (long long componentIndex = 0; componentIndex < connectedComponents.size(); componentIndex++) {
            long long firstDifference = LLONG_MAX;
            long long secondDifference = LLONG_MAX;
            for (long long currentValue : connectedComponents[componentIndex]) {
                firstDifference = min(firstDifference, distancesFromClosestInFirst[currentValue]);
                secondDifference = min(secondDifference, distancesFromClosestInLast[currentValue]);
            }
            distancesFromFirst[componentIndex] = firstDifference*firstDifference;
            distancesFromLast[componentIndex] = secondDifference*secondDifference;
        }

        long long answer = distancesFromFirst[endComponent];
        for (long long componentIndex = 0; componentIndex < connectedComponents.size(); componentIndex++) {
            answer = min(answer, distancesFromFirst[componentIndex] + distancesFromLast[componentIndex]);
        }
        cout << answer << endl;
        
    }
    return 0;
}
