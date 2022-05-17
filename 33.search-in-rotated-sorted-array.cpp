/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

// #include "dummyHead.h"
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            // WRONG: need to find which side is in ordered, and then compare with target 
            /* 
            //else if(nums[mid] < target){
            //     if(nums[mid] < nums[right-1])
            //         left = mid + 1;
            //     else    
            //         right = mid;
            // }
            // else{
            //     if(nums[mid] < nums[right-1])
            //         right = mid;
            //     else    
            //         left = mid + 1;
            //}
            */
            // RIGHT
            //  ref: https://www.cnblogs.com/grandyang/p/4325648.html
            if (nums[mid] < nums[right]) {  // left side in ordered
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } 
            else {  // right side in ordered
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

