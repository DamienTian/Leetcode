/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: BFS
    // int maxAreaOfIsland(vector<vector<int>> &grid)
    // {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    //     int result = 0;
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             if (grid[i][j])
    //             {
    //                 queue<vector<int>> q;
    //                 q.push({i, j});
    //                 int currResult = 0;
    //                 while (!q.empty())
    //                 {
    //                     auto curr = q.front();
    //                     q.pop();
    //                     for (const auto &d : directions)
    //                     {
    //                         int r = curr[0] + d[0];
    //                         int c = curr[1] + d[1];
    //                         if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c]){
    //                             q.push({r,c});
    //                             grid[r][c] = 0;
    //                         }
    //                     }
    //                     grid[curr[0]][curr[1]] = 0;
    //                     ++currResult;
    //                 }
    //                 result = max(result, currResult);
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: DFS
    //  ref:https://www.cnblogs.com/grandyang/p/7712724.html
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int result = 0;
        for (int y = 0; y < grid.size(); ++y)
        {
            for (int x = 0; x < grid[0].size(); ++x)
            {
                if (grid[y][x])
                {
                    int currMax = 0;
                    dfs(grid, currMax, result, x, y);
                }
            }
        }
        
        return result;
    }

    void dfs(vector<vector<int>> &grid, int& currMax, int &result, int x, int y)
    {
        if (y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || !grid[y][x])
            return;

        grid[y][x] = 0;

        if (++currMax > result)
            result = currMax;

        dfs(grid, currMax, result, x - 1, y);
        dfs(grid, currMax, result, x + 1, y);
        dfs(grid, currMax, result, x, y - 1);
        dfs(grid, currMax, result, x, y + 1);
    }
};
// @lc code=end
