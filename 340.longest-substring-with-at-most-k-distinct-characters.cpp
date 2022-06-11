/*
 * @lc app=leetcode id=340 lang=cpp
 *
 * [340] Longest Substring with At Most K Distinct Characters
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        return twoPtrsHash(s, k);
    }

private:
    // Falied Solution: two ptrs + hash
    //  ? reason: O(n^2)
    int twoPtrsHash_failed(string s, int k)
    {
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int curr = 0;
            unordered_set<char> mem;
            for (int j = i; j < s.size(); ++j)
            {
                if (!mem.count(s[j]))
                {
                    if(mem.size() == k)
                        break;
                    if (mem.size() < k)
                        mem.insert(s[j]);
                }
                curr++;
            }
            result = max(result, curr);
        }
        return result;
    }

    // Solution 1: two ptrs + hash map
    //  ref1: https://www.cnblogs.com/grandyang/p/5351347.html
    //  ref2: https://www.cnblogs.com/grandyang/p/5185561.html
    int twoPtrsHash(string s, int k)
    {
        int result = 0;
        // left index
        int left = 0;
        // counting the # of char appears
        unordered_map<char, int> mem;
        for (int i = 0; i < s.size(); ++i)
        {
            ++mem[s[i]];
            cout << "add " << s[i] << " count: " << mem[s[i]] << endl;
            while (mem.size() > k)
            {
                if (--mem[s[left]] == 0)
                {
                    cout << "erase " << s[left] << endl;
                    mem.erase(s[left]);
                }
                left++;
            }
            result = max(result, i - left + 1);
        }
        return result;
    }
};

// @lc code=end