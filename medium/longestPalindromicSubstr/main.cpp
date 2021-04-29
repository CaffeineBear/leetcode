#include <iostream>
#include <string>

// #include <
using namespace std;

class Solution {
public:
  string longestPalindrome(string & s) {
    string result;

    for( int i = 0; i < s.size() ; ++i){

      
      int front = i - 1;
      int back = i + 1;
      char currChar = s[i];
      
      // setup initial loop for finding consecutive currChar.
      while(front >= 0 || back < s.size()){
        int counter = 0;
        if(front >= 0 && s[front] == currChar) {
          counter++;
          front -= 1;
        }
        if(back < s.size() && s[back] == currChar) {
          counter++;
          back += 1;
        }
        if(counter == 0){
          break;
        }
      }
      
      // if both front and back is still in array range, run loop again
      // for different conditions.
      while(front >= 0 && back < s.size()){
        if(s[front] != s[back]){
          break;
        }
        front -= 1;
        back += 1;
      }

      int currLongest = back - front - 1;
      if(currLongest > result.size()){
        int start = front + 1;
        result = s.substr(start, currLongest);
      }
    }

    return result;
  }

};

int main() {
  string input;
  getline(cin, input);
  Solution s;
  cout << s.longestPalindrome(input) << endl;
}
