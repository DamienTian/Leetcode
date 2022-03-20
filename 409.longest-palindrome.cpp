/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    // Solution 1: Hash map
    //  ref: https://www.cnblogs.com/grandyang/p/5931874.html
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(const char& c : s)
            m[c]++;
        int result = 0;
        // if the palindrome can have a single letter at the middle
        bool hasMid = false;
        for(auto mm : m){
            result += mm.second;
            // if the length of char is odd, add the max even count of it
            if(mm.second % 2 != 0){
                hasMid = true;
                result -= 1;
            }
        }

        return hasMid ? result + 1 : result;
    }
};
// @lc code=end

