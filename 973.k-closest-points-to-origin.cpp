/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

//#include "dummyHead.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);
        vector<vector<int>> result;
        for(int i = 0; i < k; ++i)
            result.push_back(points.at(i));
        return result;
    }

private:
    inline static double distanceToOrigin(const vector<int>& point){
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    static bool compare(const vector<int>& p1, const vector<int>& p2){
        return distanceToOrigin(p1) < distanceToOrigin(p2);
    }
};
// @lc code=end

