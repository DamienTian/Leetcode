/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.

// #include "dummyHead.h"
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};
// @lc code=end

