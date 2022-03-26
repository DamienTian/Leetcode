/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: DFS (Recursion)
    //  ref: https://www.cnblogs.com/grandyang/p/5849037.html
    string decodeString(string s)
    {
        int index = 0;
        return decode(s, index);
    }

private:
    string decode(const string &s, int &i)
    {
        string result = "";
        while (i < s.size() && s[i] != ']')
        {
            if (s[i] < '0' || s[i] > '9')
            {
                result += s[i++];
            }
            else
            {
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    count = count * 10 + s[i++] - '0';
                }
                ++i; // skip '['
                string t = decode(s, i);
                ++i; // skip ']'
                while (count-- > 0)
                {
                    result += t;
                }
            }
        }
        return result;
    }
};
// @lc code=end
