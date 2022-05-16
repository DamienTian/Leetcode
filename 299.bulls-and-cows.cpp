/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: hashmap (grandyang use a array ot replace the hashmap)
    //  ref: https://www.cnblogs.com/grandyang/p/4929139.html
    string getHint(string secret, string guess)
    {
        int m[256] = {0}; // hashmap
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
                ++bull;
            else
            {
                if (m[secret[i]]++ < 0)
                    ++cow;
                if (m[guess[i]]-- > 0)
                    ++cow;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
// @lc code=end
