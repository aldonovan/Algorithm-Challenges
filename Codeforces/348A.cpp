#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
  int n;
  cin >> n;
  int answer = 0;
  double sum = 0;
  for(int i = 0; i < n; i++) {
    int numGames;
    cin >> numGames;
    answer = max(answer, numGames);
    sum += numGames;
  }
  int low = ceil(sum / (n-1));
  answer = max(answer, low);
  cout << answer << endl;
  return 0;
}
