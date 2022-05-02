/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: sliding window 
    //  ref: https://www.cnblogs.com/grandyang/p/5999050.html
    int characterReplacement(string s, int k) {
        // sliding window start index (left index)
        int start = 0;
        // maxcount count for current max amount of a char appears
        int result = 0, maxCount = 0;
        unordered_map<char, int> counts;
        for(int i = 0; i < s.size(); ++i){
            maxCount = max(maxCount, ++counts[s[i]]);
            // if current substring doesn't satisfy: substring has same char len < s.size() - k;
            while(i - start + 1 - maxCount > k){
                // slide window to right
                --counts[s[start++]];
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};
// @lc code=end

