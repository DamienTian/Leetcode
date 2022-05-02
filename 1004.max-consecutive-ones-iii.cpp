/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: sliding window
    //  note: follow the method for solving #424
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int result = 0;
        vector<int> count(2, 0);
        for(int i = 0; i < nums.size(); ++i){
            count[nums[i]]++;
            while(i - left + 1 - count[1] > k){
                --count[nums[left++]];
            }
            result = max(result, i - left + 1);
        }
        return result;
    }
};
// @lc code=end

