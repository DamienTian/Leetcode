/*
 * @lc app=leetcode id=490 lang=cpp
 *
 * [490] The Maze
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/6381458.html
    // bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination)
    // {
    //     vector<vector<int>> visited = maze;
    //     // Mark start pos as visited
    //     visited[start[0]][start[1]] = 1;
    //     int m = maze.size();
    //     int n = maze[0].size();
    //     queue<int> q{{start[0] * n + start[1]}};
    //     while (!q.empty())
    //     {
    //         int pos = q.front();
    //         q.pop();
    //         int posX = pos / n, posY = pos % n;

    //         // if reach the des, return true;
    //         if (posX == destination[0] && posY == destination[1])
    //             return true;

    //         // Check if the ball can move from the pos to anywhere
    //         // if (!moveable(posX, posY, m, n, visited))
    //         //     continue;

    //         for (auto d : directions)
    //         {
    //             int moveX = posX, moveY = posY;
    //             while (moveX + d.first >= 0 && moveX + d.first < m &&
    //                    moveY + d.second >= 0 && moveY + d.second < n &&
    //                    maze[moveX + d.first][moveY + d.second] == 0)
    //             {
    //                 moveX += d.first;
    //                 moveY += d.second;
    //             }
    //             if(!visited[moveX][moveY]){
    //                 visited[moveX][moveY] = 1;
    //                 q.push(moveX * n + moveY);
    //             }
    //         }
            

    //     }
    //     return false;
    // }

    // Solution 2: DFS:
    //  ref: https://www.cnblogs.com/grandyang/p/6381458.html
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination){
        return dfs(maze, start, destination);
    }
private:
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool dfs(vector<vector<int>> &maze, vector<int> &current, vector<int> &destination){
        if(current[0] == destination[0] && current[1] == destination[1])
            return true;
        bool result = false;
        int m = maze.size(), n = maze[0].size();
        maze[current[0]][current[1]] = -1;
        for(auto d : directions){
            int x = current[0];
            int y = current[1];
            while(x + d.first >= 0 && x + d.first < m && 
                y + d.second >= 0 && y + d.second < n && 
                maze[x + d.first][y + d.second] != 1){
                    x += d.first;
                    y += d.second;
            }
            if(maze[x][y] != -1){
                vector<int> next {x, y};
                result |= dfs(maze, next, destination);
            }
        }
        return result;
    }

};

// @lc code=end