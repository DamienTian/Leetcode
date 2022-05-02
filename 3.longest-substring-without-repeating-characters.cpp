/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: sliding window (using hashmap)
    //  ref (partially for if statement): https://www.cnblogs.com/grandyang/p/4480780.html
    int lengthOfLongestSubstring(string s)
    {
        int left = -1, right = 0;
        int result = 0;
        // exist records the char's last appears index
        unordered_map<char, int> exist;
        while (right < s.size())
        {
            if (exist.count(s[right]) && exist[s[right]] > left)
                left = exist[s[right]];
            exist[s[right]] = right;
            result = max(result, right - left);
            right++;
        }
        return result;
    }
};
// @lc code=end
