/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return dp(s, wordDict);
    }

private:
    // Solution 1: dp
    //  ref: https://www.cnblogs.com/grandyang/p/4257740.html
    bool dp(string s, vector<string>& wordDict){
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 0; i < dp.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && wordSet.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end

