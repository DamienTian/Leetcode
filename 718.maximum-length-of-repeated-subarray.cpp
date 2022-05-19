/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DP
    //  ref: https://www.cnblogs.com/grandyang/p/7801533.html
    int findLength(vector<int>& A, vector<int>& B) {
        int result = 0;
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for(size_t i = 1; i <= A.size(); ++i){
            for(size_t j = 1; j <= B.size(); ++j){
                dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i-1][j-1] + 1 : 0;
                result = max(result, dp[i][j]);
            }
        }
        return result;
    }
};
// @lc code=end
