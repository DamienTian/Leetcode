/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Failed Solution: DP (Time Limit Exceeded on last test case)
    // bool checkSubarraySum(vector<int>& nums, int k) {
    //     for(int i = 1; i < nums.size(); ++i)
    //         nums[i] += nums[i - 1];

    //     for(int i = 0; i < nums.size(); ++i){
    //         if(i >= 1 && nums[i] % k == 0)
    //             return true;
    //         for(int j = i - 2; j >= 0; --j){
    //             if((nums[i] - nums[j]) % k == 0)
    //                 return true;
    //         }
    //     }

    //     return false;
    // }

    // Solution: hashset
    //  ref: https://www.cnblogs.com/grandyang/p/6504158.html
    //  note: chech the proof to understand
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            int t = (sum % k);
            if (st.count(t)) return true;
            st.insert(pre);
            pre = t;
        }
        return false;
    }
};
// @lc code=end
