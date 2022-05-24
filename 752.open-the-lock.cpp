/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
// #include "dummyHead.h"
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        return bfs(deadends, target);
    }

private:
    // Solution 1: BFS (REVIEW 1)
    //  ref: https://www.cnblogs.com/grandyang/p/8449211.html
    int bfs(vector<string>& deadends, string target){
        int result = 0;
        if(target == "0000")
            return 0;
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        if (deadset.count("0000"))
            return -1;
        queue<string> q {{"0000"}};
        unordered_set<string> visited{"0000"};
        vector<char> moves {'+', '-'};
        while(!q.empty()){
            int level = q.size();
            for(int i = 0; i < level; ++i){
                string curr = q.front();
                q.pop();
                if(curr == target)
                    return result;
                for(int j = 0; j < curr.size(); ++j){
                    for(const char& m : moves){
                        string modifyCurr = curr;
                        if(m == '+')
                            modifyCurr[j] = (curr[j] == '9') ? '0' : curr[j] + 1;
                        else if(m == '-')
                            modifyCurr[j] = (curr[j] == '0') ? '9' : curr[j] - 1;
                        if(!visited.count(modifyCurr) && !deadset.count(modifyCurr))
                            q.push(modifyCurr);
                        visited.insert(modifyCurr);
                    }
                }
            }
            result++;
        }
        return -1;
    }
};

// @lc code=end