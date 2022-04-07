/*
 * @lc app=leetcode id=644 lang=cpp
 *
 * [644] Maximum Average Subarray II
 */

// @lc code=start

#include "dummyHead.h"

class Solution
{
public:
    // Failed Solution: Presum (TLE)
    //  NOTE: use less division, computer does not like division
    //  TODO: check grandyang's solution: https://www.cnblogs.com/grandyang/p/8021421.html
    // double findMaxAverage(vector<int> &nums, int k)
    // {
    //     vector<int> preSum(nums.size() + 1);
    //     for (int i = 1; i <= nums.size(); ++i)
    //     {
    //         preSum[i] = preSum[i - 1] + nums[i - 1];
    //     }
    //     double result = (double)preSum[k] / k;
    //     for (double l = k; l <= nums.size(); ++l)
    //     {
    //         double t = preSum[l];
    //         if(t > (l + 1) * result)
    //             result = t / (l + 1);
    //         for (int i = l; i <= nums.size(); ++i)
    //         {
    //             double curr = (preSum[i] - preSum[i - l]) / l;
    //             cout << (preSum[i] - preSum[i - l])<< " l = " << l << endl;
    //             if (curr > result)
    //                 result = curr;
    //         }
    //     }
    //     return result;
    // }

    // Solution: Binary search
    //  ref: https://www.cnblogs.com/grandyang/p/8021421.html
    double findMaxAverage(vector<int> &nums, int k)
    {
        // TODO
    }

    void printVectorInt(vector<int> v)
    {
        cout << "[";
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
};

// @lc code=end