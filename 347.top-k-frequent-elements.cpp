/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: hash map + priority queue
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> result;

    //     unordered_map<int, int> um;
    //     for(int num : nums)
    //         um[num]++;

    //     priority_queue<pair<int, int>> pq;
    //     for(auto m : um)
    //         pq.push(make_pair(m.second, m.first));

    //     while(k > 0){
    //         result.push_back(pq.top().second);
    //         pq.pop();
    //         --k;
    //     }

    //     return result;
    // }

    // Solution 2: Bucket sort 
    //  ref: https://www.cnblogs.com/grandyang/p/5454125.html
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;

        unordered_map<int, int> um;
        for(int num : nums)
            um[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for(auto u : um)
            buckets[u.second].push_back(u.first);
        
        for(int i = nums.size(); i > 0; --i){
            for(int j = 0; j < buckets[i].size(); ++j){
                result.push_back(buckets[i][j]);
                if(result.size() == k)  return result;
            }
        }

        return result;
    }
};
// @lc code=end

