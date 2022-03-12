/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    // Solution 1: Two Pointers
    //  ref: https://www.cnblogs.com/grandyang/p/4402392.html
    //  TODO: baraly understand, need to review 
    //  note: there is a stack solution in the ref
    int trap(vector<int>& height) {
        int res = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            // mn is the lower side (left or right)
            int mn = min(height[l], height[r]);
            if (mn == height[l]) {
                // searching left side
                ++l;
                while (l < r && height[l] < mn) {
                    res += mn - height[l++];
                }
            } else {
                --r;
                while (l < r && height[r] < mn) {
                    res += mn - height[r--];
                }
            }
        }
        return res;
    }
};
// @lc code=end

