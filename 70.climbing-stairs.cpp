/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

// #include "dummyHead.h"

// IDEA: DP
// Note: there exist Divide and Conqure method:
//  ref: https://www.cnblogs.com/grandyang/p/4079165.html (solution 4)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp.back();
    }
};
// @lc code=end

