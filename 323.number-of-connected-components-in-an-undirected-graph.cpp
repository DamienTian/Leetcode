/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start
// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS, using Hashmap and set
    int countComponents(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, unordered_set<int>> mem;
        for (auto edge : edges)
        {
            mem[edge[0]].emplace(edge[1]);
            mem[edge[1]].emplace(edge[0]);
        }

        int result = 0;
        vector<int> searched(n, false);
        queue<int> q{{0}};
        for (int i = 0; i < n; ++i)
        {
            if(searched[i])
                continue;
            else
                q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                searched[curr] = true;
                if (mem.count(curr))
                {
                    for (int c : mem[curr])
                    {
                        if(!searched[c]){
                            q.push(c);
                        }
                    }
                }
            }
            result++;
            if(!searched[i])
                q.push(i);
        }

        return result;
    }

    // Solution 2: DFS
};

// @lc code=end