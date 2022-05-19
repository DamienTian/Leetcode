/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: DP
    //  ref: https://www.cnblogs.com/grandyang/p/15732848.html
    //  note: same as #211, think about it
    int countSquares(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp = matrix;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dp[i][j] > 0 && i > 0 && j > 0)
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                result += dp[i][j];
            }
        }
        return result;
    }
};
// @lc code=end
