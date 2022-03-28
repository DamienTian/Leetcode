/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution: DFS combination
    //  ref: https://www.cnblogs.com/grandyang/p/7733098.html
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // prune prepare
        int target = accumulate(nums.begin(), nums.end(), 0);
        if(target % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return dfs(nums, k, target / k, 0, 0, visited);
    }
private:
    bool dfs(const vector<int>& nums, int k, int target, int startIndex, int currentSum, vector<bool>& visited){
        if(k == 1)  return true;
        if(currentSum > target || startIndex == nums.size()) return false; // prune
        if(currentSum == target) return dfs(nums, k - 1, target, 0, 0, visited);
        for(int i = startIndex; i < nums.size(); ++i){
            if(visited[i])  continue;
            visited[i] = true;
            if(dfs(nums, k, target, i + 1, currentSum + nums[i], visited))
                return true;
            visited[i] = false;
        }
        return false;
    }
};
// @lc code=end

