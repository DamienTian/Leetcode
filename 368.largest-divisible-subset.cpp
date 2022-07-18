/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return dp(nums);
    }

private:
    // Solution: dp
    //  ref: https://www.cnblogs.com/grandyang/p/5625209.html
    vector<int> dp(vector<int>& nums) {
        // sort nums so it only find the large % small (small % large != 0)
        sort(nums.begin(), nums.end());

        // dp a pair of int:
        //  first: longest len at this index
        //  second: previous divisible index (from larger element to smaller to build result)
        vector<pair<int, int>> dp(nums.size());
        
        // current max size
        int maxSize = 0;
        // current max size start index
        int maxSizeStart = 0;

        // loop from largest element to smaller
        for(int i = nums.size() - 1; i >= 0; --i){
            for(int j = i; j < nums.size(); ++j){
                if(nums[j] % nums[i] == 0 && dp[i].first < dp[j].first + 1) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                    if(maxSize < dp[i].first){
                        maxSize = dp[i].first;
                        maxSizeStart = i;
                    }
                }
            }
        }

        // build result
        vector<int> result;
        for(int i = 0; i < maxSize; ++i){
            result.push_back(nums[maxSizeStart]);
            maxSizeStart = dp[maxSizeStart].second;
        }

        return result;
    }
};
// @lc code=end

