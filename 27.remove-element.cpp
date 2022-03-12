/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    // Solution 1
    //  ref: https://zxi.mytechroad.com/blog/algorithms/array/leetcode-27-remove-element/
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int num : nums){
            if(num != val)
                nums[i++] = num;
        }
        return i;
    }
};
// @lc code=end

