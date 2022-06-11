/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include "dummyHead.h"

class Solution {
public:
    // Solution 1: Two Pointer
    //  ref: https://www.cnblogs.com/grandyang/p/4464476.html
    string longestPalindrome(string s) {
        if(s.size() < 2)
            return s;
        int start = 0, maxLen = 0;
        for(int i = 0; i < s.length() - 1; ++i){
            // search for odd length palindrome
            searchPalindrome(s, i, i, start, maxLen);
            // search for even length palindrome
            searchPalindrome(s, i, i + 1, start, maxLen);
        }
        return s.substr(start, maxLen);
    }

private:
    // left, right stands for start search index  
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        if(maxLen < right - left - 1){
            start = left + 1;
            maxLen = right - left - 1;
        }
    }
};
// @lc code=end

