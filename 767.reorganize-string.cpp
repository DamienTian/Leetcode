/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution: Hash map + max heap
    //  ref: https://www.cnblogs.com/grandyang/p/8799483.html
    string reorganizeString(string s)
    {
        auto compare = [](pair<char, int> p1, pair<char, int> p2)
        {
            return p1.second < p2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(compare)> q(compare);
        unordered_map<char, int> mem;
        for (const char &c : s)
            mem[c]++;
        for (const auto &m : mem)
        {
            if (m.second > (s.size() + 1) / 2)
                return "";
            q.push(m);
        }
        string result = "";
        // construct result
        while(q.size() >= 2){
            auto t1 = q.top(); 
            q.pop();
            auto t2 = q.top(); 
            q.pop();
            result += t1.first;
            result += t2.first;
            // add back to queue
            if(--t1.second > 0) q.push(t1);
            if(--t2.second > 0) q.push(t2);
        }
        // add remaining char into result
        if (q.size() > 0) 
            result += q.top().first;
        return result;
    }
};
// @lc code=end
