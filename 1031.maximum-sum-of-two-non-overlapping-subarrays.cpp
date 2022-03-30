/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: DP
    //  ref: https://www.youtube.com/watch?v=XTGEbhZmqCY
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen)
    {
        if(nums.size() < firstLen + secondLen)
            return 0;
        for(int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];

        int result = nums[firstLen + secondLen - 1];
        int firstMax = nums[firstLen - 1];
        int secondMax = nums[secondLen - 1];
        for(int i = firstLen + secondLen; i < nums.size(); ++i){
            firstMax = max(firstMax, nums[i - secondLen] - nums[i - firstLen - secondLen]);
            secondMax = max(secondMax, nums[i - firstLen] - nums[i - firstLen - secondLen]);
            result = max(result, max(firstMax + nums[i] - nums[i - secondLen], 
                                    secondMax + nums[i] - nums[i - firstLen]));
        }
        return result;
    }
};
// @lc code=end
