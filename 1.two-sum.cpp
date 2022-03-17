/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
//#include "dummyHead.h"

// Solution: Hash Map
//  ref: https://www.cnblogs.com/grandyang/p/4130379.html
//  steps: 
//  1) use a hash to stores pair (number, index in nums)
//  2) loop the nums to find two sum pair
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            // if the two sum pair was found
            if(m.count(target - nums[i])){
                return {i, m[target - nums[i]]};
            }
            //  if not, stores in the hash map
            m[nums[i]] = i;
        }
        return {};
    }

private:
    // records all substract result
    unordered_map<int, int> m;
};
// @lc code=end

