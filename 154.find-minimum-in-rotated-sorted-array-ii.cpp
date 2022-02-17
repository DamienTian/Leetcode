/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    // Solution 1: Binary search
    //  note: follow the similar pattern of #33, #81
    // int findMin(vector<int>& nums) {
    //     int left = 0;
    //     int right = nums.size() - 1;
    //     while(left < right){
    //         int mid = left + (right - left) / 2;
    //         if(nums[mid] < nums[right]){
    //             right = mid;
    //         }
    //         else if(nums[mid] > nums[right]){
    //             left = mid + 1;
    //         }
    //         else
    //             --right;
    //     }
    //     return nums[right];
    // }

    // Solution 2: Divide and conquer, Binary Search 
    //  note: same solution as #153
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

private:
    int findMin(const vector<int>& nums, int begin, int end){
        if(begin == end || isSorted(nums, begin, end))
            return nums[begin];
        int mid = begin + (end - begin) / 2;
        return min(findMin(nums, begin, mid), findMin(nums, mid + 1, end));
    }

    inline bool isSorted(const vector<int>& nums, int begin, int end){
        return nums[begin] < nums[end];
    }
};
// @lc code=end

