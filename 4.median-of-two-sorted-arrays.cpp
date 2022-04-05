/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Binary Search
    //  ref: https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-4-median-of-two-sorted-arrays/
    //  todo: very hard to understand, need to prove how to determine # element use in each vector
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        // midian index
        int m = (nums1.size() + nums2.size() + 1) / 2;

        // binary search boundary
        int l = 0, r = nums1.size();

        while (l < r)
        {
            // midian index for nums1
            const int m1 = l + (r - l) / 2;
            // index for nums2 to build m with median in nums1
            const int m2 = m - m1;

            // ? why this is the case that nums1 need more element?
            if (nums1[m1] < nums2[m2 - 1])
                l = m1 + 1;
            else
                r = m1;
        }

        // found midian indices on nums1 and nums2
        const int m1 = l, m2 = m - l;

        // left median
        const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1], m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

        // if total len is odd, return left median
        if ((nums1.size() + nums2.size()) % 2 == 1)
            return c1;

        // right median
        const int c2 = min(m1 >= nums1.size() ? INT_MAX : nums1[m1], m2 >= nums2.size() ? INT_MAX : nums2[m2]);

        return (c1 + c2) * 0.5;
    }
};
// @lc code=end
