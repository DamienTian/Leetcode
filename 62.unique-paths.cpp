/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    // Solution 1: DP
    //  note: could deduce the space to O(n) by only keep the previous row 
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n, 1));
    //     for(int i = 1; i < m; ++i){
    //         for(int j = 1; j < n; ++j){
    //             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }
    
    // Solution 2: Recursive
    //  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-62-unique-paths/
    int uniquePaths(int m, int n) {
        if(m < 0 || n < 0)  return 0;
        if(m == 1 && n == 1) return 1;
        if(mem[m][n] > 0)   return mem[m][n];
        mem[m][n] = uniquePaths(m-1, n) + uniquePaths(m, n-1);
        return mem[m][n];
    }

private:
    unordered_map<int, unordered_map<int, int>> mem;
};
// @lc code=end

