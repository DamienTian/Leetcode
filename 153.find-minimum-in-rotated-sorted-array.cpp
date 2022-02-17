/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    // Solution 1: Divide and conquer, Binary Search
    //  ref: https://www.youtube.com/watch?v=P4r7mF1Jd50&t=3s
    // int findMin(vector<int>& nums) {
    //     return findMin(nums, 0, nums.size() - 1);
    // }

    // Solution 2: 
    //  ref: https://www.cnblogs.com/grandyang/p/4032934.html
    //  note: follow the similar pattern of #33, #81
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return nums[right];
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

