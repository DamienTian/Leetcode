/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start

#include "dummyHead.h"

class Solution {
public:
    string decodeString(string s) {
        return dfsRecursion(s);
    }

private:
    // Solution 1: dfs recursion
    //  ref: https://www.cnblogs.com/grandyang/p/5849037.html
    string dfsRecursion(string s){
        // current search index
        int index = 0;
        return dfs(s, index);
    }

    string dfs(string s, int& index){
        string result = "";
        int n = s.size();

        while(index < n && s[index] != ']'){
            // if char, append it to the result
            if(s[index] < '0' || s[index] > '9')
                result += s[index++];

            // if not, it would be a number or [ ]
            else{
                int count = 0;
                // process if it is digit
                while(s[index] >= '0' && s[index] <= '9'){
                    count = count * 10 + s[index++] - '0';
                }

                ++index;    // skip the '['
                string insideStr = dfs(s, index); // took out inside string
                ++index;    // skip the ']'
                
                // append inside string at the end of result
                while(count-- > 0)
                    result += insideStr;
            }
        }
        return result;
    }

    // Solution 2: dfs iteration
    //  ref: https://www.cnblogs.com/grandyang/p/5849037.html
};
// @lc code=end

