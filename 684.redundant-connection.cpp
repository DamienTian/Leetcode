/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: Union Find
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int index = 0;
        // try remove every edge from back, then build union find and see if they has the same root
        for (int i = edges.size() - 1; i >= 0; --i)
        {
            vector<vector<int>> tryEdges(edges.begin(), edges.begin() + i);
            tryEdges.insert(tryEdges.end(), edges.begin() + i + 1, edges.end());

            // build union find forest
            // union find forest
            unordered_map<int, int> root;

            function<int(int)> findRoot = [&root, &findRoot](int n)
            {
                if (!root.count(n))
                    root[n] = n;
                return root[n] == n ? n : findRoot(root[n]);
            };

            for (auto e : tryEdges)
            {
                int r1 = findRoot(e[0]);
                int r2 = findRoot(e[1]);
                if (r1 != r2)
                {
                    root[r1] = r2;
                }
            }

            int sameRoot = -1;
            bool wrongEdge = false;
            for (int i = 1; i <= edges.size(); ++i)
            {
                if (sameRoot == -1)
                    sameRoot = findRoot(i);
                else
                {
                    if (findRoot(i) != sameRoot)
                    {
                        wrongEdge = true;
                        break;
                    }
                }
            }

            if (!wrongEdge)
            {
                index = i;
                break;
            }
        }
        return edges[index];
    }
};

// @lc code=end
