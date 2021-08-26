#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;
int main() {
    int n, k;
    ifstream fin("snakes.in");
    ofstream fout("snakes.out");
    fin >> n >> k;
    int snakes[n];
    int wasted[n][k+1];
    int sum = 0;
    int maxSnake = -1;
    for(int i = 0; i < n; i++) {
        fin >> snakes[i];
        sum += snakes[i];
        maxSnake = max(maxSnake, snakes[i]);
        wasted[i][0] = (maxSnake*(i+1)) - sum;
    }
    for(int numChanges = 1; numChanges <= k; numChanges++) {
        for(int index = 1; index < n; index++) {
            int smallestCost = INT_MAX;
            int greatestSnake = -1;
            int sum = 0;
            for(int previous = index; previous >= numChanges; previous--) {
                greatestSnake = max(greatestSnake, snakes[previous]);
                sum += snakes[previous];
                smallestCost = min(smallestCost, greatestSnake*(index - previous + 1) - sum + wasted[previous-1][numChanges - 1]);
            }
            wasted[index][numChanges] = smallestCost;
        }
    }
    fout << wasted[n-1][k] << endl;
    return 0;
}