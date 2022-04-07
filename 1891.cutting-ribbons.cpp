/*
 * @lc app=leetcode id=1891 lang=cpp
 *
 * [1891] Cutting Ribbons
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: Binary Search
//  ref: https://blog.csdn.net/qq_21201267/article/details/119708324
class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int l = 1, r = 1e5;
        int result = 0;
        while(l <= r){
            // the target length, find by binary search
            int len = (l + r) >> 1;
            if(canCut(ribbons, k, len)){
                l = len + 1;
                result = len;
            }
            else{
                r = len - 1;
            }
        }

        return result;
        
    }

private:
    // find the ribbons can be cut to # of k in len
    bool canCut(vector<int>& ribbons, int k, int len){
        int count = 0;
        for(auto r : ribbons){
            count += r / len;
            if(count >= k)
                return true;
        }
        return false;
    }
};

// @lc code=end