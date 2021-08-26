#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    queue<pair<int, int> > monsters;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    queue<pair<int, int> > start;
    vector<vector<bool> > startVisited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j = 0; j < m; j++) {
            grid[i][j] = 1;
            if(row[j] == '#') {
                grid[i][j] = 0;
            } else if(row[j] == 'A') {
                pair<int, int> startingPoint = make_pair(i, j);
                start.push(startingPoint);
                startVisited[i][j] = true;
            } else if(row[j] == 'M') {
                pair<int, int> monster = make_pair(i, j);
                monsters.push(monster);
                visited[i][j] = true;
            }
        }
    }
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int> > monsterDistances(n, vector<int>(m, INT_MAX));
    int distance = 0;
    while(!monsters.empty()) {
        int num = monsters.size();
        for(int k = 0; k < num; k++) {
            pair<int, int> monster = monsters.front();
            monsters.pop();
            monsterDistances[monster.first][monster.second] = distance;
            for(int i = 0; i < 4; i++) {
                pair<int, int> newLocation = make_pair(monster.first + directions[i][0], 
                    monster.second + directions[i][1]);
                if(newLocation.first >= 0 && newLocation.first < n && newLocation.second >= 0
                    && newLocation.second < m && grid[newLocation.first][newLocation.second] != 0
                        && !visited[newLocation.first][newLocation.second]) {
                        monsters.push(newLocation);
                        visited[newLocation.first][newLocation.second] = true;
                    } 
            }
        }
        distance++;
    }

    distance = 0;
    bool reachEdge = false;
    pair<int, int> endLocation;
    map<pair<int, int>, int> backDirections;
    while(!start.empty()) {
        if(reachEdge) break;
        int num = start.size();
        for(int k = 0; k < num; k++) {
            pair<int, int> curr = start.front();
            start.pop();
            if(curr.first == 0 || curr.first == (n - 1) || curr.second == 0 || 
                curr.second == (m - 1)) {
                    reachEdge = true;
                    endLocation = curr;
                    break;
            }
            for(int i = 0; i < 4; i++) {
                pair<int, int> newLocation = make_pair(curr.first + directions[i][0], 
                    curr.second + directions[i][1]);
                if(newLocation.first >= 0 && newLocation.first < n && newLocation.second >= 0
                    && newLocation.second < m && grid[newLocation.first][newLocation.second] != 0
                        && !startVisited[newLocation.first][newLocation.second] && 
                        distance + 1 < monsterDistances[newLocation.first][newLocation.second]) {
                        start.push(newLocation);
                        startVisited[newLocation.first][newLocation.second] = true;
                        backDirections[newLocation] = i;
                } 
            }
        }
        distance++;
    }

    if(!reachEdge) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int numSteps = 0;
        char charDirections[4] = {'U', 'D', 'R', 'L'};
        string path = "";
        while(backDirections.find(endLocation) != backDirections.end()) {
            int move = backDirections[endLocation];
            path += charDirections[move];
            endLocation.first -= directions[move][0];
            endLocation.second -= directions[move][1];
            numSteps++;
        }
        reverse(path.begin(), path.end());
        cout << numSteps << endl;
        cout << path << endl;
    }
    return 0;
}
