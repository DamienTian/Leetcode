/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Union Find
    //  ref: https://www.cnblogs.com/grandyang/p/7829169.html
    //  note: huahua's lecture avout union find - https://www.youtube.com/watch?v=VJnUwsE4fWA
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string>> result;
        // union find forest
        unordered_map<string, string> root;
        // assign the email to owner
        unordered_map<string, string> owner;
        // union the owner and emails
        unordered_map<string, set<string>> unionSet;

        // first init root and owner
        for (const auto &account : accounts)
        {
            for (int i = 1; i < account.size(); ++i)
            {
                // assign email to itself in root
                root[account[i]] = account[i];
                // assign email's owner
                owner[account[i]] = account[0];
            }
        }

        // connect all emails to a root email base on the name
        for (const auto &account : accounts)
        {
            string rootEmail = findRoot(account[1], root);
            for (int i = 2; i < account.size(); ++i)
            {
                root[findRoot(account[i], root)] = rootEmail;
            }
        }

        // build the union result
        for (const auto &account : accounts)
        {
            for (int i = 1; i < account.size(); ++i)
            {
                unionSet[findRoot(account[i], root)].insert(account[i]);
            }
        }

        // build result
        for (auto u : unionSet)
        {
            vector<string> emails(u.second.cbegin(), u.second.cend());
            emails.insert(emails.begin(), owner[u.first]);
            result.push_back(emails);
        }

        return result;
    }

private:
    // find the root of the node
    string findRoot(string s, unordered_map<string, string> &root)
    {
        return root[s] == s ? s : findRoot(root[s], root);
    }
};
// @lc code=end
