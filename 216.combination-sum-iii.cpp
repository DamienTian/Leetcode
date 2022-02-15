/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> current;
        function<void(int, int)> dfs = [n, k, &result, &current, &dfs](int start, int target)
        {
            if (current.size() == k && target == 0)
            {
                result.push_back(current);
                return;
            }

            for (int i = start; i < 10; ++i)
            {
                if (i > target)
                    return;
                current.push_back(i);
                dfs(i + 1, target - i);
                current.pop_back();
            }
        };

        dfs(1, n);
        return result;
    }
};
// @lc code=end
