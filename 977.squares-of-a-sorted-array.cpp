/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
public:
    // Solution: Two Pointer
    //  ref: https://www.cnblogs.com/grandyang/p/14172463.html 
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> result(n);

        // Put the largest squared at the end of the result, use for loop to visit every elements in the nums
        for(int k = n - 1; k >= 0; --k){
            // Compare abs value
            if(abs(nums[i]) < abs(nums[j])){
                result[k] = nums[j] * nums[j];
                --j;
            }
            else{
                result[k] = nums[i] * nums[i];
                ++i;
            }
        }
        return result;
    }
};
// @lc code=end

