/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current{};
        function<void(int, int)> dfs = [&result, &current, &nums, &dfs](int start, int level)
        {
            if (current.size() == level)
            {
                result.push_back(current);
                return;
            }

            for (int i = start; i < nums.size(); ++i)
            {
                // note: use the same idea of problem #40 to remove duplicated combination
                if (i != start && nums[i] == nums[i - 1])
                    continue;
                current.push_back(nums[i]);
                dfs(i + 1, level);
                current.pop_back();
            }
        };

        for (int l = 0; l <= nums.size(); ++l)
        {
            dfs(0, l);
            //current.clear();
        }

        return result;
    }
};
// @lc code=end
