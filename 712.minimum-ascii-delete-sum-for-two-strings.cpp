/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DP (2D)
    //  ref: https://github.com/grandyang/leetcode/issues/712
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        for(int i = 1; i <= m; ++i){
            dp[i][0] = dp[i - 1][0] + s1[i-1];
            for(int j = 1; j <= n; ++j){
                dp[i][j] = (s1[i - 1] == s2[j - 1]) 
                    ? dp[i - 1][j - 1]  // if two char equal, no need to delete char
                    //      delete s1[i-1]              delete s2[j-1]            
                    : min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

