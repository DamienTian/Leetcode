/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
// #include "dummyHead.h"

// Solution: DFS
//  ref: https://www.cnblogs.com/grandyang/p/4444160.html
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrackingDFS(n, n, "", result);
        return result;
    }

    void backtrackingDFS(int left, int right, string current, vector<string>& result){
        if(left > right)    // for case ")("   
            return;
        if(left == 0 && right == 0)
            result.push_back(current);
        else{
            if(left > 0)
                backtrackingDFS(left - 1, right, current + '(', result);
            if(right > 0)
                backtrackingDFS(left, right - 1, current + ')', result);
        }
    }
};
// @lc code=end

