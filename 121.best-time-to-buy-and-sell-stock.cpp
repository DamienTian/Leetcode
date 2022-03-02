/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: DP
    //  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-121-best-time-to-buy-and-sell-stock/
    // int maxProfit(vector<int>& prices) {
    //     int lowestPrice = prices[0];
    //     int result = 0;
    //     for(int i = 1; i < prices.size(); ++i){
    //         lowestPrice = min(lowestPrice, prices[i]);
    //         result = max(result, prices[i] - lowestPrice);
    //     }
    //     return result;
    // }

    // Solution 2: DP + Maxsubarray
    //  ref: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-121-best-time-to-buy-and-sell-stock/
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        // Daliy Gain
        vector<int> gains(prices.size() - 1, 0);
        for (int i = 1; i < prices.size(); ++i)
        {
            gains[i - 1] = prices[i] - prices[i - 1];
        }
        return max(0, maxSubArray(gains));
    }

    // note: use #53 solution as the helper to find result
    int maxSubArray(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(dp[i], result);
        }
        return result;
    }
};
// @lc code=end
