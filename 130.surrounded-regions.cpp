/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
//#include "dummyHead.h"

class Solution {
public:
    // Solution 1: DFS
    void solve(vector<vector<char>>& board){
        // solveDFS(board);
        solveBFS(board);
    }

    void solveDFS(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // change all 'o' that is connect to the edge to 'A',
        // those 'o's are not surrounded
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || i == m-1 || j == 0 || j == n-1)
                    dfs(board, i, j);
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'A')
                    board[i][j] = 'O';     
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

    // Solution 2：BFS
    void solveBFS(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        stack<int> s;
        // add all side into search queue
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                    s.push(i * n + j);
            }
        }
        while(!s.empty()){
            int index = s.top();
            s.pop();
            int x = index / n, y = index % n;
            board[x][y] = 'A';
            for(auto d : dirs){
                int newX = x + d[0], newY = y + d[1];
                if(newX >= 0 && newX < m && newY >= 0 && newY < n && 
                  board[newX][newY] == 'O'){
                    s.push(newX * n + newY);
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    
private:
    vector<vector<int>> dirs {{1,0}, {-1,0}, {0,1}, {0,-1}};
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i < 0 || i >= board.size() || 
           j < 0 || j >= board[0].size() ||
          board[i][j] == 'X')
            return;
        if(board[i][j] == 'O'){
            cout << " Get edge O at " << i << " " << j << endl; 
            board[i][j] = 'A';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
        
    }
};

// @lc code=end
