#include <iostream>
using namespace std;
int main() {
  int t, n, p;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cin >> n >> p;
    int widths[n];
    int heights[n];
    int sumPerimeters = 0;
    for(int j = 0; j < n; j++) {
      cin >> widths[j];
      cin >> heights[j];
      sumPerimeters += 2*widths[j] + 2*heights[j];
    }
    int remainingAreas = p - sumPerimeters;
    //Can increase by any value between 2*min(w, h) and 2*sqrt(w^2 + h^2)
    cout << "Case #" << i << ": " << answer << endl;
  }
  return 0;
}
