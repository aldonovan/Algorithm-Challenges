#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  for(int s = 1; s <= t; s++) {
    cin >> n;
    int numbers[n][n];
    int trace = 0;
    int rowRepeats = 0;
    int columnRepeats = 0;
    for(int i = 0; i < n; i++) {
      bool repeats = false;
      unordered_set<int> values;
      for(int j= 0; j < n; j++) {
        cin >> numbers[i][j];
        if(values.find(numbers[i][j]) != values.end()) repeats = true;
        values.insert(numbers[i][j]);
      }
      if(repeats) rowRepeats++;
    }
    for(int i = 0; i < n; i++) {
      trace += numbers[i][i];
    }
    for(int i = 0; i < n; i++) {
      bool repeats = false;
      unordered_set<int> values;
      for(int j = 0; j < n; j++) {
        if(values.find(numbers[j][i]) != values.end()) repeats = true;
        values.insert(numbers[j][i]);
      }
      if(repeats) columnRepeats++;
    }
    cout << "Case #" << s << ": " << trace << " " << rowRepeats << " " << columnRepeats << endl;
  }
  return 0;
}
