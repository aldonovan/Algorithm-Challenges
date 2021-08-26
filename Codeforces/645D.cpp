//Robot Rapping Results Report: Combines binary search with topological sort
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

bool canDetermineOrder(int numBattles, int numRobots, pair<int, int> battles[]) {
  vector<int> adj[numRobots+1];
  vector<int> inDegree(numRobots + 1, 0);
  for(int i = 0; i < numBattles; i++) {
    int robot1 = battles[i].first;
    int robot2 = battles[i].second;
    adj[robot2].push_back(robot1);
    inDegree[robot1]++;
  }
  queue<int> robots;
  for(int i = 1; i < numRobots + 1; i++) {
    if(inDegree[i] == 0) robots.push(i);
  }
  int visitedRobots = 0;
  while(!robots.empty()) {
    if(robots.size() > 1) return false;
    int nextRobot = robots.front();
    robots.pop();
    visitedRobots++;
    for(int i = 0; i < adj[nextRobot].size(); i++) {
      int neighbor = adj[nextRobot][i];
      inDegree[neighbor]--;
      if(inDegree[neighbor] == 0) {
        robots.push(neighbor);
      }
    }
  }
  return visitedRobots == numRobots;
}

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> battles[m];
  for(int i = 0; i < m; i++) {
    int robot1, robot2;
    cin >> robot1 >> robot2;
    pair<int, int> battle(robot1, robot2);
    battles[i] = battle;
  }
  int low = 1;
  int high = m;
  int minRapBattles = -1;
  while(low <= high) {
    int mid = low + (high - low)/2;
    if(canDetermineOrder(mid, n, battles)) {
      minRapBattles = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << minRapBattles << endl;
  return 0;
}
