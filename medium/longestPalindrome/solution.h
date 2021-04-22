#include <string>
#include <map>

using namespace std;

class Solution {
public:
    static string longestPalindrome(string s) {
        string result;
        map<string, bool> isPalidromDict;
        for(int subStrSize = s.size() - 1; subStrSize > 0; --subStrSize){
            for(int i = 0; i <= s.size() - subStrSize; ++i){
                string currSubstr = s.substr(i, subStrSize);
                if(isPalidromDict.find(currSubstr) == isPalidromDict.end() ){
                    bool passed = isPalindrom(currSubstr);
                    if(passed){
                        if(result.size() < currSubstr.size()){
                            result = currSubstr;
                        }
                    }
                    isPalidromDict[currSubstr] = passed;
                }
            }
        }
        return result;
    }
    static bool isPalindrom(string subStr){
        int n = subStr.size();
        bool result = true;
        for(int i = 0; i < n/2; ++i){
            if(subStr[i] != subStr[n-i-1]){
                result = false;
                return result;
            }
        }
        return result;
    }
};