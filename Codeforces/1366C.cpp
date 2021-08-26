#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m, num;
        cin >> n >> m;
        unordered_map<int, pair<int, int> > distanceCount;
        int farthestDistance = (n+m-2)/2;
        for(int dist = 0; dist <= farthestDistance; dist++) {
            distanceCount[dist] = make_pair(0, 0);
        }
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> num;
                int distance = min(j+k, n+m-2-j-k);
                if(num == 0) {
                     distanceCount[distance].first++;
                }
                distanceCount[distance].second++;
            }
        }
        int numChanges = 0;
        for(int dist = 0; dist <= farthestDistance; dist++) {
            if(dist != farthestDistance || (n+m) % 2 != 0) {
                numChanges += min(distanceCount[dist].first, distanceCount[dist].second - distanceCount[dist].first);
            }
        }
        cout << numChanges << endl;
    }
    return 0;
}