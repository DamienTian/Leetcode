/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DP (brute force)
    //  ref: https://www.cnblogs.com/grandyang/p/4938187.html
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 0;
        // for every num, search all smaller element before it
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    // note: O(nlogn) solution involve binary search, but doesn't perserve right LIS order
};
// @lc code=end

