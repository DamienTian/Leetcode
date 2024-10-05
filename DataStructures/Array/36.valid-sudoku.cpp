/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
//#include "../dummyHead.h"

// Solution: array
//  ref: https://www.cnblogs.com/grandyang/p/4421217.html
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9)); 
        vector<vector<bool>> cols(9, vector<bool>(9)); 
        vector<vector<bool>> cells(9, vector<bool>(9)); 
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.')
                    continue;
                int n = board[i][j] - '1'; // to match indices
                if(rows[i][n] || cols[n][j] || cells[3 * (i / 3) + j / 3][n])
                    return false;
                rows[i][n] = true;
                cols[n][j] = true;
                cells[3 * (i / 3) + j / 3][n] = true;
            }
        }
        return true;
    }
};
// @lc code=end

