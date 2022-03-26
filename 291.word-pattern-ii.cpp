/*
 * @lc app=leetcode id=291 lang=cpp
 *
 * [291] Word Pattern II
 */

// @lc code=start

// #include "dummyHead.h"

// Solution: Backtracking
//  ref: https://www.cnblogs.com/grandyang/p/5325761.html
class Solution
{
public:
    bool wordPatternMatch(string pattern, string str)
    {
        return helper(pattern, str, 0, 0);
    }

private:
    // pi: pattern index
    // si: str index
    bool helper(const string& pattern, const string& str, int pi, int si){
        if(pi == pattern.size() && si == str.size())
            return true;
        if(pi == pattern.size() || si == str.size())
            return false;

        // current search pattern char
        char p = pattern[pi];

        // find all possible string for the pattern char
        for(int i = si; i < str.size(); ++i){
            string t = str.substr(si, i - si + 1);
            if(m.count(p) && m[p] == t){
                if(helper(pattern, str, pi + 1, i + 1))
                    return true;
            }
            else if(!m.count(p)){
                if(s.count(t))
                    continue;
                m[p] = t;
                s.insert(t);
                if(helper(pattern, str, pi + 1, i + 1))
                    return true;
                m.erase(p);
                s.erase(t);
            }
        }
        return false;
    }

    unordered_map<char, string> m;
    unordered_set<string> s;
};
// @lc code=end
