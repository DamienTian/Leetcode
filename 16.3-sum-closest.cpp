/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: two ptrs
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result;
        int gap = INT_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            bool foundTarget = false;
            while(j < k){
                int current = nums[i] + nums[j] + nums[k];
                if(abs(current - target) < gap){
                    result = current;
                    gap = abs(current - target);
                }
                if(current < target)
                    j++;
                else if(current > target)
                    k--;
                else{
                    foundTarget = true;
                    break;
                }
            }
            if(foundTarget)
                break;
        }
        return result;
    }
};
// @lc code=end

