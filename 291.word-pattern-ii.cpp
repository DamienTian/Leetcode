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
            // if find the match, continue search for remaining
            if(m.count(p) && m[p] == t){
                if(helper(pattern, str, pi + 1, i + 1))
                    return true;
            }
            // if m does not has current search pattern ... 
            else if(!m.count(p)){
                // if the substring has been found, continue the for loop (i++)
                //  note:
                /*  
                    think aoubt str = "redrediredredi" pattern = "abab"
                    a could be "red", b could be "redi"
                    since "red" has matched with 'a', when search to "redi", 
                    the first 3 letters "red" will be skip and "redi" will be matched
                */
                if(s.count(t))
                    continue;

                // add new match into hash table and set
                m[p] = t;
                s.insert(t);
                if(helper(pattern, str, pi + 1, i + 1))
                    return true;

                // if the search with this substring does not match pattern, pop the substring out
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
