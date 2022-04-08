/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/14590796.html
    //  note: a better way to do this is A* algorithm
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0][0] == 1)
            return -1;
        const int m = grid.size();
        const int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = 0;
        queue<vector<int>> q;
        q.push({0, 0});
        int result = 0;
        while (!q.empty())
        {
            result++;
            // Level Order Travensal
            for (int i = q.size(); i > 0; --i)
            {
                auto curr = q.front();
                q.pop();
                if (curr[0] == m - 1 && curr[1] == n - 1)
                    return result;
                for (auto d : directions)
                {
                    int x = curr[0] + d[0], y = curr[1] + d[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 1 || visited[x][y] != -1)
                        continue;
                    visited[x][y] = result;
                    q.push({x, y});
                }
            }
        }

        return -1;
    }

private:
    vector<vector<int>> directions{
        {0, -1},  // up
        {0, 1},   // down
        {-1, 0},  // left
        {1, 0},   // right
        {-1, -1}, // up left
        {1, -1},  // up right
        {-1, 1},  // down left
        {1, 1}    // down right
    };
};
// @lc code=end
