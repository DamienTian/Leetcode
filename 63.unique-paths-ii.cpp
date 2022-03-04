/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: DP
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // init dp table: filled the side of the dp
        bool obstacleOnTop = false, obstacleOnleftSide = false;
        for(int i = 0; i < m; ++i){
            if(obstacleGrid[i][0] || obstacleOnleftSide){
                obstacleOnleftSide = true;
                dp[i][0] = 0;
            }
            else{
                dp[i][0] = 1;
            }
        }
        for(int j = 0; j < n; ++j){
            if(obstacleGrid[0][j] || obstacleOnTop){
                obstacleOnTop = true;
                dp[0][j] = 0;
            }
            else{
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }

    // Solution 2: DP (a less complex way)
    //  ref: https://www.cnblogs.com/grandyang/p/4353680.html
    // TODO: pass for now, need to check the solution later
};
// @lc code=end