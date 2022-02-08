/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

class Solution {
    // Failed Solution 1: O(nlogn)
    // Time Limit Exceeded
public:
    // int maxArea(vector<int>& height) {
    //     if(height.empty()){
    //         return 0;
    //     }

    //     int result = 0;
    //     for(size_t i = 0; i < height.size(); ++i){
    //         for(int j = i + 1; j < height.size(); ++j){
    //             int area = min(height[i], height[j]) * (j - i);
    //             result = (area > result) ? area : result;
    //         }
    //     }

    //     return result;
    // }

    // Solution 1: Two Pointer
    //  ref: https://www.cnblogs.com/grandyang/p/4455109.html
    int maxArea(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int result = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            result = max(result, min(height[i], height[j]) * (j - i));
            (height[i] < height[j]) ? ++i : --j;
        }
        
        return result;
    }
};
// @lc code=end

