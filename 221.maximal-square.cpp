/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: DP
    //  ref: https://www.cnblogs.com/grandyang/p/4550604.html
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) 
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || j == 0)
                    dp[i][j] = matrix[i][j] - '0';
                else if(matrix[i][j] == '1')
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};
// @lc code=end

