/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// Review 1

// #include "dummyHead.h"

// @lc code=start
class Solution {
public:
    // Solution 1: DP
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i){
            lowestPrice = min(lowestPrice, prices[i]);
            profit = max(profit, prices[i] - lowestPrice);
        }
        return profit;
    }
};
// @lc code=end

