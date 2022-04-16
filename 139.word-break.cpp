/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Falied Solution: Time Limit Exceeded
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     if (s.empty())
    //         return true;
    //     for (string word : wordDict)
    //     {
    //         if (s.substr(0, word.size()) == word)
    //         {
    //             //cout << s.substr(0, word.size()) << " == " << word << "  reamin s: " << s.substr(word.size()) << endl;
    //             if(wordBreak(s.substr(word.size()), wordDict))
    //                 return true;
    //         }
    //     }
    //     return false;
    // }

    // Solution 1: DFS Recursive with memoization
    //  ref: http://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/
    // bool wordBreak(string s, vector<string> &wordDict)
    // {
    //     unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    //     return wordBreak(s, dict);
    // }

    // Solution 2: DP
    //  ref: https://www.cnblogs.com/grandyang/p/4257740.html
    // bool wordBreak(string s, vector<string> &wordDict)
    // {   
    //     unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    //     vector<bool> dp(s.size() + 1, false);
    //     dp[0] = true;
    //     for(int i = 0; i < dp.size(); ++i){
    //         for(int j = 0; j < i; ++j){
    //             if(dp[j] && wordSet.count(s.substr(j, i - j))){
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp.back();
    // }

    // Solution 3: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/4257740.html
    //  note: BFS the first valid word, push next start search index to queue, then BFS again
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> visited(s.size(), false);
        queue<int> q{{0}};
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(!visited[start]){
                for(int i = start + 1; i <= s.size(); ++i){
                    if(wordSet.count(s.substr(start, i - start))){
                        q.push(i);
                        if(i == s.size())
                            return true;
                    }
                }
                visited[start] = true;
            }
        }
        return false;
    }

private:
    // helper function for DFS
    bool wordBreak(string s, const unordered_set<string> &dict)
    {
        if (mem.count(s))
            return mem[s];
        if (dict.count(s))
            return mem[s] = true;
        // break string and test
        for (int i = 1; i < s.length(); ++i)
        {
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            if (dict.count(left) && wordBreak(right, dict))
                return mem[s] = true;
        }
        return mem[s] = false;
    }

    unordered_map<string, bool> mem;
};
// @lc code=end
