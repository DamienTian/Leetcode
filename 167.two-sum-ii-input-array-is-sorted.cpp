/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: Two Pointers
    // vector<int> twoSum(vector<int> &numbers, int target)
    // {
    //     int i = 0, j = numbers.size() - 1;
    //     while (i < j)
    //     {
    //         // while (numbers[j] >= target)
    //         // {
    //         //     --j;
    //         // }
    //         int sum = numbers[i] + numbers[j];
    //         if (sum != target)
    //         {
    //             (sum > target) ? --j : ++i;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     return {i+1, j+1};
    // }

    // Solution 2: Binary Search
    //  ref: https://www.cnblogs.com/grandyang/p/5185815.html
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); ++i)
        {
            int t = target - numbers[i];
            int left = i;
            int right = numbers.size();
            while (left < right)
            {
                // Find the new target mid
                int mid = left + (right - left) / 2;
                if (numbers[mid] == t)
                {
                    return {i + 1, mid + 1};
                }
                else if (numbers[mid]< t)  
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        return {};
    }
};
// @lc code=end
