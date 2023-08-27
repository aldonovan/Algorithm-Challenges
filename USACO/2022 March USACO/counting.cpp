#include <iostream>
#include <climits>
using namespace std;
int main() {
    int n;
    cin >> n;
    pair<char, int> observations[n];
    for (int i = 0; i < n; i++) {
        char type;
        int value;
        cin >> type >> value;
        observations[i] = {type, value};
    }
    // Just simple O(n^2) solution -- there are faster ways as well
    int minimumWrong = INT_MAX;
    for (int i = 0; i < n; i++) {
        int currValue = observations[i].second;
        int currWrong = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                continue;
            }
            if ((observations[j].first == 'L' && observations[j].second < currValue) || 
                (observations[j].first == 'G' && observations[j].second > currValue)) {
                    currWrong++;
            }
        }
        minimumWrong = min(minimumWrong, currWrong);
    }
    cout << minimumWrong << endl;
    return 0; 
}
