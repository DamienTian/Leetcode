/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
// #include "dummyHead.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        unordered_set<int> visited;
        dfs(nums, result, current, visited);
        return result;
    }

private:
    void dfs(const vector<int>& nums, vector<vector<int>>& result, vector<int>& current, unordered_set<int>& visited){
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited.count(i))
                continue;
            current.push_back(nums[i]);
            visited.insert(i);
            dfs(nums, result, current, visited);
            visited.erase(i);
            current.pop_back();
        }
    }
};
// @lc code=end

