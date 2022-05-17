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
    // Solution 1: Binary Search w/o lambda
    //  note: key for this problem is how to find peak
    //  ref: https://zxi.mytechroad.com/blog/algorithms/binary-search/1095-find-in-mountain-array/
    // int findInMountainArray(int target, MountainArray &mountainArr)
    // {
    //     // find peak
    //     int left = 0, right = mountainArr.length() - 1;
    //     while (left < right)
    //     {
    //         int mid = left + (right - left) / 2;
    //         if (mountainArr.get(mid) < mountainArr.get(mid + 1))
    //             left = mid + 1;
    //         else
    //             right = mid;
    //     }
    //     int peak = left;
    //     if (mountainArr.get(peak) == target)
    //         return peak;
    //     // do binary search on bothside
    //     int leftIndex = binarySearch(mountainArr, 0, peak - 1, target, false);
    //     if (leftIndex != -1)
    //         return leftIndex;
    //     return binarySearch(mountainArr, peak + 1, mountainArr.length() - 1, target, true);
    // }

    // Solution 2: Binary Search with lambda
    //  ref: https://zxi.mytechroad.com/blog/algorithms/binary-search/1095-find-in-mountain-array/
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        const int n = mountainArr.length();
        // binary search
        auto binarySearch = [&](int l, int r, function<bool(int)> condition)
        {
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (!condition(m))
                    l = m + 1;
                else
                    r = m;
            }
            return l;
        };
        // peak
        int peak = binarySearch(0, n - 1, [&](int i) -> bool
                                { return mountainArr.get(i) > mountainArr.get(i + 1); });
        // find left index
        int left = binarySearch(0, peak, [&](int i) -> bool
                                { return mountainArr.get(i) >= target; });
        if (mountainArr.get(left) == target)
            return left;
        // find right index
        int right = binarySearch(peak, n - 1, [&](int i) -> bool
                                 { return mountainArr.get(i) <= target; });
        if (mountainArr.get(right) == target)
            return right;
        return -1;
    }

private:
    // int binarySearch(MountainArray &mountainArr, int leftBound, int rightBound, int target, bool reversed)
    // {
    //     int left = leftBound, right = rightBound;
    //     while (left <= right)
    //     {
    //         int mid = left + (right - left) / 2;
    //         if (mountainArr.get(mid) == target)
    //             return mid;
    //         if (!reversed)
    //         {
    //             if (mountainArr.get(mid) < target)
    //                 left = mid + 1;
    //             else
    //                 right = mid - 1;
    //         }
    //         else
    //         {
    //             if (mountainArr.get(mid) > target)
    //                 left = mid + 1;
    //             else
    //                 right = mid - 1;
    //         }
    //     }
    //     return -1;
    // }
};
// @lc code=end
