/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
//#include "../dummyHead.h"

// Solution: Two pointers? array (permutation)?
//  ref: https://www.youtube.com/watch?v=CjizdDIAy_4
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        int j = n - 1;
        while(i >= 0 && nums[i+1] <= nums[i]){
            --i;
        } 
        if (i >= 0) {
            while(nums[j] <= nums[i]){
                --j;
            } 
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


// @lc code=end

