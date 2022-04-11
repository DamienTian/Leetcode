/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Two Pointers
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i)
        {
            // nums[i] > 0 optimization from Grandyang
            //  ref: https://www.cnblogs.com/grandyang/p/4481576.html
            if(nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = nums.size() - 1;
            int target = -nums[i];
            while (j < k)
            {
                if(nums[j] + nums[k] == target){
                    // erase duplicated answer
                    if((j == i + 1 && k == nums.size() - 1) || (j > i + 1 && nums[j] != nums[j - 1]) || (k < nums.size() - 1 && nums[k] != nums[k + 1]))
                        result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] > target)
                    k--;
                else    
                    j++;
            }
        }
        return result;
    }
};
// @lc code=end
