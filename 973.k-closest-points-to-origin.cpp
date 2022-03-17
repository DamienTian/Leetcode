/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: sort
    // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    //     sort(points.begin(), points.end(), compare);
    //     vector<vector<int>> result;
    //     for(int i = 0; i < k; ++i)
    //         result.push_back(points.at(i));
    //     return result;
    // }

    // Solution 2: max heap (c++ priority queue)
    //  ref: https://www.cnblogs.com/grandyang/p/14159477.html
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;

        // use a priority queue to store a pair: distance - index in points
        priority_queue<pair<int, int>> pq;

        for(int i = 0; i < points.size(); ++i){
            int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({distance, i});
            if(pq.size() > k)
                pq.pop();   // pop the top (the largest distance)
        }
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            result.push_back(points[t.second]);
        }
        return result;
    }   

private:
    inline static double distanceToOrigin(const vector<int>& point){
        return sqrt(point[0] * point[0] + point[1] * point[1]);
    }

    static bool compare(const vector<int>& p1, const vector<int>& p2){
        return distanceToOrigin(p1) > distanceToOrigin(p2);
    }
};
// @lc code=end

