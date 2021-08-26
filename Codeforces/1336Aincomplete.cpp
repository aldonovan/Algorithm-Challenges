#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
//Tried BFS but probably better to use DFS
// sum first n - k elements (sorted order) of size of subtree - depth of node
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> adj[n+1];
    int firstCity, secondCity;
    for(int i = 0; i < n - 1; i++) {
        cin >> firstCity >> secondCity;
        adj[firstCity].push_back(secondCity);
        adj[secondCity].push_back(firstCity);
    }
    int numTourismCities = n - k;
    queue<int> cities;
    unordered_set<int> visited;
    cities.push(1);
    int maxHappiness = 0;
    int numVisitedCities = 1;
    int numSteps = 0;
    while(!cities.empty()) {
        // int levelSize = cities.size();
        // for(int i = 0; i < levelSize; i++) {
        //     int currCity = cities.front();
        //     cities.pop();
        //     visited.insert(currCity);
        //     for(int i = 0; i < adj[currCity].size(); i++) {
        //         int neighboringCity = adj[currCity][i];
        //         if(visited.find(neighboringCity) == visited.end()) {
        //             cities.push(adj[currCity][i]);
        //         }
        //     }
        // }
        // numSteps++;
    }
    cout << maxHappiness << endl;
    return 0;
}