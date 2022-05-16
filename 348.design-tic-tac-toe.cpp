/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start

// #include "dummyHead.h"

// Solution 1: 2D memory
// class TicTacToe
// {
// public:
//     TicTacToe(int n)
//     {
//         size = n;
//         board.resize(n, vector<int>(n, 0));
//         horizontalCount.resize(n, vector<int>(2, 0));
//         verticalCount.resize(n, vector<int>(2, 0));
//         diagonalCountLeft.resize(2, 0);
//         diagonalCountRight.resize(2, 0);
//         winner = 0;
//     }
//     int move(int row, int col, int player)
//     {
//         if (board[row][col] != 0)
//             return -1;
//         if (winner != 0)
//             return winner;
//         board[row][col] = player;
//         horizontalCount[row][player - 1]++;
//         verticalCount[col][player - 1]++;
//         if (row == col || row + col + 1 == size)
//         {
//             if(row == col && row + col + 1 == size)
//             {
//                 diagonalCountLeft[player - 1]++;
//                 diagonalCountRight[player - 1]++;
//             }
//             else if (row == col)
//             {
//                 diagonalCountLeft[player - 1]++;
//             }
//             else
//             {
//                 diagonalCountRight[player - 1]++;
//             }
//         }
//         cout << endl;
//         if (horizontalCount[row][player - 1] == size ||
//             verticalCount[col][player - 1] == size ||
//             diagonalCountLeft[player - 1] == size ||
//             diagonalCountRight[player - 1] == size)
//         {
//             winner = player;
//             return player;
//         }
//         return 0;
//     }
// private:
//     vector<vector<int>> board;
//     vector<vector<int>> horizontalCount;
//     vector<vector<int>> verticalCount;
//     vector<int> diagonalCountLeft, diagonalCountRight;
//     int winner;
//     int size;
// };

// Solution 2: 1D memory
//  ref: https://leetcode.com/problems/design-tic-tac-toe/
class TicTacToe
{
public:
    TicTacToe(int n) : rows(n), cols(n), size(n), diag(0), revDiag(0) {}

    int move(int row, int col, int player)
    {
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += (row == col ? add : 0);
        revDiag += (row == size - col - 1 ? add : 0);
        return (abs(rows[row]) == size || abs(cols[col]) == size || abs(diag) == size || abs(revDiag) == size) ? player : 0;
    }

private:
    vector<int> rows, cols;
    int diag, revDiag, size;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

// @lc code=end
