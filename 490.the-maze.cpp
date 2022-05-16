/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS (REVIEW 1)
    //  ref: https://www.cnblogs.com/grandyang/p/6381458.html
    // bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    // {
    //     int m = maze.size(), n = maze[0].size();
    //     if (m == 0 || n == 0 || maze[start[0]][start[1]] == 1)
    //         return false;
    //     vector<vector<int>> visited(m, vector<int>(n, 0));
    //     queue<vector<int>> q{{start}};
    //     visited[start[0]][start[1]] = 1;
    //     while (!q.empty())
    //     {
    //         vector<int> pos = q.front();
    //         q.pop();
    //         if (pos[0] == destination[0] && pos[1] == destination[1])
    //                 return true;
    //         for (const auto &d : directions)
    //         {
    //             int x = pos[0], y = pos[1];
    //             while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0)
    //             {
    //                 x += d.first;
    //                 y += d.second;
    //             }
    //             x -= d.first;
    //             y -= d.second;
    //             if(visited[x][y] == 0){
    //                 visited[x][y] = 1;
    //                 q.push({x, y});
    //             }
    //         }
    //     }
    //     return false;
    // }

    // Solution 2: DFS (REVIEW 1)
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    {
        return dfs(maze, start, destination);
    }

private:
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Solution 2: DFS + Memo
    //  ref: https://www.cnblogs.com/grandyang/p/6381458.html
    bool dfs(vector<vector<int>> &maze, vector<int> &current, vector<int> &destination)
    {
        if (current[0] == destination[0] && current[1] == destination[1])
            return true;
        int m = maze.size(), n = maze[0].size();
        bool result = false;
        maze[current[0]][current[1]] = -1;
        for (const auto &d : directions)
        {
            int x = current[0], y = current[1];
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1)
            {
                x += d.first;
                y += d.second;
            }
            x -= d.first;
            y -= d.second;
            if (maze[x][y] != -1)
            {
                vector<int> next{x, y};
                result |= dfs(maze, next, destination);
            }
        }
        return result;
    }
};

// @lc code=end