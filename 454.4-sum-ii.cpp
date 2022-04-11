/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Hash
    //  ref: https://www.cnblogs.com/grandyang/p/6073317.html
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int result = 0;
        unordered_map<int, int> m;
        int n = nums1.size();
        for(int i1 = 0; i1 < n; i1++){
            for(int i2 = 0; i2 < n; i2++){
                m[nums1[i1] + nums2[i2]]++;
            }
        }

        for(int i3 = 0; i3 < n; i3++){
            for(int i4 = 0; i4 < n; i4++){
                int key = -1 * (nums3[i3] + nums4[i4]);
                result += m[key];
            }
        }

        return result;
    }
};
// @lc code=end
