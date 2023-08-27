#include <iostream>
#include <vector>
using namespace std;

int threeWays(int n, char grid[50][50], vector<int> gridRowMaxBales, vector<int> gridColMaxBales) {
    if (grid[0][0] == 'H') return 0;
    int answer = 0;
    for (int col = 1; col < n - 1; col++) {
        if (grid[0][col] == 'H') {
            break;
        }
        for (int row = 1; row < n - 1; row++) {
            if (grid[row][col] == 'H') {
                break;
            }
            if (gridRowMaxBales[row] < col && gridColMaxBales[n - 1] < row) {
                answer++;
            }
        }
    }
    return answer;
}

int twoWays(int n, char grid[50][50], vector<int> gridRowMaxBales, vector<int> gridColMaxBales) {
    if (grid[0][0] == 'H') return 0;
    int answer = 0;

    for (int col = 1; col < n - 1; col++) {
        if (grid[0][col] == 'H') {
            break;
        }
        if (gridColMaxBales[col] == -1 && gridRowMaxBales[n-1] < col) {
            answer++;
        }
    }
    return answer;
}

int oneWays(int n, char grid[50][50]) {
    int firstRowBales = 0;
    int lastColBales = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 'H') {
                if (row == 0) firstRowBales++;
                if (col == n - 1) lastColBales++;
            }
        }
    }
    if (firstRowBales == 0 && lastColBales == 0) {
        return 1;
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n, k;
        cin >> n >> k;
        char grid[50][50];
        char transposeGrid[50][50];
        vector<int> gridRowMaxBales(n, -1);
        vector<int> gridColMaxBales(n, -1);
        vector<int> transposeGridRowMaxBales(n, -1);
        vector<int> transposeGridColMaxBales(n, -1);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                cin >> grid[row][col];
                if (grid[row][col] == 'H') {
                    gridRowMaxBales[row] = col;
                    gridColMaxBales[col] = row;
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                transposeGrid[row][col] = grid[col][row];
                if (transposeGrid[row][col] == 'H') {
                    transposeGridRowMaxBales[row] = col;
                    transposeGridColMaxBales[col] = row;
                }
            }
        }

        int answer = 0;
        if (k >= 1) {
            answer += oneWays(n, grid) + oneWays(n, transposeGrid);
        }
        if (k >= 2) {
            answer += twoWays(n, grid, gridRowMaxBales, gridColMaxBales) + twoWays(n, transposeGrid, transposeGridRowMaxBales, transposeGridColMaxBales);
        }
        if (k >= 3) {
            answer += threeWays(n, grid, gridRowMaxBales, gridColMaxBales) + threeWays(n, transposeGrid, transposeGridRowMaxBales, transposeGridColMaxBales);
        }
        cout << answer << endl;
    }
    return 0;
}
