/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    int rob(vector<int>& nums) {
        return dp(nums);
    }
private:
    // Solution 1: my dp
    int mydp(const vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> m(nums.size());
        m[0] = nums[0];
        m[1] = max(m[0], nums[1]);
        int result = max(m[0], m[2]);
        for(int i = 2; i < m.size(); ++i){
            m[i] = max(m[i-1] , m[i-2] + nums[i]);
            result = max(result, m[i]);
        }
        return result;
    }

    // Solution 2: dp with constant space
    //  ref: https://www.cnblogs.com/grandyang/p/4383632.html
    int dp(const vector<int>& nums){
        // indicators of whether rob or not rob current house
        int rob = 0, notRob = 0;
        for(int i = 0; i < nums.size(); ++i){
            int preRob = rob, preNotRob = notRob;
            rob = preNotRob + nums[i];
            notRob = max(preRob, preNotRob);
        }
        return max(rob, notRob);
    }
};
// @lc code=end

