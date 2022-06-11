/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    int trap(vector<int>& height) {
        // return dp(height);
        return twoPtrs(height);
    }

private:
    // Solution 1: dp
    //  ref: https://www.cnblogs.com/grandyang/p/4402392.html
    int dp(vector<int>& height){
        int result= 0;
        int edgeMax = 0;
        vector<int> dp(height.size(), 0);
        // first, from lef to right, find the max on left for each col
        for(int i = 0; i < height.size(); ++i){
            dp[i] = edgeMax;
            // cout << "dp[" << i << "] = " << dp[i] << endl;
            edgeMax = max(edgeMax, height[i]);
        }
        edgeMax = 0;
        // then, from right to left, find the max of right, and update dp
        for(int i = height.size() - 1; i >= 0; --i){
            dp[i] = min(dp[i], edgeMax);
            // cout << "dp[" << i << "] = " << dp[i] << endl;
            edgeMax = max(edgeMax, height[i]);
            if(dp[i] > height[i])
                result += dp[i] - height[i];
        }
        return result;
    }

    // Solution 2: two ptrs
    //  ref: https://www.cnblogs.com/grandyang/p/4402392.html
    int twoPtrs(vector<int>& height){
        int result = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            int minSide = min(height[left], height[right]);
            if(minSide == height[left]){
                ++left;
                while(left < right && height[left] < minSide)
                    result += minSide - height[left++];
            }
            else{
                --right;
                while(left < right && height[right] < minSide)
                    result += minSide - height[right--];
            }
        }
        return result;
    }
};
// @lc code=end

