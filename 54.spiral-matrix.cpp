/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
//#include "dummyHead.h"

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
// @lc code=end
