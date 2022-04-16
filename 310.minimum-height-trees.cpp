/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Failed Solution: BFS on every vertex (TLE)
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     vector<int> result;
    //     int minHeight = INT_MAX;
    //     // build the graph
    //     unordered_map<int, unordered_set<int>> graph;
    //     for(auto e : edges){
    //         graph[e[0]].insert(e[1]);
    //         graph[e[1]].insert(e[0]);
    //     }
    //     for(int i = 0; i < n; ++i){
    //         vector<bool> visited(n, false);
    //         queue<int> q;
    //         q.push(i);
    //         int currentHeight = 0;
    //         while(!q.empty()){
    //             currentHeight++;
    //             for(int i = q.size(); i > 0; --i){
    //                 int leaf = q.front();
    //                 q.pop();
    //                 visited[leaf] = true;
    //                 for(int adj : graph[leaf]){
    //                     if(!visited[adj])
    //                         q.push(adj);
    //                 }
    //             }
    //         }
    //         // cout << currentHeight << " " << i << endl;
    //         if(currentHeight < minHeight){
    //             minHeight = currentHeight;
    //             result.clear();
    //         }
    //         if(currentHeight == minHeight)
    //             result.push_back(i);
    //     }
    //     return result;
    // }

    // Solution: BFS & erase leaf vertices
    //  ref: https://www.cnblogs.com/grandyang/p/5000291.html
     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> result;
        // build the graph
        unordered_map<int, unordered_set<int>> graph;
        for(auto e : edges){
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }
        // bfs on leaves
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) 
                q.push(i);
        }
        // while more than 2 veritces has not been searched
        while(n > 2){
            n -= q.size();
            for(int i = q.size(); i > 0; --i){
                int leaf = q.front();
                q.pop();
                for(auto adj : graph[leaf]){
                    graph[adj].erase(leaf);
                    // when adjancent becomes leaf node, do bfs
                    if(graph[adj].size() == 1)
                        q.push(adj);
                }
            }
        }
        // the remaining nodes are roots
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }

        return result;
     }
};

// @lc code=end

