/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DP
    //  note: check grandyang's blog for a shorter version, and idea is different with mine too
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        if(target == 0)
            return true;
        vector<int> dp(target);
        dp[0] = nums[0];
        for(int i = 1; i < target; ++i){
            if(dp[i - 1] > (nums[i] + i))
                dp[i] = dp[i - 1];
            else
                if(dp[i-1] < i)
                    dp[i] = 0;
                else
                    dp[i] = i + nums[i];
        }
        return dp.back() >= target;
    }

    // Solution 2: Greedy
    //  ref: https://www.cnblogs.com/grandyang/p/4371526.html
    bool canJump(vector<int>& nums) {
        // reach: the furthest index can reach at previous step
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};
// @lc code=end

