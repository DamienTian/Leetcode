/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int levels = nums.size();
        vector<vector<int>> result;
        vector<int> current{};

        function<void(int, int)> dfs = [levels, &result, &current, &nums, &dfs](int start, int level)
        {
            if (current.size() == level)
            {
                result.push_back(current);
                return;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                current.push_back(nums[i]);
                dfs(i + 1, level);
                current.pop_back();
            }
        };

        for (int l = 0; l <= levels; ++l)
        {
            dfs(0, l);
            //current.clear();
        }

        return result;
    }
};
// @lc code=end
