/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start

// IDEA: Binary Search
// NOTE(IMPORTANT):
//  ref: Grandyang has listed many cases of using binary search
//        https://www.cnblogs.com/grandyang/p/6854825.html

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        
        while(left < right){
            //int mid = (right + left) / 2;  // wrong 
            int mid = left + (right - left) / 2;    // right
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

