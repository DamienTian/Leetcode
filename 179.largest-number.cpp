/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
// #include "dummyHead.h"

class Solution
{
public:
    // Solution: quick sort
    string largestNumber(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        // printVectorInt(nums);
        string result = "";
        for (int n : nums)
            result += to_string(n);
        return result[0] == '0' ? "0" : result;
    }

private:
    // ref of quick sort: https://www.geeksforgeeks.org/quick-sort/
    void quickSort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pi = partition(nums, low, high);

            quickSort(nums, low, pi - 1);
            quickSort(nums, pi + 1, high);
        }
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int index = low - 1;

        for (int i = low; i < high; ++i)
        {
            if (compare(nums[i], pivot))
            {
                index++;
                swap(nums[index], nums[i]);
            }
        }

        swap(nums[index + 1], nums[high]);
        return index + 1;
    }

    // ref compare: https://www.cnblogs.com/grandyang/p/4225047.html
    bool compare(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
};

// @lc code=end
