/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Falied Solution: Brute force, time limit exceed
    // void setZeroes(vector<vector<int>> &matrix)
    // {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for (int i = 0; i < m; ++i)
    //     {
    //         for (int j = 0; j < n; ++j)
    //         {
    //             if(matrix[i][j] == 0){
    //                 int goLeft = j - 1, goRight = j + 1, goUp = i - 1, goDown = i + 1;
    //                 while(goLeft >= 0){
    //                     if(matrix[i][goLeft] != 0)
    //                         matrix[i][goLeft--] = 0;
    //                 }
    //                 while(goRight < n){
    //                     if(matrix[i][goRight] != 0)
    //                         matrix[i][goRight++] = 0;
    //                 }
    //                 while(goUp >= 0){
    //                     if(matrix[goUp][j] != 0)
    //                         matrix[goUp--][j] = 0;
    //                 }
    //                 while(goDown < m){
    //                     if(matrix[goDown][j] != 0)
    //                         matrix[goDown++][j] = 0;
    //                 }
    //             }
    //         }
    //     }
    // }

    // Solution 1: Grandyang
    //  ref: https://grandyang.com/leetcode/73/
    void setZeroes(vector<vector<int>> &matrix)
    {
        if(matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool rowZero = false, colZero = false;
        
        // check first row and column's 0s
        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) colZero = true;
        }
        for (int i = 0; i < n; ++i) {
            if (matrix[0][i] == 0) rowZero = true;
        } 

        // check 0s except fir row and column, and use first row and column 
        // to stores the search result (very important, this makes space O(1))
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // update matrix
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (rowZero) {
            for (int i = 0; i < n; ++i) matrix[0][i] = 0;
        }
        if (colZero) {
            for (int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};
// @lc code=end
