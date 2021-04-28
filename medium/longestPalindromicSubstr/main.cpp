struct hashpair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    static constexpr int START_IND = 0;
    static constexpr int END_IND = 1;
    static constexpr int LENGTH_IND = 2;
    
    string longestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        }
        string result;
        // vector<int> maxStrPos(3);
        int maxStrPos[3] = {-1, -1, -1};
        unordered_map<pair<int, int>,bool, hash_pair> palindDict; 
        for(int subStrSize = s.size(); subStrSize > 0; --subStrSize){
            for(int i = 0; i <= s.size() - subStrSize; ++i){
                if(palindDict.find(make_pair( i , i+subStrSize)) != palindDict.end() ){
                    continue;
                }
                bool passed = isPalindrom(s, i , i+subStrSize);
                if(passed){
                    int currMaxSize = maxStrPos[LENGTH_IND];
                    if(currMaxSize < subStrSize){
                        maxStrPos[START_IND] = i;
                        maxStrPos[END_IND] = i + subStrSize;
                        maxStrPos[LENGTH_IND] = subStrSize;
                    }
                }
                palindDict[make_pair( i , i+subStrSize)] = passed;
            }
        }
        result = s.substr(maxStrPos[START_IND], maxStrPos[LENGTH_IND]);
        return result;
    }
    // end exclusive
    static bool isPalindrom(string str, int start, int end){
        int n = end - start;
        bool result = true;
        int counter = 0;
        for(int i = start; i < (start + n/2); ++i){
            if(str[i] != str[end - 1 - counter]){
                result = false;
                break;
            }
            counter++;
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
};_
