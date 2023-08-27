#include <iostream>
using namespace std;
int main() {
  int t;
  string digits;
  cin >> t;
  for(int c = 1; c <= t; c++) {
    cin >> digits;
    string minimal = "";
    int parentheses = 0;
    for(int i = 0; i < digits.length(); i++) {
      char digit = digits[i];
      int number = digit - '0';
      for(int p = parentheses; p < number; p++) {
        minimal += "(";
      }
      for(int p = parentheses; p > number; p--) {
        minimal += ")";
      }
      minimal += digit;
      parentheses = number;
    }
    for(int i = 0; i < parentheses; i++) {
      minimal += ")";
    }
    cout << "Case #" << c << ": " << minimal << endl;
  }
  return 0;
}
