/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start

//#include "dummyHead.h"

class Solution
{
public:
    // Failed Solution: Two Pointers (Time Limit Exceeded, 129/130 cases passed (N/A))
    // int countSubstrings(string s)
    // {
    //     if (s.empty())
    //         return 0;
    //     int result = 0;
    //     for (int maxLen = 1; maxLen <= s.length(); ++maxLen)
    //     {
    //         for (int i = 0; i < s.length(); ++i)
    //         {
    //             if (maxLen % 2 != 0)
    //                 searchPalindrome(s, i, i, result, maxLen);
    //             else
    //                 searchPalindrome(s, i, i + 1, result, maxLen);
    //         }
    //     }
    //     return result;
    // }

    // Solution 1: Two Pointers
    //  ref: https://www.cnblogs.com/grandyang/p/7404777.html
    int countSubstrings(string s)
    {
        if (s.empty())
            return 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            searchPalindrome(s, i, i, result);
            searchPalindrome(s, i, i + 1, result);
        }
        return result;
    }

private:
    // left, right stands for start search index
    void searchPalindrome(string s, int left, int right, int &result, int maxLen)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right] && (right - left - 1) < maxLen)
        {
            left--;
            right++;
        }
        if (right - left - 1 == maxLen)
        {
            // cout << s.substr(left + 1, maxLen) << endl;
            result += 1;
        }
    }

    void searchPalindrome(string s, int left, int right, int &result)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
            result++;
        }
    }
};
// @lc code=end
