/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: Slide window (think as dp)
    //  ref: https://zxi.mytechroad.com/blog/algorithms/array/leetcode-1423-maximum-points-you-can-obtain-from-cards/
    int maxScore(vector<int>& cardPoints, int k) {
        const int n = cardPoints.size();

        // Add up first k elements 
        int current = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        int result = current;

        // then add up end of the vector to find max
        for(int i = 0; i < k; ++i){
            current = current - cardPoints[k - i - 1] + cardPoints[n - i - 1];
            result = max(current, result);
        }
        return result;
    }
};
// @lc code=end

