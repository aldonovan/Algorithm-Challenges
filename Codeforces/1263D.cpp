#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<unordered_set<char> > diffPasswords;
  string password;
  for(int i = 0; i < n; i++) {
    cin >> password;
    unordered_set<char> passLetters;
    for(int p = 0; p < password.length(); p++) {
      passLetters.insert(password[p]);
    }
    for(int j = diffPasswords.size()-1; j >= 0; j--) {
      bool intersection = false;
      for(char c: diffPasswords[j]) {
        if(passLetters.find(c) != passLetters.end()) {
          intersection = true;
          break;
        }
      }
      if(intersection) {
        for(char c: diffPasswords[j]) {
          passLetters.insert(c);
        }
        diffPasswords.erase(diffPasswords.begin() + j);
      }
    }
    diffPasswords.push_back(passLetters);
  }
  cout << diffPasswords.size() << endl;
  return 0;
}
