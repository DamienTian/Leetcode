/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
//#include "dummyHead.h"

class Solution {
public:
    // Solution 1: binary search on both vertical and horizontal (search on diagonal)
    //  ref: https://leetcode.com/problems/search-a-2d-matrix-ii/solution/ (Solution 2)
    //  note: notice the diagonal (left-up to right-down) of matrix is in order
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        
        // Loop times depend on the shorter dimension
        int shortDimension = min(matrix.size(), matrix[0].size());
        for(int i = 0; i < shortDimension; ++i){
            bool verticalFound = binarySearch(matrix, target, i, true);
            bool horizontalFound = binarySearch(matrix, target, i, false);
            if(verticalFound || horizontalFound)
                return true;
        }
        return false;
    }

private:
    bool binarySearch(const vector<vector<int>>& matrix, int target, int start, bool isVertical){
        int low = start;
        int high = isVertical ? matrix.size() : matrix[0].size();

        while(low < high){
            int mid = low + (high - low) / 2;
            if(isVertical){
                if(matrix[mid][start] < target)
                    low = mid + 1;
                else if(matrix[mid][start] > target)
                    high = mid;
                else
                    return true;
            }
            else{
                if(matrix[start][mid] < target)
                    low = mid + 1;
                else if(matrix[start][mid] > target)
                    high = mid;
                else
                    return true;
            }
        }
        return false; 
    }
};
// @lc code=end

