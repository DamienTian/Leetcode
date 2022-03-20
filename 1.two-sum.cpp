/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Hash Map
    //  ref: https://www.cnblogs.com/grandyang/p/4130379.html
    //  steps:
    //  1) use a hash to stores pair (number, index in nums)
    //  2) loop the nums to find two sum pair
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     for(int i = 0; i < nums.size(); ++i){
    //         // if the two sum pair was found
    //         if(m.count(target - nums[i])){
    //             return {i, m[target - nums[i]]};
    //         }
    //         //  if not, stores in the hash map
    //         m[nums[i]] = i;
    //     }
    //     return {};
    // }

    // Solution 2: Sort + Two Pointers
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> sortNums = nums;
        sort(sortNums.begin(), sortNums.end());
        int small = 0, large = nums.size() - 1;
        while (small < large)
        {
            int twoSum = sortNums[small] + sortNums[large];
            if (twoSum == target)
                break;
            else if (twoSum > target)
                large--;
            else
                small++;
        }
        vector<int> result;
        int n1 = sortNums[small];
        int n2 = sortNums[large];
        cout << n1 << " " <<n2 <<endl;
        bool same = false;
        if (n1 == n2)
            same = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == n1)
            {
                result.push_back(i);
            }
            else if(nums[i] == n2){
                result.push_back(i);
            }
        }

        return result;
    }

private:
    // records all substract result
    unordered_map<int, int> m;
};
// @lc code=end
