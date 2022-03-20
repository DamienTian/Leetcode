/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
// #include "dummyHead.h"

class Solution {
public:
    // Failed Solution: Two Pointers (Time Limit Exceeded)
    // string longestPalindrome(string s) {
    //     string result = "";
    //     for(int i = 0; i < s.length(); ++i){
    //         for(int j = i; j < s.length(); ++j){
    //             int start = i, end = j;
    //             bool isPalindromic = true;
    //             while(start < end){
    //                 if(s[start++] != s[end--]){
    //                     isPalindromic = false;
    //                     break;
    //                 }
    //             }
    //             if(isPalindromic)
    //                 result = (j - i + 1) > result.length() ? s.substr(i, j - i + 1) : result;
    //         }
    //     }
    //     return result;
    // }

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

