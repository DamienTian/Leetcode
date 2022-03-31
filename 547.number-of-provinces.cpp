/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DFS (similar with Problem #200)
    //  ref: https://zxi.mytechroad.com/blog/graph/leetcode-547-friend-circles/
    // int findCircleNum(const vector<vector<int>> &isConnected)
    // {
    //     if (isConnected.empty())
    //     {
    //         return 0;
    //     }
    //     int result = 0;
    //     int n = isConnected.size();
    //     // mark if it has been visited
    //     vector<bool> visited(n, false);
    //     for (int i = 0; i < n; ++i)
    //     {
    //         if (visited[i])
    //         {
    //             continue;
    //         }
    //         dfs(isConnected, n, i, visited);
    //         ++result;
    //     }
    //     return result;
    // }

    // Solution 2: union find
    //  ref: cnblogs.com/grandyang/p/6686983.html
    int findCircleNum(const vector<vector<int>> &isConnected)
    {
        if (isConnected.empty())
        {
            return 0;
        }

        int result = isConnected.size();

        for(int i = 0; i < isConnected.size(); ++i)
            root[i] = i;

        for(int i = 0; i < isConnected.size(); ++i){
            for(int j = i + 1; j < isConnected[i].size(); ++j){
                if(isConnected[i][j] == 1 && findRoot(i) != findRoot(j)){
                    --result;
                    root[findRoot(j)] = findRoot(i);
                }
            }
        }
        
        return result;
    }

private:
    void dfs(const vector<vector<int>> &isConnected, int n, int current, vector<bool> &visited)
    {
        if (visited[current])
            return;
        visited[current] = true;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i] && isConnected[current][i] == 1)
            {
                dfs(isConnected, n, i, visited);
            }
        }
    }

    // union find forest
    unordered_map<int, int> root;

    int findRoot(int n){
        return root[n] == n ? n : findRoot(root[n]);
    }
};
// @lc code=end
