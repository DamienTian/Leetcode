/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Two Pointer
    //  ref: https://www.cnblogs.com/grandyang/p/4030114.html
    bool isPalindrome(string s)
    {
        
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;            
            }
            if (tolower(s[left++]) != tolower(s[right--])){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
