/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    // Solution 1: DP 
    //  Note: could optimize the space to O(1) by just remember the previous two steps.
    // int minCostClimbingStairs(vector<int>& cost) {
    //     vector<int> dp (cost.size(), numeric_limits<int>::max());
    //     dp[0] = cost[0];
    //     dp[1] = cost[1];
    //     for(size_t i = 2; i < cost.size(); ++i){
    //         for(int s = 1; s < 3; ++s){
    //             int c = i - s;
    //             if(c >= 0 && dp[i] > (dp[c] + cost[i])){
    //                 dp[i] = dp[c] + cost[i];
    //             }
    //         }
    //     }
    //     return min(dp[cost.size()-2], dp[cost.size()-1]);
    // }

    // Solution 2: DP with recursion;
    int minCostClimbingStairs(const vector<int>& cost) {
        vector<int> dp (cost.size() + 1);
        return recursion(cost, dp, cost.size());
    }

    int recursion(const vector<int>& cost, vector<int>& mem, int step){
        if(step < 2){
            return 0;
        }
        if(mem[step] > 0){
            return mem[step];
        }
        return mem[step] = min(recursion(cost, mem, step - 1) + cost[step - 1], 
                        recursion(cost, mem, step - 2) + cost[step - 2]);
        
    }
};
// @lc code=end

