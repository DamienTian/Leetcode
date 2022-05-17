/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: Binary Search
    // Note: all you need is two binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                // do another round of binary search to find:
                //  - last element which is not greater than the target
                //  - first element which is not smaller than the target
                int leftBound, rightBound;
                //  find left bound of range
                left = 0, right = nums.size();
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(nums[mid] < target) left = mid + 1;
                    else    right = mid;
                }
                leftBound = right;
                //  find right bound of range
                left = 0, right = nums.size();
                while(left < right){
                    int mid = left + (right - left) / 2;
                    if(nums[mid] <= target) left = mid + 1;
                    else    right = mid;
                }
                rightBound = right;
                return {leftBound, rightBound-1};
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return {-1,-1};
    }
};
// @lc code=end

