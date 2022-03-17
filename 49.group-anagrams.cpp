/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
//#include "dummyHead.h"

class Solution
{
public:
    // Solution: Hashmap
    //  ref: https://www.cnblogs.com/grandyang/p/4385822.html
    //  TODO: there is a sort method in ref too, that one is better
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for (string str : strs)
        {
            vector<int> charCount(26);
            string key;
            for (char c : str)
                charCount[c - 'a']++;
            for (int i = 0; i < 26; ++i)
            {
                if (charCount[i] != 0)
                    key += string(1, i + 'a') + to_string(charCount[i]);
            }
            m[key].push_back(str);
        }
        for (auto a : m)
        {
            result.push_back(a.second);
        }

        return result;
    }
};
// @lc code=end
