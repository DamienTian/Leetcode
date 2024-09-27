/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
//#include "../dummyHead.h"

// most recent practice
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();      // col size
        int n = matrix[0].size();   // row size
        int total = m * n;
        int l = 0, r = n, t = 0, b = m; // bounds (left, right, top, botttom)
        int x = 0, y = 0;
        int dirX = 1, dirY = 0; // moving direction
        vector<int> result;
        while(total > 0){
            result.push_back(matrix[y][x]);
            total--;
            x += dirX; y += dirY;
            if(x >= r){ // moving right, hit the right bound, means the top was all went through
                x--; y++; dirX = 0; dirY = 1; t++; 
            }
            else if(y >= b){ // moving down, hit the bottom bound, means the right was all went through
                x--; y--; dirX = -1; dirY = 0; r--;
            }
            else if(x < l){ // moving left, hit the left bound, means the bottom was all went through
                x++; y--; dirX = 0; dirY = -1; b--;
            }
            else if(y < t){ // moving up, hit the top bound, means the left was all went through
                x++; y++; dirX = 1; dirY = 0; l++;
            }
        }
        return result;
    }
};

/*
class Solution
{
public:
    // Solution
    //  ref: https://www.cnblogs.com/grandyang/p/4362675.html
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();

        // Set the boundaries of
        int up = 0, down = m - 1, left = 0, right = n - 1;

        while (true)
        {
            // search over top
            for (int i = left; i <= right; ++i)
                result.push_back(matrix[up][i]);
            if (++up > down)
                break;

            // search over right
            for (int i = up; i <= down; ++i)
                result.push_back(matrix[i][right]);
            if(--right < left)
                break;
            
            // search over bottom
            for (int i = right; i >= left; --i)
                result.push_back(matrix[down][i]);
            if(--down < up)
                break;

            // search over left
            for (int i = down; i >= up; --i)
                result.push_back(matrix[i][left]);
            if (++left > right)
                break; 
        }

        return result;
    }
};

*/
// @lc code=end
