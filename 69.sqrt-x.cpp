/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    // Solution 1: binary search
    //  note: take a look at grandyang's version (https://www.cnblogs.com/grandyang/p/4346413.html) too
    int mySqrt(int x) {
        long left = 1, right = x;
        while(left < right){
            long mid = left + (right - left) / 2;
            if(mid * mid >= x)
                right = mid;
            else
                left = mid + 1;
        }
        return right * right > x ? right - 1 : right;
    }
};
// @lc code=end

