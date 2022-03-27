/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: Recursion DFS
//  ref: http://zxi.mytechroad.com/blog/string/leetcode-856-score-of-parentheses/ 
class Solution {
public:
    int scoreOfParentheses(string s) {
        if(s == "()")
            return 1;
        int balance = 0;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i] == '(') balance++;
            if(s[i] == ')') balance--;
            if(balance == 0)
                return scoreOfParentheses(s.substr(0, i+1)) + 
                        scoreOfParentheses(s.substr(i+1));
        }
        return 2 * scoreOfParentheses(s.substr(1, s.size() - 2));
    }
};
// @lc code=end

