/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
// Definition for a QuadTree node.
// class Node
// {
// public:
//     bool val;
//     bool isLeaf;
//     Node *topLeft;
//     Node *topRight;
//     Node *bottomLeft;
//     Node *bottomRight;

//     Node()
//     {
//         val = false;
//         isLeaf = false;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = NULL;
//         topRight = NULL;
//         bottomLeft = NULL;
//         bottomRight = NULL;
//     }

//     Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
//     {
//         val = _val;
//         isLeaf = _isLeaf;
//         topLeft = _topLeft;
//         topRight = _topRight;
//         bottomLeft = _bottomLeft;
//         bottomRight = _bottomRight;
//     }
// };

// #include "dummyHead.h"

// Solution: Divide and conquer
// ref: https://www.cnblogs.com/grandyang/p/9649348.html
//  TODO: didn't make it, and don't really understand his solution
// class Solution
// {
// public:
//     Node *construct(vector<vector<int>> &grid)
//     {
//         return helper(grid, 0, grid.size() - 1, 0, grid[0].size());
//     }

//     Node *helper(vector<vector<int>> &grid, int leftBound, int rightBound, int topBound, int bottomBound)
//     {
//         if (leftBound > rightBound || topBound > bottomBound)
//             return nullptr;
//         bool isLeaf = true;
//         int currentGridVal = grid[leftBound][topBound];
//         // where to divide gird into 1/4 size of before
//         int rowMid = leftBound + (rightBound - leftBound) / 2;
//         int colMid = topBound + (bottomBound - topBound) / 2;
//         for (int i = leftBound; i < rightBound; ++i)
//         {
//             for (int j = topBound; j < bottomBound; ++j)
//             {
//                 if (grid[i][j] != currentGridVal)
//                 {
//                     isLeaf = false;
//                     break;
//                 }
//             }
//         }

//         if (isLeaf)
//             return new Node(currentGridVal == 1, true, nullptr, nullptr, nullptr, nullptr);
//         return new Node(false, false,
//                         helper(grid, leftBound, rowMid, topBound, colMid), // top left
//                         helper(grid, leftBound, rowMid, colMid + 1, bottomBound),     // bottom left
//                         helper(grid, rowMid + 1, rightBound, topBound, colMid),       // top right
//                         helper(grid, rowMid + 1, rightBound, colMid + 1, bottomBound) // bottom right
//         );
//     }
// };

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
    Node* build(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        if (r1 > r2 || c1 > c2) return NULL;
        bool isLeaf = true;
        int val = grid[r1][c1], rowMid = (r1 + r2) / 2, colMid = (c1 + c2) / 2;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
        }
        if (isLeaf) return new Node(val == 1, true, NULL, NULL, NULL, NULL);
        return new Node(false, false, 
               build(grid, r1, c1, rowMid, colMid),
               build(grid, r1, colMid + 1, rowMid, c2),
               build(grid, rowMid + 1, c1, r2, colMid),
               build(grid, rowMid + 1, colMid + 1, r2, c2));
    }
};
// @lc code=end
