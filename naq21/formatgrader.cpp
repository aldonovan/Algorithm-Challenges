#include <iostream>
#include <vector>
using namespace std;
int main() {
    int c, n;
    cin >> c >> n;
    int lastError = 0;
    vector<pair<int, int>> errors;
    vector<pair<int, int>> correct;
    for (int i = 0; i < n; i++) {
        int currentError;
        cin >> currentError;
        if (lastError + 1 < currentError) {
            correct.push_back({lastError + 1, currentError - 1});
        }
        if (lastError == 0 || lastError != currentError - 1) {
            errors.push_back({currentError, currentError});
        } else {
            errors[errors.size() - 1].second++;
        }
        lastError = currentError;
    }
    if (lastError + 1 <= c) {
        correct.push_back({lastError + 1, c});
    }
    cout << "Errors: ";
    for (int i = 0; i < errors.size(); i++) {
        if (errors[i].first == errors[i].second) {
            cout << errors[i].first;
        } else {
            cout << errors[i].first << '-' << errors[i].second;
        }
        if (i == errors.size() - 2) {
            cout << " and ";
        } else if (i < errors.size() - 2) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Correct: ";
    for (int i = 0; i < correct.size(); i++) {
        if (correct[i].first == correct[i].second) {
            cout << correct[i].first;
        } else {
            cout << correct[i].first << '-' << correct[i].second;
        }
        if (i == correct.size() - 2) {
            cout << " and ";
        } else if (i < correct.size() - 2) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}
