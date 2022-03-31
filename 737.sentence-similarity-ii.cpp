/*
 * @lc app=leetcode id=737 lang=cpp
 *
 * [737] Number of Provinces
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Union Find
    //  ref: https://www.cnblogs.com/grandyang/p/8053934.html
    bool areSentencesSimilarTwo(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs)
    {
        if (sentence1.size() != sentence2.size())
            return false;
        for (auto p : similarPairs)
        {
            if (findRoot(p[0]) != findRoot(p[1]))
                root[findRoot(p[0])] = findRoot(p[1]);
        }
        for (int i = 0; i < sentence1.size(); ++i)
        {
            if (findRoot(sentence1[i]) != findRoot(sentence2[i]))
                return false;
        }
        return true;
    }

private:
    unordered_map<string, string> root;
    string findRoot(string s)
    {
        if (!root.count(s))
            root[s] = s;
        return root[s] == s ? s : findRoot(root[s]);
    }
};

// @lc code=end