/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: DP with O(n) space
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<int> dp(grid[0].size());
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(i == 0 && j == 0)
                    dp[0] = grid[0][0];
                else if(i == 0)
                    dp[j] = dp[j - 1] + grid[0][j];
                else if(j == 0)
                    dp[0] += grid[i][0];
                else
                    dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
            }
        }
        return dp.back();
    }
};
// @lc code=end
