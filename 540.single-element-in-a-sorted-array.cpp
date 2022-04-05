/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: binary search
    //  ref: https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-540-single-element-in-a-sorted-array/
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            int n = m ^ 1;  // int n = m % 2 == 0 ? m + 1 : m - 1;
            // note: if single element appears, nums[odd] != nums[odd - 1], nums[even] != nums[even + 1]
            //  note ...    (think about indices and elements in vector)
            if(nums[m] == nums[n])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};
// @lc code=end

