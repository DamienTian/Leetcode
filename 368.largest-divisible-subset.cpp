/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: DP
    //  ref: https://www.cnblogs.com/grandyang/p/5625209.html
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        // sort array so we only looking for big % small
        sort(nums.begin(), nums.end());
        // stores the max len of subarray that can divide each other
        vector<int> dp(nums.size(), 0);
        // store the last divisible number's index of current index
        vector<int> previousDivisible(nums.size(), 0);
        // stores the max len subarray and the start index of the subarray
        int maxLen = 0, maxLenStartIndex = 0;
        // we only search big % small
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            for (int j = i; j < nums.size(); ++j)
            {
                if(nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    previousDivisible[i] = j;
                    if(maxLen < dp[i]){
                        maxLen = dp[i];
                        maxLenStartIndex = i;
                    }
                }
            }
        }
        vector<int> result;
        for(int i = 0; i < maxLen; ++i){
            result.push_back(nums[maxLenStartIndex]);
            maxLenStartIndex = previousDivisible[maxLenStartIndex];
        }
        return result;
    }
};
// @lc code=end
