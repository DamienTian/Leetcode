/*
 * @lc app=leetcode id=1300 lang=cpp
 *
 * [1300] Sum of Mutated Array Closest to Target
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: binary search
    //  ref: https://its401.com/article/qq_39856931/106765328
    int findBestValue(vector<int> &arr, int target)
    {
        sort(arr.begin(), arr.end());
        vector<int> prefixSum(arr.size() + 1);
        for (int i = 1; i < arr.size(); ++i)
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];

        // printVectorInt(prefixSum);

        int maxElement = arr[arr.size() - 1];
        int diff = target; // difference beterrn sum and target
        int result = 0;
        for (int i = 1; i <= maxElement; ++i)
        {
            int lowerBoundIndex = searchLowerBound(arr, i, 0, arr.size());
            // auto lowerBoundIndex = lower_bound(arr.begin(), arr.end(), i);
            int currentSum = prefixSum[lowerBoundIndex] + i * (arr.size() - lowerBoundIndex);
            // int currentSum = prefixSum[lowerBoundIndex - arr.begin()] + (arr.end() - lowerBoundIndex) * i;
            if (abs(currentSum - target) < diff)
            {
                result = i;
                diff = abs(currentSum - target);
            }
        }
        return result;
    }

private:
    int searchLowerBound(const vector<int> &arr, int val, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            if (val > arr[mid])
                return searchLowerBound(arr, val, mid + 1, right);
            else
                return searchLowerBound(arr, val, left, mid);
        }
        return right;
    }

    // print vector<int>
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
