/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
// class MountainArray
// {
// public:
//     int get(int index);
//     int length();
// };
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Binary Search
    //  ref: https://www.cnblogs.com/grandyang/p/14616376.html
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        int left = 0, right = len - 1;
        int peak = -1;
        // first find peak
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1))
                left = mid + 1;
            else
                right = mid;
        }
        peak = left;
        if(mountainArr.get(peak) == target)
            return peak;

        // then search peak left and peak right
        int idx1 = binarySearch(target, mountainArr, 0, peak - 1, true);
        int idx2 = binarySearch(target, mountainArr, peak + 1, len - 1, false);
        return idx1 == -1 ? idx2 : idx1; 
    }

    int binarySearch(int target, MountainArray &mountainArr, int left, int right, bool isAscending){
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target){
                if(isAscending)
                    left = mid + 1;
                else
                    right = mid;
            }
            else{
                if(!isAscending)
                    left = mid + 1;
                else
                    right = mid;
            }
        }

        return mountainArr.get(right) == target ? right : -1;
    }
};
// @lc code=end
