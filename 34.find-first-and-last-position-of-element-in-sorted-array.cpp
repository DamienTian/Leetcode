/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start, end;
        
        // Find start (find the first element that is less than or equal to target)
        int left = 0;
        int right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        // Note: notice when left bound is out-of-boundary case
        start = (left != nums.size() && nums[right] == target) ? right : -1;

        // If couldn't find start, then there has no end, return.
        if(start == -1)
            return {-1, -1};

        // Find end (find the first element that is greater than target)
        left = 0;
        right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        // Note: notice when right bound is out-of-boundary case
        end = (!(right <= 0) && nums[right - 1] == target) ? right - 1 : -1;

        return {start, end};
    }
};
// @lc code=end

