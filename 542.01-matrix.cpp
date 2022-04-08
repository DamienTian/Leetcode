/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Falied Solution: BFS (TLE)
    //  note: do BFS on every 1, correct thought, but failed with last case
    // vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    // {
    //     int m = mat.size();
    //     int n = mat[0].size();
    //     vector<vector<int>> result(m, vector<int>(n, 0));
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             if (mat[i][j] == 0)
    //                 continue;
    //             queue<vector<int>> q;
    //             q.push({i, j});
    //             set<vector<int>> visited;
    //             int distance = 0;
    //             bool foundZero = false;
    //             while (!q.empty() && !foundZero)
    //             {
    //                 for (int k = q.size(); k > 0; --k)
    //                 {
    //                     auto curr = q.front();
    //                     q.pop();
    //                     if (mat[curr[0]][curr[1]] == 0)
    //                     {
    //                         result[i][j] = distance;
    //                         foundZero = true;
    //                         break;
    //                     }
    //                     for (auto d : directions)
    //                     {
    //                         int x = curr[0] + d[0], y = curr[1] + d[1];
    //                         if (x < 0 || y < 0 || x >= m || y >= n || visited.count({x, y}))
    //                             continue;
    //                         visited.insert({x, y});
    //                         q.push({x, y});
    //                     }
    //                 }
    //                 distance++;
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution 1: BFS 
    //  ref: https://www.cnblogs.com/grandyang/p/6602288.html
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        // push all 0 into q, do bfs search from 0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }

        // search from 0s
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto d : directions){
                int x = curr[0] + d[0], y = curr[1] + d[1];
                if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] <= mat[curr[0]][curr[1]] + 1) continue;
                mat[x][y] =  mat[curr[0]][curr[1]] + 1;
                q.push({x, y});
            }
        }

        return mat;
    }

private:
    vector<vector<int>> directions{
        {0, -1}, // up
        {0, 1},  // down
        {-1, 0}, // left
        {1, 0},  // right
    };
};
// @lc code=end
