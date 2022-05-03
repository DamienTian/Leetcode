/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DP (O(n^2))
    // int jump(vector<int>& nums) {
    //     vector<int> dp(nums.size(), INT_MAX);
    //     dp[0] = 0;
    //     for(int i = 0; i < nums.size(); ++i){
    //         for(int j = 1; j <= nums[i]; ++j){
    //             if(i + j < nums.size())
    //                 dp[i + j] = min(dp[i + j], dp[i] + 1);
    //         }
    //     }
    //     return dp.back();
    // }

    // Solution 2: Greedy (O(n))
    //  ref: https://www.cnblogs.com/lichen782/p/leetcode_Jump_Game_II.html
    int jump(vector<int>& nums){
        int result = 0;
        // current furthest index and previous furthest index
        int curr = 0, prev = 0;
        for(int i = 0; i < nums.size() - 1; ++i){
            curr = max(curr, i + nums[i]);
            if(i >= prev){
                prev = curr;
                result++;
                if(curr >= nums.size() - 1)
                    break;
            }
        } 
        return result;
    }
};
// @lc code=end

