/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return twoPtrsHashmap(s);
    }

private:
    // Solution 1: hashmap
    //  ref: https://www.cnblogs.com/grandyang/p/4480780.html
    //  note: see explaination of if statement 
    int twoPtrsHashmap(string s){
        unordered_map<char, int> mem;
        int start = -1, result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            // mem[s[i]] > start indicates the previous same char is still in sliding window
            if (mem.count(s[i]) && mem[s[i]] > start)
            {
                start = mem[s[i]];
            }
            mem[s[i]] = i;
            result = max(result, i - start);
        }
        return result;
    }
};
// @lc code=end

