/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DP
    //  ref: https://www.cnblogs.com/grandyang/p/4298664.html
    // bool isInterleave(string s1, string s2, string s3) {
    //     if(s1.length() + s2.length() != s3.length())
    //         return false;
    //     // DP table to memorize if first i chars of s1 and first j chars of s2 can bulid first i+j chars of s3
    //     vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
    //     for(int i = 0; i <= s1.length(); ++i){
    //         for(int j = 0; j <= s2.length(); ++j){
    //             if(i == 0 && j == 0)
    //                 dp[i][j] = true;
    //             else if(i == 0)
    //                 dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[j - 1];
    //             else if(j == 0)
    //                 dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i - 1];
    //             else 
    //                 dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i - 1 + j]) || 
    //                             (dp[i][j - 1] && s2[j - 1] == s3[j - 1 + i]);
    //         }
    //     }
    //     return dp[s1.length()][s2.length()];
    // }

    // Solution 2: DFS + Memoization
    //  ref: https://www.cnblogs.com/grandyang/p/4298664.html
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        unordered_set<int> failedCombine;
        return dfs(s1,s2,s3,0,0,0,failedCombine);
    }

private:
    
    bool dfs(const string& s1, const string& s2, const string& s3, int s1Index, int s2Index, int s3Index, unordered_set<int>& failedCombine){
        int com = s1Index * s3.size() + s2Index;
        if(failedCombine.count(com))
            return false;
        // if one of s1 or s2 has been completely searched, compare remain substr
        if(s1Index == s1.size()) return s2.substr(s2Index) == s3.substr(s3Index);
        if(s2Index == s2.size()) return s1.substr(s1Index) == s3.substr(s3Index);
        if((s1[s1Index] == s3[s3Index] && dfs(s1, s2, s3, s1Index+1, s2Index, s3Index+1, failedCombine)) || 
            (s2[s2Index] == s3[s3Index] && dfs(s1, s2, s3, s1Index, s2Index+1, s3Index+1, failedCombine))){
                return true;
            }
        failedCombine.insert(com);
        return false;
    }
};
// @lc code=end

