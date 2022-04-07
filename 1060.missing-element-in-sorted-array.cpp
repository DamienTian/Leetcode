/*
 * @lc app=leetcode id=1060 lang=cpp
 *
 * [1060] Missing Element in Sorted Array
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Failed Solution: Binary Search (TLE)
    // int missingElement(vector<int>& nums, int k) {
    //     int currTarget = nums[0];
    //     while(k > 0){
    //         currTarget++;
    //         // search is a binary search
    //         if(search(nums, currTarget) == -1)
    //             k--;
    //     }
    //     return currTarget;
    // }

    // Solution: Binary Search
    //  ref: https://leetcode.com/problems/missing-element-in-sorted-array/solution/
    int missingElement(vector<int>& nums, int k) {
        if(k > missingCount(nums, nums.size() - 1))
            return nums[nums.size() - 1] + k - missingCount(nums, nums.size() - 1);

        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(missingCount(nums, m) < k)
                l = m + 1;
            else
                r = m;
        }

        // find the index that:
        // 1) kth missing number is greater than nums[index - 1] 
        // 2) and less than nums[index]
        return nums[r - 1] + k - missingCount(nums, r - 1);
    }

private:
    // helper function to find how many numbers are missing until nums[i]
    int missingCount(const vector<int>& nums, int i){
        return nums[i] - nums[0] - i;
    }

    // NOTE:    don't do this value equal search, it will be very costy,
    //note...)  change it to find # of missing element
    int search(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int m = l + (r - l) / 2;
            if(target == nums[m])
                return m;
            else if(target > nums[m])
                l = m + 1;
            else
                r = m;
        }
        return -1;
    }
};

// @lc code=end