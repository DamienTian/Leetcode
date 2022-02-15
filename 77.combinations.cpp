/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(n, k, result, current, 1);
        return result;
    }
    
    void dfs(int n, int k, vector<vector<int>> &result, vector<int> &current, int start){
        if(k == 0){
            result.push_back(current);
            return;
        }

        for(int i = start; i <= n; ++i){
            current.push_back(i);
            dfs(n, k-1, result, current, i+1);
            current.pop_back();
        }
    }
};
// @lc code=end

