#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minimumImbalance = 0;
pair<int, int> ranges[100001];
pair<int, int> assignments[100001];
vector<int> children[100001];
int nodeValues[100001];

pair<int, int> dfs(int currNode) {
    vector<pair<int, int>> childInfo;
    int l = ranges[currNode].first;
    int r = ranges[currNode].second;
    int maximumL = INT_MIN;
    int minR = INT_MAX;
    for (int child : children[currNode]) {
        childInfo.push_back(dfs(child));
    }
    bool found = false;
    int intervalLeft = INT_MIN;
    int intervalRight = INT_MAX;
    for (pair<int, int> p : childInfo) {
        maximumL = max(maximumL, p.first);
        minR = min(minR, p.second);
        if (p.first >= p.second) {
            if (!found) {
                intervalLeft = p.second;
            } else {
                intervalLeft = min(intervalLeft, p.second);
            }
            if (!found) {
                found = true;
                intervalRight = p.first;
            } else {
                intervalRight = max(intervalRight, p.first);
            }
        }
    }
    assignments[currNode] = {maximumL, minR};
    maximumL = max(maximumL, l);
    minR = min(minR, r);
    // If we have a null interval, we simply want to intersect [l, r] and all other intervals as well as we can
    if (!found) {
        for (pair<int, int> p : childInfo) {
            intervalLeft = max(intervalLeft, p.first);
            intervalRight = min(intervalRight, p.second);
        }
        if (intervalRight >= intervalLeft) {
            // 0 is a possible answer here
            if (currNode == 1) {
                nodeValues[currNode] = intervalRight;
            } 
        } else {
            // [intervalRight, intervalLeft]
            // assignments[currNode] = make_pair(intervalRight, intervalLeft);
            int mid = intervalRight + (intervalLeft - intervalRight) / 2;
            if (mid >= l && mid <= r) {
                if (currNode == 1) {
                    nodeValues[currNode] = mid;
                }
                minimumImbalance = max(max(minimumImbalance, (intervalLeft - intervalRight)/2), intervalLeft - intervalRight - ((intervalLeft - intervalRight)/2));
            } else {
                int dist1 = intervalLeft - intervalRight;
                int dist2 = intervalLeft - intervalRight;
                dist1 = max(max(l - intervalRight, intervalRight - l), max(l - intervalLeft, intervalLeft - l));
                dist2 = max(max(r - intervalRight, intervalRight - r), max(r - intervalLeft, intervalLeft - r));
                if (dist1 <= dist2) {
                    if (currNode == 1) {
                        nodeValues[currNode] = l;
                    }
                    // assignments[currNode] = {intervalRight, intervalLeft};
                    minimumImbalance = max(minimumImbalance, dist1);
                } else {
                    minimumImbalance = max(minimumImbalance, dist2);
                    // assignments[currNode] = {intervalRight, intervalLeft};
                    if (currNode == 1) {
                        nodeValues[currNode] = r;
                    }
                }
                // int dist1 = INT_MAX;
                // int dist2 = INT_MAX;
                // if (l >= intervalRight && l <= intervalLeft) {
                //     dist1 = max(intervalLeft - l, l - intervalRight);
                // }
                // if (r >= intervalRight && r <= intervalLeft) {
                //     dist2 = max(intervalLeft - r, r - intervalRight);
                // }
                // if (dist1 <= dist2) {
                //     minimumImbalance = max(minimumImbalance, dist1);
                //     if (currNode == 1) {
                //         nodeValues[currNode] = l;
                //     }
                   
                // } else {
                //     minimumImbalance = max(minimumImbalance, dist2);
                //     if (currNode == 1) {
                //         nodeValues[currNode] = r;
                //     }
                // }
            }
        }
    } else {
        for (pair<int, int> p : childInfo) {
            if (p.first < p.second) {
                intervalLeft = min(intervalLeft, p.second);
                intervalRight = max(intervalRight, p.first);
            }
        }
        // intervalLeft = min(intervalLeft, r);
        // intervalRight = max(intervalRight, l);

        // assignments[currNode] = make_pair(intervalLeft, intervalRight);
        int temp = intervalLeft;
        intervalLeft = intervalRight;
        intervalRight = temp;
        int mid = intervalRight + (intervalLeft - intervalRight) / 2;
        if (mid >= l && mid <= r) {
            if (currNode == 1) {
                nodeValues[currNode] = mid;
            }
            // assignments[currNode] = make_pair(intervalRight, intervalLeft);
            minimumImbalance = max(max(minimumImbalance, (intervalLeft - intervalRight)/2), intervalLeft - intervalRight - ((intervalLeft - intervalRight)/2));
        } else {
            int dist1 = intervalLeft - intervalRight;
            int dist2 = intervalLeft - intervalRight;
            dist1 = max(max(l - intervalRight, intervalRight - l), max(l - intervalLeft, intervalLeft - l));
            dist2 = max(max(r - intervalRight, intervalRight - r), max(r - intervalLeft, intervalLeft - r));
            if (dist1 <= dist2) {
                if (currNode == 1) {
                    nodeValues[currNode] = l;
                }
                // assignments[currNode] = {intervalRight, intervalLeft};
                minimumImbalance = max(minimumImbalance, dist1);
            } else {
                if (currNode == 1) {
                    nodeValues[currNode] = r;
                }
                minimumImbalance = max(minimumImbalance, dist2);
                // assignments[currNode] = {intervalRight, intervalLeft};
            }
        }

    }
    // If we have a necessary interval, we can greedily select which side (or none) for the fluid intervals -> then can choose 
    // cout << "Node " << currNode << " : " << minimumImbalance <<  " with assignment " << nodeValues[currNode] << endl;
    return make_pair(maximumL, minR);
}

void assign(int currNode, int currLeft, int currRight) {    
    if (nodeValues[currNode] < 0) {
        int maxL = assignments[currNode].first;
        int minR = assignments[currNode].second;
        if (ranges[currNode].first == ranges[currNode].second) {
            nodeValues[currNode] = ranges[currNode].first;
        } else {
            if (maxL == INT_MAX || minR == INT_MIN) {
                // We are at a leaf -- just intersect
                nodeValues[currNode] = max(ranges[currNode].first, currLeft);
            } else {
                if (maxL <= minR) {
                    // Open to any points in that interval -- let's intersect ranges[currNode] with currLeft, currRight and this interval
                    int left = max(max(currLeft, ranges[currNode].first), maxL);
                    nodeValues[currNode] = left;
                } else {
                    // [minR, maxL]
                    int left = max(max(minR - minimumImbalance, currLeft), ranges[currNode].first);
                    nodeValues[currNode] = left;
                }
            }
        }
    }
    currRight = min(currRight, nodeValues[currNode] + minimumImbalance);
    currLeft = max(currLeft, nodeValues[currNode] - minimumImbalance);
    for (int child : children[currNode]) {
        assign(child, currLeft, currRight);
    }
}


int main() {
    int t, b;
    cin >> t >> b;
    while (t--) {
        int n;
        cin >> n;
        minimumImbalance = 0;
        for (int i = 1; i <= n; i++) {
            children[i] = vector<int>();
            assignments[i] = {-1, -2};
            nodeValues[i] = -1;
        }
        for (int node = 2; node <= n; node++) {
            int parent;
            cin >> parent;
            children[parent].push_back(node);
        }
        for (int node = 1; node <= n; node++) {
            int l, r;
            cin >> l >> r;
            ranges[node] = make_pair(l, r);
        }
        dfs(1);
        cout << minimumImbalance << endl;
        if (b == 1) {
            assign(1, INT_MIN, INT_MAX);
            for (int node = 1; node <= n; node++) {
                cout << nodeValues[node] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
