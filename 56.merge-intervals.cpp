/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Failed Solution: tried to use merge sort
    //  note: don't over complicated the problem
    // vector<vector<int>> merge(vector<vector<int>> &intervals)
    // {
    //     if (intervals.empty() || intervals.size() == 1)
    //         return intervals;
    //     vector<vector<int>> left(intervals.begin(), intervals.begin() + intervals.size() / 2);
    //     vector<vector<int>> right(intervals.begin() + intervals.size() / 2 + 1, intervals.begin() + intervals.size());
    //     return mergeSort(merge(left), merge(right));
    // }

    // Solution: sort by first elements, then insert
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty() || intervals.size() == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& v1, const vector<int>& v2){
                return v1[0] < v2[0];
            });
        vector<vector<int>> result {intervals[0]};
        for(int i = 1; i < intervals.size(); ++i){
            if(intervals[i][0] > result[result.size()-1][1])
                result.push_back(intervals[i]);
            else
                result[result.size()-1][1] = max(intervals[i][1], result[result.size()-1][1]);
        }
        return result;
    }

private:
    // vector<vector<int>> mergeSort(vector<vector<int>> &left, vector<vector<int>> &right)
    // {
    //     vector<vector<int>> result;
    //     int l = 0, r = 0;
    //     while (l < left.size() && r < right.size())
    //     {
    //         if (left[l][0] < right[r][0]){
    //             result.push_back(left[l]);
    //             if(left[l][1] > right[r][0]){
    //                 result[result.size()-1][1] = right[r][1];
    //             }
    //             l++;
    //         }
    //         else{
    //             result.push_back(right[r]);
    //             if(right[r][1] > left[l][0]){
    //                 result[result.size()-1][1] = left[l][1];
    //             }
    //             r++;
    //         }
    //     }
    //     return result;
    // }
};
// @lc code=end
