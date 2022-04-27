/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Falied Solution: TLE
    // vector<double> medianSlidingWindow(vector<int> &nums, int k)
    // {
    //     vector<double> result;
    //     deque<long> current(nums.begin(), nums.begin() + k);
    //     for (int i = 0; i <= nums.size() - k; ++i)
    //     {
    //         vector<long> sortCurrent(current.begin(), current.end());
    //         sort(sortCurrent.begin(), sortCurrent.end());
    //         double median = 0;
    //         if (k % 2 == 0)
    //             median = (sortCurrent[k / 2] + sortCurrent[k / 2 - 1]) / 2.0;
    //         else
    //             median = sortCurrent[k / 2];
    //         result.push_back(median);
    //         if (i == nums.size() - k)
    //             break;
    //         current.pop_front();
    //         current.push_back(nums[i + k]);
    //     }
    //     return result;
    // }

    // Solution: multiset + STL
    //  ref: https://www.cnblogs.com/grandyang/p/6620334.html
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> result;
        // multiset keep elements in ordered
        multiset<double> ms(nums.begin(), nums.begin() + k);
        // set median
        auto median = next(ms.begin(), k / 2);
        for(int i = k; ; ++i){
            result.push_back((*median + *prev(median, 1 - k % 2)) / 2);
            if (i == nums.size())
                return result;
            // note: think about this part and check ref to see why 
            ms.insert(nums[i]);
            if(nums[i] < *median)
                --median;
            if(nums[i - k] <= *median)
                ++median;
            ms.erase(ms.lower_bound(nums[i - k]));
        }
    }
};
// @lc code=end
