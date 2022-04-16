/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Failed Solution: DFS (Time Limit Exceeded)
    // int combinationSum4(vector<int>& nums, int target) {
    //     if(target == 0)
    //         return 1;
    //     if(target < 0)
    //         return 0;

    //     int result = 0;
    //     for(int n : nums){
    //         result += combinationSum4(nums, target - n);
    //     }
    //     return result;
    // }

    // Solution 1: DFS + memoization
    //  ref: https://www.cnblogs.com/grandyang/p/5705750.html
    // int combinationSum4(vector<int> &nums, int target)
    // {
    //     return combine(nums, target);
    // }

    // Solution 2: DP
    //  ref: https://www.cnblogs.com/grandyang/p/5705750.html
    int combinationSum4(vector<int> &nums, int target)
    {   
        // note: change to unsigned int to pass all testcases
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;  // empty combination is always 1, which is []
        for(int i = 1; i <= target; ++i){
            for (auto a : nums) {
                if (i >= a) 
                    dp[i] += dp[i - a];
            }
        }
        return dp[target];
    }

private:
    int combine(const vector<int> &nums, int target)
    {
        if (target == 0)
            return 1;
        if (target < 0)
            return 0;
        if (mem.count(target))
            return mem[target];

        int result = 0;
        for (int n : nums)
        {
            result += combine(nums, target - n);
        }
        return mem[target] = result;
    }
    
    unordered_map<int, int> mem;
};
// @lc code=end
