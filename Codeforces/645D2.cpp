//Robot Rapping Results Report: Just topological sort
#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> battles[m];
  vector<int> adj[n+1];
  vector<int> inDegree(n + 1, 0);
  for(int i = 0; i < m; i++) {
    int robot1, robot2;
    cin >> robot1 >> robot2;
    pair<int, int> battle(robot1, robot2);
    adj[robot2].push_back(robot1);
    inDegree[robot1]++;
    battles[i] = battle;
  }
  queue<int> robots;
  for(int i = 1; i < n + 1; i++) {
    if(inDegree[i] == 0) robots.push(i);
  }
  int visitedRobots = 0;
  vector<int> topSort;
  while(!robots.empty()) {
    if(robots.size() > 1) {
      cout << -1 << endl;
      return 0;
    }
    int nextRobot = robots.front();
    robots.pop();
    topSort.push_back(nextRobot);
    visitedRobots++;
    for(int i = 0; i < adj[nextRobot].size(); i++) {
      int neighbor = adj[nextRobot][i];
      inDegree[neighbor]--;
      if(inDegree[neighbor] == 0) {
        robots.push(neighbor);
      }
    }
  }
  if(visitedRobots != n) {
    cout << -1 << endl;
    return 0;
  }
  set<pair<int, int> > topEdges;
  for(int i = 1; i < topSort.size(); i++) {
    pair<int, int> edge(topSort[i], topSort[i-1]);
    topEdges.insert(edge);
  }
  int battleNumber = 0;
  while(topEdges.size() > 0) {
    pair<int, int> currBattle = battles[battleNumber];
    if(topEdges.find(currBattle) != topEdges.end()) {
      topEdges.erase(currBattle);
    }
    battleNumber++;
  }
  cout << battleNumber << endl;
  return 0;
}
