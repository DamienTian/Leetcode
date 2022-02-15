/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    // Solution 1: BFS 
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    //     vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    //     vector<vector<int>> visited(image.size() , vector<int>(image[0].size(), 0));
    //     queue<pair<int, int>> q;
    //     q.push({sr, sc});
    //     int originColor = image[sr][sc];
    //     while(!q.empty()){
    //         auto p = q.front();
    //         q.pop();
    //         for(const auto& d : directions){
    //             int r = p.first + d[0];
    //             int c = p.second + d[1];
    //             if(r >= 0 && r < image.size() && c >= 0 && c < image[r].size() && !visited[r][c] && image[r][c] == originColor){
    //                 q.push({r, c});
    //             }
    //         }
    //         image[p.first][p.second] = newColor;
    //         visited[p.first][p.second] = 1;
    //     }

    //     return image;
    // }

    // Solution 2: DFS
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> visited(image.size() , vector<int>(image[0].size(), 0));
        int originColor = image[sr][sc];
        dfs(image, visited, originColor, newColor, sr, sc);
        return image;
    }

    void dfs(vector<vector<int>>& image, vector<vector<int>> visited, int originColor, int newColor, int r, int c){
        if(r < 0 || r >= image.size() || c < 0 || c >= image[r].size() || visited[r][c] || image[r][c] != originColor){
            return;
        }
        image[r][c] = newColor;
        visited[r][c] = 1;
        dfs(image, visited, originColor, newColor, r - 1, c);
        dfs(image, visited, originColor, newColor, r + 1, c);
        dfs(image, visited, originColor, newColor, r, c - 1);
        dfs(image, visited, originColor, newColor, r, c + 1);
    }
};
// @lc code=end

