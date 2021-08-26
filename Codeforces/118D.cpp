#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  /*Count number of ways to line up n1 footmen and n2 horsemen
  so that there is never more than k1 footmen in a row or
  more than k2 horsemen in a row
  */
  //Thought: Recursion based on first person?
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  //Answer = dp[n1][n2][k1][k2][0] + dp[n1][n2][k1][k2][1]
  //dp[n1][n2][k1][k2][0] = sum of dp[n1-x][n2][k1][k2][1] for x = 1 to k1
  //dp[n1][n2][k1][k2][1] = sum of dp[n1][n2-x][k1][k2][0] for x = 1 to k2
  //dp[1][0][0] = 1
  //dp[1][0][1] = 0
  //dp[0][1][0] = 0
  //dp[0][1][1] = 1
  //dp[1][1][0] = dp[0][1][1] = 1
  //dp[1][1][1] = dp[1][0][0] = 1
  //dp[3][1][0] = dp[2][1][1] + dp[1][1][1] + dp[0][1][1]

  long long footmen[n1+1][n2+1];
  long long horsemen[n1+1][n2+1];
  footmen[1][0] = 1;
  footmen[0][1] = 0;
  footmen[1][1] = 1;
  footmen[0][0] = 1;
  horsemen[1][0] = 0;
  horsemen[0][1] = 1;
  horsemen[1][1] = 1;
  horsemen[0][0] = 1;

  for(int nc2 = 0; nc2 <= n2; nc2++) {
    for(int nc1 = 2; nc1 <= n1; nc1++) {
      int lower1 = max(0, nc1 - k1);
      int lower2 = max(0, nc1 - k2);
      footmen[nc1][nc2] = 0;
      horsemen[nc1][nc2] = 0;
      for(int i = lower1; i < nc1; i++) {
        footmen[nc1][nc2] += horsemen[i][nc2];
      }
      cout << "First: " << nc1 << " Second: " << nc2 << " " << footmen[nc1][nc2] << endl;
      for(int i = lower2; i < nc2; i++) {
        horsemen[nc1][nc2] += footmen[nc1][i];
      }
      cout << "Horse First: "<< nc1 << " Second: " << nc2 << " " << horsemen[nc1][nc2] << endl;
    }
  }
  cout << footmen[n1][n2] + horsemen[n1][n2] << endl;
  return 0;
}
