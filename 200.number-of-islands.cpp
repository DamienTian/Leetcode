/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

// IDEA: DFS / BFS
//  ref: 
//      DFS: https://www.youtube.com/watch?v=XSmgFKe-XYU&t=9s
//      BFS: https://www.cnblogs.com/grandyang/p/4402656.html 
//  time: O(size of the grid) = O(length * width)
class Solution {
public:
    // DFS version
    // int numIslands(vector<vector<char>>& grid) {
    //     int result = 0;
    //     if(grid.empty()){
    //         return result;
    //     } 
    //     size_t length = grid.size();
    //     size_t width = grid[0].size();
    //     for(size_t l = 0; l < length; ++l){
    //         for(size_t w = 0; w < width; ++w){
    //             result += grid[l][w] - '0';
    //             dfs(grid, width, length, w, l);
    //         }
    //     }
    //     return result;
    // }

    // BFS version (no optimization)
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.empty()){
            return result;
        } 
        size_t length = grid.size();
        size_t width = grid[0].size();

        // Check if the place has been visited
        vector<vector<bool>> visited(length, vector<bool>(width, false));
        // Use Queue to stores next grid to search (BFS)
        queue<pair<int, int>> bfsQueue;
        
        for(size_t l = 0; l < length; ++l){
            for(size_t w = 0; w < width; ++w){
                // Find a '1', search all surround grids
                if(grid[l][w] == '1' && !visited[l][w]){
                    bfsQueue.push(make_pair(l, w));
                    ++result;
                    while(!bfsQueue.empty()){
                        auto current = bfsQueue.front();
                        bfsQueue.pop();

                        int y = current.first;
                        int x = current.second;
                        visited[y][x] = true;

                        // Search four directions
                        pair<int, int> left (y, x - 1);
                        pair<int, int> right (y, x + 1);
                        pair<int, int> up (y - 1, x);
                        pair<int, int> down (y + 1, x);
                        vector<pair<int, int>> directions {left, right, up, down};
                        for(auto d : directions){
                            if(d.first < 0 || d.second < 0 || d.first >= length || d.second >= width || 
                               grid[d.first][d.second] == '0' || visited[d.first][d.second]){
                                continue;
                            }
                            // Marked grid is found as visited
                            visited[d.first][d.second] = true;
                            // Push it into queue to find it adjancent in next round of while loop
                            bfsQueue.push(make_pair(d.first, d.second));
                        }
                    }
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& grid, int width, int length ,int x, int y){
        // Out of boundary and '0' check (bask case)
        if(x < 0 || y < 0 || x >= width || y >= length || grid[y][x] == '0'){
            return;
        }
        // If we find the land '1', change it to '0'
        grid[y][x] = '0';
        // Search all adjancent sides
        dfs(grid, width, length, x - 1, y);
        dfs(grid, width, length, x + 1, y);
        dfs(grid, width, length, x, y - 1);
        dfs(grid, width, length, x, y + 1);
    }
};
// @lc code=end

