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
    // Solution 1: BFS (REVIEW 1)
    // int countComponents(int n, vector<vector<int>> &edges)
    // {
    //     unordered_map<int, unordered_set<int>> graph;
    //     for(const auto& e : edges){
    //         graph[e[0]].insert(e[1]);
    //         graph[e[1]].insert(e[0]);
    //     }
    //     unordered_set<int> visited;
    //     int result = n;
    //     for(int i = 0; i < n; i++){
    //         queue<int> q;
    //         if(!visited.count(i)){
    //             visited.insert(i);
    //             q.push(i);
    //         }
    //         while(!q.empty()){
    //             int t = q.front();
    //             q.pop();
    //             for(int n : graph[t]){
    //                 if(!visited.count(n)){
    //                     --result;
    //                     visited.insert(n);
    //                     q.push(n);
    //                 }
    //             }
    //         }
    //     }
    //     return result;
    // }

    // Solution 2: DFS (skip, folllow the same idea of BFS)

    // Solution 3: edge collasped
    //  ref: https://www.cnblogs.com/grandyang/p/5166356.html
    int countComponents(int n, vector<vector<int>> &edges)
    {
        int result = n;
        vector<int> root(n);
        for(int i = 0; i < n; ++i)
            root[i] = i;
        for(const auto& e : edges){
            int x = findRoot(root, e[0]), y = findRoot(root, e[1]);
            if(x != y){
                --result;
                root[y] = x;
            }
        }  
        return result; 
    }

private:
    int findRoot(const vector<int>& root, int i){
        while(root[i] != i)
            i = root[i];
        return i;
    }
};

// @lc code=end