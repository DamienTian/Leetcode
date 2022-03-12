/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution
{
public:
    // Solution: Two Pointer
    //  ref: https://www.cnblogs.com/grandyang/p/4822732.html
    //  note: use two ptrs, one ptr keep moving forward and swap all non-zero element with another ptr
    void moveZeroes(vector<int> &nums)
    {
        for(int i = 0, j = 0; i < nums.size(); ++i){
            if(nums[i]){
                swap(nums[i], nums[j++]);
            }
        }
    }
};
// @lc code=end
