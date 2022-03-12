/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // Solution: two pointers
    //  ref: https://www.cnblogs.com/grandyang/p/4329295.html
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int n : nums){
            if(i < 2 || n > nums[i - 2]){
                nums[i++] = n;
            }
        }
        return i;
    }
};
// @lc code=end

