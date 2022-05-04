/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

// #include "dummyHead.h"

// Review: 1

class Solution
{
public:
    // Solution 1: BFS
    // int numIslands(vector<vector<char>> &grid)
    // {
    //     if (grid.empty() || grid[0].empty())
    //         return 0;
    //     int m = grid.size(), n = grid[0].size();
    //     vector<vector<int>> visited(m, vector<int>(n, 0));
    //     int result = 0;
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             if (grid[i][j] == '0' || visited[i][j] == 1)
    //                 continue;
    //             result++;
    //             queue<int> q{{i * n + j}};
    //             visited[i][j] = 1;
    //             while (!q.empty())
    //             {
    //                 int pos = q.front();
    //                 q.pop();
    //                 int y = pos / n;
    //                 int x = pos % n;
    //                 for (const auto &d : dirs)
    //                 {
    //                     int nx = x + d[0];
    //                     int ny = y + d[1];
    //                     if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
    //                         grid[ny][nx] == '0' || visited[ny][nx] == 1)
    //                         continue;
    //                     visited[ny][nx] = 1;
    //                     q.push(ny * n + nx);
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: DFS
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int result = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, result, i, j);
                    result++;
                }
            }
        }
        return result;
    }
private:
    vector<vector<int>> dirs{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(const vector<vector<char>> &grid, vector<vector<bool>> &visited, int& result, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j])
            return;
        visited[i][j] = true;
        for(const auto& d : dirs)
            dfs(grid, visited, result, i + d[0], j + d[1]);
    }
};
// @lc code=end
