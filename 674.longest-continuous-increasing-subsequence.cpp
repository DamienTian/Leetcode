/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: DP
    //  note: dp array can be replace by a single int counter to count the current length  
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 1;
        vector<int> dp(nums.size(), 1);
        for(int i = 1; i < dp.size(); ++i){
            if(nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end

