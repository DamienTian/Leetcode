/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
//#include "dummyHead.h"

// Solution: BFS
//  ref: https://www.cnblogs.com/grandyang/p/8449211.html
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000")    return 0;
        unordered_set<string> deadendsSet (deadends.begin(), deadends.end());
        if(deadendsSet.count("0000")) return -1;
        queue<string> q {{"0000"}};
        unordered_set<string> visited {{"0000"}};
        int result = 0;
        vector<int> moves {1, -1};
        while(!q.empty()){
            result++;
            for(int k = q.size(); k > 0; --k){
                string curr = q.front();
                q.pop();
                
                for(int i = 0; i < curr.length(); ++i){
                    for(int move : moves){
                        string next = curr;
                        next[i] = ((curr[i] - '0') + 10 + move) % 10 + '0';
                        if(next == target)
                            return result;
                        if(!visited.count(next) && !deadendsSet.count(next)){
                            q.push(next);
                        }
                        visited.emplace(next);
                    }
                }
            }
            
        }
        return -1;
    }
};

// @lc code=end