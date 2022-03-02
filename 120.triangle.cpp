/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    // Solution: DP
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() < 2){
            return triangle[0][0];
        }
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for(int i = 1; i < triangle.size(); ++i){
            vector<int> newDP(dp.size() + 1, numeric_limits<int>::max());
            for(int j = 0; j < dp.size(); ++j){
                newDP[j] = min(newDP[j], dp[j] + triangle[i][j]);
                newDP[j+1] = min(newDP[j+1], dp[j] + triangle[i][j+1]);
            }
            dp = newDP;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end

