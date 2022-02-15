/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: DFS
    //  ref: https://zxi.mytechroad.com/blog/searching/leetcode-40-combination-sum-ii/
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, result, current);
        return result;
    }

    void dfs(vector<int> &candidates, int target, int startIndex, vector<vector<int>> &result, vector<int> &current)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = startIndex; i < candidates.size(); ++i)
        {
            int n = candidates[i];
            if (n > target)
                return;
            // note: this erase all duplicated combinations
            if (i != startIndex && candidates[i] == candidates[i - 1])
                continue;
            current.push_back(n);
            dfs(candidates, target - n, i + 1, result, current);
            current.pop_back();
        }
    }
};
// @lc code=end
