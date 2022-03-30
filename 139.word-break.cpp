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

    // Solution: DFS Recursive with memoization
    //  ref: http://zxi.mytechroad.com/blog/leetcode/leetcode-139-word-break/
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        return wordBreak(s, dict);
    }

private:
    bool wordBreak(string s, const unordered_set<string> &dict){
        if(mem.count(s))
            return mem[s];
        if(dict.count(s))
            return mem[s] = true;
        // break string and test
        for(int i = 1; i < s.length(); ++i){
            const string left = s.substr(0, i);
            const string right = s.substr(i);
            if(dict.count(left) && wordBreak(right, dict))
                return mem[s] = true;
        }
        return mem[s] = false;
    }

    unordered_map<string, bool> mem;
};
// @lc code=end
