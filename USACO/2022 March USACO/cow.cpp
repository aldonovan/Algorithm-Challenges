#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

bool comp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
    return p1.first.second < p2.first.second;
}

int main() {
    string s;
    int Q;
    cin >> s >> Q;
    int blockSize = ceil(sqrt(s.length()));
    int numBlocks = ((s.length() - 1) / blockSize) + 1;
    pair<int, int> queries[Q];
    bool results[Q];
    vector<pair<pair<int, int>, int>> blocks[numBlocks];
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = make_pair(l - 1, r - 1);
        int blockIndex = (l - 1) / blockSize;
        blocks[blockIndex].push_back(make_pair(queries[i], i));
    }
    for (int i = 0; i < numBlocks; i++) {
        // 0 - C, 1 - O, 2 - W, 3 - _
        bool possibility[s.length()][4];
        if (i < numBlocks - 1) {
            int firstIndex = (i+1)*blockSize;
            if(s[firstIndex] == 'C') {
                possibility[firstIndex][0] = true;
                possibility[firstIndex][1] = false;
                possibility[firstIndex][2] = false;
                possibility[firstIndex][3] = false;
            } else if(s[firstIndex] == 'O') {
                possibility[firstIndex][0] = false;
                possibility[firstIndex][1] = true;
                possibility[firstIndex][2] = false;
                possibility[firstIndex][3] = false;
            } else if(s[firstIndex] == 'W') {
                possibility[firstIndex][0] = false;
                possibility[firstIndex][1] = false;
                possibility[firstIndex][2] = true;
                possibility[firstIndex][3] = false;
            }

            for(int index = firstIndex + 1; index < s.length(); index++) {
                if (s[index] == 'C') {
                    possibility[index][0] = possibility[index - 1][3];
                    possibility[index][1] = possibility[index - 1][2];
                    possibility[index][2] = possibility[index - 1][1];
                    possibility[index][3] = possibility[index - 1][0];
                } else if(s[index] == 'O') {
                    possibility[index][0] = possibility[index - 1][2];
                    possibility[index][1] = possibility[index - 1][3];
                    possibility[index][2] = possibility[index - 1][0];
                    possibility[index][3] = possibility[index - 1][1];
                } else if (s[index] == 'W') {
                    possibility[index][0] = possibility[index - 1][1];
                    possibility[index][1] = possibility[index - 1][0];
                    possibility[index][2] = possibility[index - 1][3];
                    possibility[index][3] = possibility[index - 1][2];
                }
            }
        }
        for (int queryIndex = 0; queryIndex < blocks[i].size(); queryIndex++) {
                pair<pair<int, int>, int> query = blocks[i][queryIndex];
                int endIndex = query.first.second;
                int startIndex = query.first.first;
                if (endIndex < (i+1)*blockSize) {
                    bool prevPossibility[4];
                    bool newPossibility[4];
                    // Just process the full query
                    if(s[startIndex] == 'C') {
                        prevPossibility[0] = true;
                        prevPossibility[1] = false;
                        prevPossibility[2] = false;
                        prevPossibility[3] = false;
                    } else if(s[startIndex] == 'O') {
                        prevPossibility[0] = false;
                        prevPossibility[1] = true;
                        prevPossibility[2] = false;
                        prevPossibility[3] = false;
                    } else if(s[startIndex] == 'W') {
                        prevPossibility[0] = false;
                        prevPossibility[1] = false;
                        prevPossibility[2] = true;
                        prevPossibility[3] = false;
                    }
                    for (int index = startIndex + 1; index <= endIndex; index++) {
                        if (s[index] == 'C') {
                            newPossibility[0] = prevPossibility[3];
                            newPossibility[1] = prevPossibility[2];
                            newPossibility[2] = prevPossibility[1];
                            newPossibility[3] = prevPossibility[0];
                        } else if(s[index] == 'O') {
                            newPossibility[0] = prevPossibility[2];
                            newPossibility[1] = prevPossibility[3];
                            newPossibility[2] = prevPossibility[0];
                            newPossibility[3] = prevPossibility[1];
                        } else if (s[index] == 'W') {
                            newPossibility[0] = prevPossibility[1];
                            newPossibility[1] = prevPossibility[0];
                            newPossibility[2] = prevPossibility[3];
                            newPossibility[3] = prevPossibility[2];
                        }
                        prevPossibility[0] = newPossibility[0];
                        prevPossibility[1] = newPossibility[1];
                        prevPossibility[2] = newPossibility[2];
                        prevPossibility[3] = newPossibility[3];
                    }
                    results[query.second] = prevPossibility[0];
                } else {
                    bool prevPossibility[4] = {possibility[endIndex][0], possibility[endIndex][1], possibility[endIndex][2], possibility[endIndex][3]};
                    bool newPossibility[4];
                    for (int index = (i + 1)*blockSize - 1; index >= startIndex; index--) {
                        if (s[index] == 'C') {
                            newPossibility[0] = prevPossibility[3];
                            newPossibility[1] = prevPossibility[2];
                            newPossibility[2] = prevPossibility[1];
                            newPossibility[3] = prevPossibility[0];
                        } else if(s[index] == 'O') {
                            newPossibility[0] = prevPossibility[2];
                            newPossibility[1] = prevPossibility[3];
                            newPossibility[2] = prevPossibility[0];
                            newPossibility[3] = prevPossibility[1];
                        } else if (s[index] == 'W') {
                            newPossibility[0] = prevPossibility[1];
                            newPossibility[1] = prevPossibility[0];
                            newPossibility[2] = prevPossibility[3];
                            newPossibility[3] = prevPossibility[2];
                        }
                        prevPossibility[0] = newPossibility[0];
                        prevPossibility[1] = newPossibility[1];
                        prevPossibility[2] = newPossibility[2];
                        prevPossibility[3] = newPossibility[3];
                    }
                    results[query.second] = prevPossibility[0];
                }
            }
    }
    for (int i = 0; i < Q; i++) {
        if (results[i]) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }
    cout << "\n";
    return 0;
}
