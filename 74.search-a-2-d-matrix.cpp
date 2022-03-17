/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Binary search 2D
    //  note: coulde be solved by treating the matrix as a vector
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int vectorSize = matrix[0].size();
        int mleft = 0;
        int mright = matrix.size();

        // find vector that can contain target
        while (mleft < mright)
        {
            int mmid = mleft + (mright - mleft) / 2;
            if (matrix[mmid][0] <= target && matrix[mmid][vectorSize - 1] >= target)
            {
                // Break the outer while loop if the target vector was founded 
                mleft = mright;

                // Find target from target vector
                int left = 0, right = vectorSize;
                while (left < right)
                {
                    int mid = left + (right - left) / 2;
                    if (matrix[mmid][mid] == target)
                        return true;
                    else if (matrix[mmid][mid] < target)
                        left = mid + 1;
                    else
                        right = mid;
                }
            }
            else if (matrix[mmid][0] >= target)
                mright = mmid;
            else
                mleft = mmid + 1;
        }

        return false;
    }
};
// @lc code=end
