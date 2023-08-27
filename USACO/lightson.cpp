#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
int main() {
  ifstream fin("lightson.in");
  ofstream fout("lightson.out");
  int N, M;
  fin >> N >> M;
  vector<pii> lightUp[N+1][N+1];
  int x, y, a, b;
  while(M--) {
    fin >> x >> y >> a >> b;
    lightUp[x][y].push_back(pii(a, b));
  }
  queue<pii> rooms;
  rooms.push(pii(1, 1));
  bool reached[N+1][N+1];
  bool lit[N+1][N+1];
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      reached[i][j] = false;
      lit[i][j] = false;
    }
  }
  reached[1][1] = true;
  lit[1][1] = true;
  int neighbors[5][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {0, 0}};
  while(!rooms.empty()) {
    pii room = rooms.front();
    rooms.pop();
    for(auto& dir : neighbors) {
      int x = room.first + dir[0];
      int y = room.second + dir[1];
      if(1 <= x && x <= N && 1 <= y && y <= N && reached[x][y]) {
        reached[room.first][room.second] = true;
        vector<pii> newLit = lightUp[room.first][room.second];
        for(int i = 0; i < newLit.size(); i++) {
          pii newRoom = newLit[i];
          if(!lit[newRoom.first][newRoom.second]) {
            rooms.push(newRoom);
            lit[newRoom.first][newRoom.second] = true;
          }
        }
        for(auto& adj: neighbors) {
          int f = room.first + adj[0];
          int s = room.second + adj[1];
          if(1 <= f && f <= N && 1 <= s && s <= N && lit[f][s] && !reached[f][s]) {
            rooms.push(pii(f, s));
          }
        }
        break;
      }
    }
  }
  int totalLit = 0;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(lit[i][j]) totalLit++;
    }
  }
  fout << totalLit << endl;
  return 0;
}
