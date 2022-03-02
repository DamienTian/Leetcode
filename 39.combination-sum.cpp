/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

// NOTE: this problem can be solved by DP
//  DP solution ref: https://www.cnblogs.com/grandyang/p/4419259.html
class Solution {
public:
    // Solution: DFS
    vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
        if(candidates.empty()){
            return {};
        }
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, result, current, 0);
        return result;
    }

private:
    void dfs(const vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index){
        if(target <= 0){
            if(target == 0){
                result.push_back(current);
            }
            return;
        }
        for(int i = index; i < candidates.size(); ++i){
            current.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], result, current, i);
            current.pop_back();
        }
    }
};

// @lc code=end

