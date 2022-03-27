/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
// #include "dummyHead.h"

// Solution: Backtracking
//  note: take a look at grandyang's version
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s, 0, 3, result);
        return result;
    }

private:
    int strToInt(const string& s){
        int result = 0;
        for(char c : s){
            if(result * 10 + (c - '0') <= 255){
                result = result * 10 + (c - '0');
            }
            else{
                result = INT_MAX;
                break;
            }
        }
        return result;
    }

    void backtrack(string& s, int sIndex, int remainDot, vector<string>& result){
        if(remainDot == 0){
            string lastStr = s.substr(sIndex);
            int last = strToInt(lastStr);
            if(last >= 0 && last <= 255 && s[s.size() - 1] != '.' && 
                (lastStr.size() == 1 || (lastStr.size() > 1 && lastStr[0] != '0')))
                result.push_back(s);
            return;
        }
        for(int i = sIndex; i < s.length(); ++i){
            string t = s.substr(sIndex, i - sIndex + 1);
            if(t[0] == '0' && t.length() > 1)
                break;
            int tInt = strToInt(t);
            if(tInt >= 0 && tInt <= 255){
                s.insert(i + 1, ".");
                backtrack(s, i + 2, remainDot - 1, result);
                s.erase(i + 1, 1);
            }
        }
    }
};


// @lc code=end

