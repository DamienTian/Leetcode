/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: counting
    //  time: O(n^2)
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     int minRow = 0;
    //     while(k > 0){
    //         minRow = 0;
    //         for(int i = 0; i < matrix.size(); ++i){
    //             if(matrix[i][0] < matrix[minRow][0])
    //                 minRow = i;
    //         }
    //         cout << k << "  " << minRow << endl;
    //         if(k > 1){
    //             matrix[minRow].erase(matrix[minRow].begin());
    //             if(matrix[minRow].empty())
    //                 matrix.erase(matrix.begin() + minRow);
    //             --k;
    //         }
    //         else
    //             break;
    //     }
    //     return matrix[minRow][0];
    // }

    // Solution 2: max heap
    //  ref: https://www.cnblogs.com/grandyang/p/5727892.html
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                q.emplace(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }

    // TODO: Solution 3: Binary Search
    //  ref: https://www.cnblogs.com/grandyang/p/5727892.html
};
// @lc code=end

