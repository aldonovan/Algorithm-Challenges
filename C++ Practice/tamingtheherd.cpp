#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int counter[n];
    for(int i = 0; i < n; i++) {
        cin >> counter[i];
    }
    int incorrectEntries[n+1][n+1];
    for(int breakouts = 1; breakouts <= n; breakouts++) {
        for(int startIndex = n - breakouts; startIndex >= 0; startIndex--) {
            int minIncorrect = INT_MAX;
            int currIncorrect = 0;
            int numIncorrect = 0;
            for(int i = startIndex; i < n - breakouts + 1; i++) {
                if(counter[i] != i - startIndex) numIncorrect++;
                currIncorrect = numIncorrect;
                if(breakouts > 1) {
                    currIncorrect += incorrectEntries[i+1][breakouts-1];
                }
                minIncorrect = min(minIncorrect, currIncorrect);
            }
            incorrectEntries[startIndex][breakouts] = minIncorrect;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << incorrectEntries[0][i] << endl;
    }
    return 0;
}