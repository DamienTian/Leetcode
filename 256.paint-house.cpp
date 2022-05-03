/*
 * @lc app=leetcode id=256 lang=cpp
 *
 * [256] Longest Increasing Subsequence
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DP (brute force: O(n^3))
    //  note: this solution works with more than 3 colors
    int minCost(vector<vector<int>> &costs)
    {
        vector<vector<int>> dp(costs.size(), vector<int>(costs[0].size(), 0));
        for (int i = 0; i < costs.size(); ++i)
        {
            for (int j = 0; j < costs[0].size(); ++j)
            {
                if (i == 0)
                    dp[i][j] = costs[i][j];
                else
                {
                    int minCost = INT_MAX;
                    for (int k = 0; k < costs[0].size(); ++k)
                    {
                        if (k != j)
                            minCost = min(minCost, dp[i - 1][k]);
                    }
                    dp[i][j] = costs[i][j] + minCost;
                    //printMatrix2DInt(dp);
                }
            }
        }
        return *(min_element(dp[costs.size() - 1].begin(), dp[costs.size() - 1].end()));
    }
};

// @lc code=end