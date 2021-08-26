#include <bits/stdc++.h>
using namespace std;

int numChanges = 0;
int endIndexRows[1000][1000];
int endIndexCols[1000][1000];
int startIndexRows[1000][1000];
int startIndexCols[1000][1000];
string rows[1000];

void dfs(int row, int col) {
    char letter = rows[row][col];
    if(letter == '.' || letter == '#') {
        return;
    }
    int startIndexRow = startIndexRows[row][col];
    int endIndexRow =  endIndexRows[row][col];
    int startIndexCol = startIndexCols[row][col];
    int endIndexCol = endIndexCols[row][col];
    int rowPalindromeSpot = endIndexRow - (col - startIndexRow);
    int colPalindromeSpot = endIndexCol - (row - startIndexCol);
    if (rows[row][rowPalindromeSpot] == '.') {
        numChanges++;
        rows[row][rowPalindromeSpot] = rows[row][col];
        dfs(row, rowPalindromeSpot);
    }
    if (rows[colPalindromeSpot][col] == '.') {
        numChanges++;
        rows[colPalindromeSpot][col] = rows[row][col];
        dfs(colPalindromeSpot, col);
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n, m;
        cin >> n >> m;
        numChanges = 0;
        for(int j = 0; j < n; j++) {
            cin >> rows[j];
            int lastValidIndex = 0;
            for(int k = 0; k < m; k++) {
                if(rows[j][k] == '#') {
                    for(int index = lastValidIndex; index < k; index++) {
                        endIndexRows[j][index] = k - 1;
                        startIndexRows[j][index] = lastValidIndex;
                    }
                    lastValidIndex = k + 1;
                }
            }
            for(int index = lastValidIndex; index < m; index++) {
                endIndexRows[j][index] = m - 1;
                startIndexRows[j][index] = lastValidIndex;
            }
        }
        for(int col = 0; col < m; col++) {
            int lastValidIndex = 0;
            for(int row = 0; row < n; row++) {
                if(rows[row][col] == '#') {
                    for(int index = lastValidIndex; index < row; index++) {
                        endIndexCols[index][col] = row - 1;
                        startIndexCols[index][col] = lastValidIndex;
                    }
                    lastValidIndex = row + 1;
                }
            }
            for(int row = lastValidIndex; row < n; row++) {
                endIndexCols[row][col] = n - 1;
                startIndexCols[row][col] = lastValidIndex;
            }
        }
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                dfs(row, col);
            }
        }
        cout << "Case #" << i << ": " << numChanges << endl;
        for(int row = 0; row < n; row++) {
            cout << rows[row] << endl;
        }
    }
    return 0;
}