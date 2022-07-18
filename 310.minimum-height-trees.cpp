/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start

#include "dummyHead.h"

class Solution
{
public:
    // Solution: BFS & erase leaf vertices
    //  ref: https://www.cnblogs.com/grandyang/p/5000291.html
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        return bfs(n, edges);
    }

private:
    vector<int> bfs(int n, vector<vector<int>> &edges){
        if (n == 1)
            return {0};
        vector<int> result;
        // build the graph
        unordered_map<int, unordered_set<int>> graph;
        for (auto e : edges)
        {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        // bfs on leaves
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (graph[i].size() == 1)
                q.push(i);
        }
        // while more than 2 veritces has not been searched
        while (n > 2)
        {
            n -= q.size();
            for (int i = q.size(); i > 0; --i)
            {
                int leaf = q.front();
                q.pop();
                for (auto adj : graph[leaf])
                {
                    graph[adj].erase(leaf);
                    // when adjancent becomes leaf node, do bfs
                    if (graph[adj].size() == 1)
                        q.push(adj);
                }
            }
        }
        // the remaining nodes are roots
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }

        return result;
    }
};

// @lc code=end
