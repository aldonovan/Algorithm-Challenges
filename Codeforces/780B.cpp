#include <iostream>
using namespace std;

bool friendsCanMeet(int friendLocations[], int friendSpeeds[], int
    numFriends, double time) {
    double lowestHigherPosition = INT_MAX; 
    double highestLowerPosition = 0;

    for(int i = 0; i < numFriends; i++) {
        lowestHigherPosition = min(lowestHigherPosition, friendLocations[i]
            + friendSpeeds[i]*time);
        highestLowerPosition = max(highestLowerPosition, friendLocations[i]
            - friendSpeeds[i]*time);
    }
    return lowestHigherPosition >= highestLowerPosition;
}

int main() {
    int numFriends;
    cin >> numFriends;
    int friendLocations[numFriends];
    int friendSpeeds[numFriends];
    for(int i = 0; i < numFriends; i++) {
        cin >> friendLocations[i];
    }
    for(int i = 0; i < numFriends; i++) {
        cin >> friendSpeeds[i];
    }
    double low = 0.0;
    double high = 1000000000.0;
    double minTimeToMeet = INT_MAX;
    while(low <= high - 0.0000001) {
        double mid = low + (high - low)/2.0;
        if(friendsCanMeet(friendLocations, friendSpeeds, numFriends, mid)) {
            minTimeToMeet = mid;
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << minTimeToMeet << endl;
    return 0;
}