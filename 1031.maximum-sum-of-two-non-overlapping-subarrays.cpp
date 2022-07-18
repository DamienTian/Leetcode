/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return dp(nums, firstLen, secondLen);
    }

private:
    // Solution: dp
    //  ref: https://www.cnblogs.com/grandyang/p/14403710.html
    int dp(vector<int>& nums, int firstLen, int secondLen){
        for(int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        // init result as first (firstLen + secondLen) subarrays sum
        int result = nums[firstLen + secondLen - 1];
        // init first and second 
        int firstMax = nums[firstLen - 1];
        int secondMax = nums[secondLen - 1];
        for(int i = firstLen + secondLen; i < nums.size(); ++i){
            // find each max
            firstMax = max(firstMax, nums[i - secondLen] - nums[i - firstLen - secondLen]);
            secondMax = max(secondMax, nums[i - firstLen] - nums[i - firstLen - secondLen]);
            // find max result
            //  note: take a look at index to see how it deals with overlap cases
            result = max(result, 
                    max(firstMax + nums[i] - nums[i - secondLen], 
                        secondMax + nums[i] - nums[i - firstLen]));
        }
        return result;
    }
};
// @lc code=end

