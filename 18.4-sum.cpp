/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: two pointers
//  ref: https://www.cnblogs.com/grandyang/p/4515925.html
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])    // remove duplicated
                continue;
            for (int j = i + 1; j < n - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])    // remove duplicated
                    continue;
                int left = j + 1;
                int right = n - 1;
                while(left < right){
                    // prevent overflow
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) // remove duplicated
                            left++;
                        while(left < right && nums[right] == nums[right - 1])   // remove duplicated
                            right--;
                        left++;
                        right--;
                    }
                    else if(sum < target)
                        ++left;
                    else    
                        --right;
                }
            }
        }
        return result;
    }
};
// @lc code=end
