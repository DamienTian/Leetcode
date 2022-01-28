/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

// IDEA: DP
// Note: there exist Divide and Conqure method:
//  ref: https://www.cnblogs.com/grandyang/p/4079165.html (solution 4)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp (n + 1, 0);
        dp[0] = 1;

        for(size_t i = 1; i <= n; i++){     // O(n)
            for(int s = 1; s <= 2; s++){    // O(1)
            int c = i - s;
                if(c >= 0){
                    dp[i] += dp[c];
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

