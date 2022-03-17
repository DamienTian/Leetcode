/*
 * @lc app=leetcode id=1086 lang=cpp
 *
 * [1086] High Five
 */

// @lc code=start
//#include "dummyHead.h"

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> records;
        for(const vector<int>& i : items){
            records[i[0]].push(i[1]);
        }

        vector<vector<int>> result;
        for(auto record : records){
            int total = 0;
            for(int i = 0; i < 5; ++i){
                total += record.second.top();
                record.second.pop();
            }
            result.push_back({record.first, total / 5});
        }

        return result;
    }
};

// @lc code=end
