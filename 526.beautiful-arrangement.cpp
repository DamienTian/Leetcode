/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: permutation by swap
    //  ref: https://www.cnblogs.com/grandyang/p/6533276.html
    // int countArrangement(int n)
    // {
    //     vector<int> nums;
    //     for (int i = 1; i <= n; ++i)
    //         nums.push_back(i);
    //     return permutationSwap(nums, n);
    // }

    // Solution 2: permutation dfs (no vector<int> of numbers created)
    int countArrangement(int n)
    {
        int result = 0;
        vector<bool> visited(n, false);
        permutationDFS(n, 1, result, visited);
        return result;
    }

private:
    int permutationSwap(vector<int> &nums, int pos)
    {
        if (pos <= 0){
            return 1;
        }
        int result = 0;
        for (int i = 0; i < pos; ++i)
        {
            if (isBeautiful(nums[i], pos))
            {
                swap(nums[i], nums[pos - 1]);
                result += permutationSwap(nums, pos - 1);
                swap(nums[i], nums[pos - 1]);
            }
        }
        return result;
    }

    void permutationDFS(int n, int index, int& result, vector<bool>& visited){
        if(index > n){
            result++;
            return;
        }
        for(int i = 0; i < n; ++i){
            if(!visited[i] && isBeautiful(i+1, index)){
                visited[i] = true;
                cout << "i: " << i+1 << " index: " << index << " add" << endl;
                permutationDFS(n, index + 1, result, visited);
                cout << "i: " << i+1 << " index: " << index << " pop" << endl;
                visited[i] = false;
            }
        }
    }

    bool isBeautiful(int n, int index)
    {
        return n % (index) == 0 || (index) % n == 0;
    }
};
// @lc code=end
