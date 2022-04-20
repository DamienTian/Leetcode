/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: Heap Sort
    //  ref: https://www.cnblogs.com/grandyang/p/7689927.html
    //  note: see how to use heap to sort result
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto compare = [](pair<string, int> p1, pair<string, int> p2){
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)> q(compare);
        unordered_map<string, int> mem;
        for(const string& w : words)
            mem[w]++;
        for(const auto& m : mem){
            q.push(m);
            if (q.size() > k) q.pop();
        }
        vector<string> result(k);
        for(int i = k - 1; i >= 0; --i){
            result[i] = (q.top().first);
            q.pop();
        }
        return result;
    }

    // TODO: bucket sort 
    //  ref: https://www.cnblogs.com/grandyang/p/7689927.html
};
// @lc code=end

