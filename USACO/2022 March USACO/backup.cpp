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
    int maximumL = ranges[currNode].first;
    int minR = ranges[currNode].second;
    for (int child : children[currNode]) {
        childInfo.push_back(dfs(child));
    }
    bool found = false;
    int intervalLeft = 0;
    int intervalRight = 0;
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
    // If we have a null interval, we simply want to intersect [l, r] and all other intervals as well as we can
    if (!found) {
        intervalLeft = l;
        intervalRight = r;
        for (pair<int, int> p : childInfo) {
            intervalLeft = max(intervalLeft, p.first);
            intervalRight = min(intervalRight, p.second);
        }
        if (intervalRight >= intervalLeft) {
            // 0 is a possible answer here
            if (currNode == 1) {
                assignments[currNode] = make_pair(intervalRight, intervalRight);
                nodeValues[currNode] = intervalRight;
            } else {
                assignments[currNode] = make_pair(intervalLeft, intervalRight);
            }
        } else {
            // [intervalRight, intervalLeft]
            assignments[currNode] = make_pair(intervalRight, intervalLeft);
            int mid = intervalRight + (intervalLeft - intervalRight) / 2;
            if (mid >= l && mid <= r) {
                nodeValues[currNode] = mid;
                minimumImbalance = max(max(minimumImbalance, (intervalLeft - intervalRight)/2), intervalLeft - intervalRight - ((intervalLeft - intervalRight)/2));
            } else {
                int dist1 = INT_MAX;
                int dist2 = INT_MAX;
                if (l >= intervalRight && l <= intervalLeft) {
                    dist1 = max(intervalLeft - l, l - intervalRight);
                }
                if (r >= intervalRight && r <= intervalLeft) {
                    dist2 = max(intervalLeft - r, r - intervalRight);
                }
                if (dist1 <= dist2) {
                    minimumImbalance = max(minimumImbalance, dist1);
                    nodeValues[currNode] = l;
                } else {
                    minimumImbalance = max(minimumImbalance, dist2);
                    nodeValues[currNode] = r;
                }
            }
        }
    } else {
        for (pair<int, int> p : childInfo) {
            if (p.first < p.second) {
                intervalLeft = min(intervalLeft, p.second);
                intervalRight = max(intervalRight, p.first);
            }
        }
        intervalLeft = min(intervalLeft, r);
        intervalRight = max(intervalRight, l);
        assignments[currNode] = make_pair(intervalLeft, intervalRight);
        int temp = intervalLeft;
        intervalLeft = intervalRight;
        intervalRight = temp;
        int mid = intervalRight + (intervalLeft - intervalRight) / 2;
        if (mid >= l && mid <= r) {
            nodeValues[currNode] = mid;
            minimumImbalance = max(max(minimumImbalance, (intervalLeft - intervalRight)/2), intervalLeft - intervalRight - ((intervalLeft - intervalRight)/2));
        } else {
            int dist1 = INT_MAX;
            int dist2 = INT_MAX;
            if (l >= intervalRight && l <= intervalLeft) {
                dist1 = max(intervalLeft - l, l - intervalRight);
            }
            if (r >= intervalRight && r <= intervalLeft) {
                dist2 = max(intervalLeft - r, r - intervalRight);
            }
            if (dist1 <= dist2) {
                minimumImbalance = max(minimumImbalance, dist1);
                nodeValues[currNode] = l;
            } else {
                minimumImbalance = max(minimumImbalance, dist2);
                nodeValues[currNode] = r;
            }
        }

    }
    // If we have a necessary interval, we can greedily select which side (or none) for the fluid intervals -> then can choose 
    // cout << "Node " << currNode << " : " << minimumImbalance <<  " with assignment " << nodeValues[currNode] << endl;
    return make_pair(maximumL, minR);
}

void assign(int currNode, int currLeft, int currRight) {
    // cout << "Node " << currNode << " assigned " << nodeValues[currNode] << " current currLeft and currRight are " << currLeft << " and " << currRight << endl;
    if (nodeValues[currNode] < 0) {
        int value = min(currRight, ranges[currNode].second);
        nodeValues[currNode] = value;
        currRight = min(currRight, value + minimumImbalance);
        currLeft = max(currLeft, value - minimumImbalance);
    }
    if (assignments[currNode].second - assignments[currNode].first >= 0) {
        currLeft = max(currLeft, assignments[currNode].first);
        currRight = min(currRight, assignments[currNode].second);
    }
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
            assign(1, assignments[1].first, assignments[1].second);
            for (int node = 1; node <= n; node++) {
                cout << nodeValues[node] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
