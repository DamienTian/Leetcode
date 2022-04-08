/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/5962508.html
    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //     if(heights.empty() || heights[0].empty())
    //         return {};
    //     int m = heights.size();
    //     int n = heights[0].size();
    //     // using to queue to de BFS: one for pacific, another for Atlantic
    //     queue<vector<int>> qPac, qAtl;
    //     // two bfs results
    //     vector<vector<bool>> pacific(m, vector<bool>(n, false));
    //     vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    //     // mark pacific and atlantic sides
    //     for(int i = 0; i < m; ++i){
    //         qPac.push({i, 0});
    //         pacific[i][0] = true;
    //         qAtl.push({i, n - 1});
    //         atlantic[i][n - 1] = true;
    //     }
    //     for(int i = 0; i < n; ++i){
    //         qPac.push({0, i});
    //         pacific[0][i] = true;
    //         qAtl.push({m - 1, i});
    //         atlantic[m - 1][i] = true;
    //     }
    //     // do bfs on both pacific and atlantic
    //     bfs(heights, pacific, qPac);
    //     bfs(heights, atlantic, qAtl);
    //     // if both pacific and atlantic are true, result is true
    //     vector<vector<int>> result;
    //     for (int i = 0; i < m; ++i) {
    //         for (int j = 0; j < n; ++j) {
    //             if (pacific[i][j] && atlantic[i][j]) {
    //                 result.push_back({i, j});
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: DFS
    //  ref: https://www.cnblogs.com/grandyang/p/5962508.html
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        if (heights.empty() || heights[0].empty())
            return {};
        int m = heights.size();
        int n = heights[0].size();
        // two bfs results
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        // mark pacific and atlantic sides
        for (int i = 0; i < m; ++i)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int i = 0; i < n; ++i)
        {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }
        // if both pacific and atlantic are true, result is true
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void bfs(const vector<vector<int>> &heights, vector<vector<bool>> &mark, queue<vector<int>> q)
    {
        int m = heights.size();
        int n = heights[0].size();
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for (auto d : directions)
            {
                int x = curr[0] + d[0], y = curr[1] + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || mark[x][y] || heights[x][y] < heights[curr[0]][curr[1]])
                    continue;
                mark[x][y] = true;
                q.push({x, y});
            }
        }
    }

    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &mark, int x, int y)
    {
        if (x < 0 || x >= heights.size() || y < 0 || y >= heights[0].size() || mark[x][y])
            return;
        mark[x][y] = true;
        for (auto d : directions)
        {
            int nx = x + d[0], ny = y + d[1];
            if (nx >= 0 && nx < heights.size() && ny >= 0 && ny < heights[0].size() && 
                !mark[nx][ny] && heights[x][y] <= heights[nx][ny])
                dfs(heights, mark, nx, ny);
        }
    }

    vector<vector<int>> directions{
        {0, -1}, // up
        {0, 1},  // down
        {-1, 0}, // left
        {1, 0},  // right
    };
};
// @lc code=end
