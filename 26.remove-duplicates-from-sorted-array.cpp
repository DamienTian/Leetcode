/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
//#include "dummyHead.h"

class Solution {
public:
    // Solution 1: Two Pointers (delete element)
    // int removeDuplicates(vector<int>& nums) {
    //     int i = 0 , j = i;
    //     while(i < nums.size() && j < nums.size()){
    //         j++;
    //         while(j < nums.size() && nums[i] == nums[j]){
    //             nums.erase(nums.begin() + j);
    //         }
    //         i++;
    //     }
    //     return nums.size();
    // }

    // Solution 2: Two Pointers (doesn't delete element)
    //  ref: https://turingplanet.org/2020/05/20/array-two-pointers%E5%A5%97%E8%B7%AF%E3%80%90leetcode%E5%88%B7%E9%A2%98%E5%A5%97%E8%B7%AF%E6%95%99%E7%A8%8B2%E3%80%91/
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            // if not duplicate, keep it, otherwise skip it
            if(i == 0 || nums[j] != nums[i - 1]){
                nums[i++] = nums[j++];
                // nums[i] = nums[j];
                // ++i;
                // ++j;
            }
            else{
                ++j;
            }
        }

        return i;
    }

};
// @lc code=end

