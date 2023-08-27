
#include <iostream>
#include <vector>
#include <set>
#include <stack>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int testCase = 0; testCase < t; testCase++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> observations;
        for (int i = 1; i <= m; i++) {
            int numValues;
            cin >> numValues;
            vector<int> newObservation;
            int newValue;
            for (int j = 0; j < numValues; j++) {
                cin >> newValue;
                newObservation.push_back(newValue);
            }
            observations.push_back(newObservation);
        }
        if (m == 1) {
            stack<int> values;
            for (int v : observations[0]) {
                if (!values.empty() && values.top() == v) {
                    values.pop();
                } else {
                    values.push(v);
                }
            }
            if (values.empty()) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (n == 1) {
            int counter = 0;
            for (int i = 0; i < observations.size(); i++) {
                if (observations[i].size() > 0 && (i == 0 || observations[i-1].size() == 0)) {
                    counter++;
                }
            }
            if (counter <= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (n == 2) {
            bool prevContainsTwo = false;
            bool prevContainsOne = false;
            bool containsInvalidElement = false;
            int twosCounter = 0;
            int onesCounter = 0;
            int counts[4] = {0, 0, 0, 0};
            for (int i = 0; i < observations.size(); i++) {
                if (observations[i].size() == 4) {
                    if (observations[i][0] == 1 && observations[i][1] == 1 && observations[i][2] == 2
                        && observations[i][3] == 2) {
                            counts[0]++;
                    } else if (observations[i][0] == 2 && observations[i][1] == 2 && observations[i][2] == 1
                        && observations[i][3] == 1) {
                            counts[1]++;
                    } else if (observations[i][0] == 1 && observations[i][1] == 2 && observations[i][2] == 2
                        && observations[i][3] == 1) {
                            counts[2]++;
                            if (i > 0 && observations[i-1].size() == 2) {
                                if (observations[i-1][0] == 2 && observations[i-1][1] == 2) {
                                    containsInvalidElement = true;
                                }
                            }
                            if (i < observations.size() - 1 && observations[i+1].size() == 2) {
                                if (observations[i+1][0] == 2 && observations[i+1][1] == 2) {
                                    containsInvalidElement = true;
                                }
                            }
                    } else if (observations[i][0] == 2 && observations[i][1] == 1 && observations[i][2] == 1
                        && observations[i][3] == 2) {
                            counts[3]++;
                             if (i > 0 && observations[i-1].size() == 2) {
                                if (observations[i-1][0] == 1 && observations[i-1][1] == 1) {
                                    containsInvalidElement = true;
                                }
                            }
                            if (i < observations.size() - 1 && observations[i+1].size() == 2) {
                                if (observations[i+1][0] == 1 && observations[i+1][1] == 1) {
                                    containsInvalidElement = true;
                                }
                            }
                    } else {
                        containsInvalidElement = true;
                    }
                }

                bool containsOne = false;
                bool containsTwo = false;
                for (int j = 0; j < observations[i].size(); j++) {
                    if (observations[i][j] == 2) {
                        containsTwo = true;
                    } else {
                        containsOne = true;
                    }
                }
                if (containsOne && !prevContainsOne) {
                    onesCounter++;
                }
                if (containsTwo && !prevContainsTwo) {
                    twosCounter++;
                }
                prevContainsTwo = containsTwo;
                prevContainsOne = containsOne;
            }
            int numFourValues = 0;
            for (int i = 0; i < 4; i++) {
                if (counts[i] > 0) {
                    numFourValues++;
                }
            }
            if (twosCounter > 1 || onesCounter > 1 || containsInvalidElement || numFourValues > 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else if (m == 2) {
            // Check validity of each sequence separately (like m = 1 case)
            // Need to ensure that what surrounds us stays constant
            // Need to ensure that something in front of us does not go behind 

            bool containsInvalidElement = false;
            vector<vector<int>> surroundedValues(n + 1);
            vector<set<int>> frontValues(n+1);
            for (int i = 0; i < observations.size(); i++) {
                vector<int> values;
                set<int> inFront;
                for (int v : observations[i]) {
                    vector<int> surround;
                    set<int> frontCopy;
                    if (values.size() > 0 && values[values.size() - 1] == v) {
                        values.pop_back();
                        
                        for (int s : values) {
                            surround.push_back(s);
                        }
                        if (values.size() == 0) {
                            surround.push_back(-1);
                        }
                        if(surroundedValues[v].size() > 0) {
                            if (surroundedValues[v].size() != surround.size()) {
                                containsInvalidElement = true;
                            } else {
                                for (int j = 0; j < surround.size(); j++) {
                                    if (surroundedValues[v][j] != surround[j]) {
                                        containsInvalidElement = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (i == 0) {
                            surroundedValues[v] = surround;
                        }
                        inFront.insert(v);
                    } else {
                        values.push_back(v);
                        for (int s : inFront) {
                            if (frontValues[s].find(v) != frontValues[s].end()) {
                                containsInvalidElement = true;
                            }
                            frontCopy.insert(s);
                        }
                        if (i == 0) {
                            frontValues[v] = frontCopy;
                        }
                    }
                }
                if (values.size() > 0) {
                    containsInvalidElement = true;   
                } 
            }
            if (containsInvalidElement) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            // Add a contiguity constraint - done
            // Check validity of each sequence separately (like m = 1 case) - done
            // Need to ensure that what surrounds us stays constant - done
            // Need to ensure that something in front of us does not go behind 

            bool containsInvalidElement = false;
            vector<vector<int>> surroundedValues(n + 1);
            set<pair<int, int>> frontValues;
            vector<int> countsOfColors(n+1, 0);
            vector<bool> prevContainsColor(n+1, false);
            for (int i = 0; i < observations.size(); i++) {
                vector<int> values;
                vector<int> inFront;
                vector<bool> newContainsColor(n+1, false);
                for (int v : observations[i]) {
                    vector<int> surround;
                    if (values.size() > 0 && values[values.size() - 1] == v) {
                        values.pop_back();
                        
                        for (int s : values) {
                            surround.push_back(s);
                        }
                        if (values.size() == 0) {
                            surround.push_back(-1);
                        }
                        if(surroundedValues[v].size() > 0) {
                            if (surroundedValues[v].size() != surround.size()) {
                                containsInvalidElement = true;
                            } else {
                                for (int j = 0; j < surround.size(); j++) {
                                    if (surroundedValues[v][j] != surround[j]) {
                                        containsInvalidElement = true;
                                        break;
                                    }
                                }
                            }
                        }
                        if (surroundedValues[v].size() == 0) {
                            surroundedValues[v] = surround;
                        }
                        inFront.push_back(v);
                    } else {
                        if (!prevContainsColor[v]) {
                            countsOfColors[v]++;
                            newContainsColor[v] = true;
                        }
                        values.push_back(v);
                        for (int s : inFront) {
                            if (frontValues.find({s, v}) != frontValues.end()) {
                                containsInvalidElement = true;
                            }
                            frontValues.insert({v, s});
                        }
                    }
                }
                prevContainsColor = newContainsColor;
                if (values.size() > 0) {
                    containsInvalidElement = true;   
                } 
            }
            for (int color = 1; color <= n; color++) {
                if (countsOfColors[color] > 1) {
                    containsInvalidElement = true;
                    break;
                }
            }
            if (containsInvalidElement) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
