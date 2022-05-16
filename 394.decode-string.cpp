/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: dfs (recursion)
    //  ref: https://www.cnblogs.com/grandyang/p/5849037.html
    string decodeString(string s) {
        int index = 0;
        return dfs(s, index);
    }

private:
    string dfs(const string& s, int& index){
        string result = "";
        int n = s.size();
        while(index < n && s[index] != ']'){
            // append chars
            if(s[index] < '0' || s[index] > '9')
                result += s[index++];
            else{
                // count for # of appears
                int count = 0;
                // loop all numbers
                while(s[index] >= '0' && s[index] <= '9'){
                    count = count * 10 + s[index++] - '0';
                }
                ++index; // skip '['
                // search string inside the []
                string t = dfs(s, index);
                ++index; // skip ']'
                while(count-- > 0)
                    result += t;
            }
        }
        return result;
    }
};
// @lc code=end

