/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: DFS
    //  ref: https://www.cnblogs.com/grandyang/p/4359825.html (solution 1)
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        unordered_set<int> visited;
        dfs(nums, result, current, visited);
        return result;
    }

private:
    void dfs(const vector<int> &nums, vector<vector<int>> &result, vector<int> &current, unordered_set<int> &visited)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited.count(i))
                continue;
            // remove duplicate
            //  note:                       when this happened, it means the previous same element have not been used OR has be poped from previous ans,
            //  note continue ...)      so when the previous same node has not been used OR has been used to make ans, this one cannot be used again.
            if(i > 0 && nums[i] == nums[i-1] && !visited.count(i-1))
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
