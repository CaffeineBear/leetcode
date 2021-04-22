#include <iostream>
#include <map>
using namespace std;

/**
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        map<char, int> charCounter;
        string currSub;
        for(char c: s){
            charCounter[c]++;
            currSub += c;
            if(charCounter[c] == 1){
                if(max < currSub.size()){
                    max = currSub.size();
                }
                continue;
            }

            int pos = currSub.find(c);
            if(pos != string::npos){
                string subStrToDelete = currSub.substr(0, pos + 1);
                this->updateCharCounter(charCounter, subStrToDelete);
                currSub = currSub.substr(pos + 1);
            }
        }

        return max;
    }
private:
    void updateCharCounter(map<char, int> & charCounter, string deletedSubstr){
        for(char c: deletedSubstr){
            charCounter[c] -= 1;
        }
    }
    void printCharCounter(map<char, int> & charCounter){
        cout << "charCounter: ";

        for(auto &it : charCounter){
            cout << it.first << " -> " << it.second << ", ";
        }
        cout << endl;
    }
};