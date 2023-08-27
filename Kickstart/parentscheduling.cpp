#include <iostream>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
int main() {
  int t, n, s, e;
  cin >> t;
  for(int c = 1; c <= t; c++) {
    cin >> n;
    ppi schedule[n];
    for(int i = 0; i < n; i++) {
      cin >> s >> e;
      schedule[i] = ppi(pii(s, e), i);
    }
    sort(schedule, schedule + n);
    string answer = "";
    char assign[n];
    int cFree = 0;
    int jFree = 0;
    for(int i = 0; i < n; i++) {
      if(cFree > schedule[i].first.first && jFree > schedule[i].first.first) {
        answer = "IMPOSSIBLE";
        break;
      }
      if(cFree <= schedule[i].first.first) {
        assign[schedule[i].second] = 'C';
        cFree = schedule[i].first.second;
      } else {
        assign[schedule[i].second] = 'J';
        jFree = schedule[i].first.second;
      }
    }
    if(answer != "IMPOSSIBLE") {
      for(int i = 0; i < n; i++) {
        answer += assign[i];
      }
    }
    cout << "Case #" << c << ": " << answer << endl;
  }
  return 0;
}
