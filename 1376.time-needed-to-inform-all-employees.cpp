/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    // Solution 1: DFS + graph
    //  ref: https://zxi.mytechroad.com/blog/searching/leetcode-1376-time-needed-to-inform-all-employees/
    // int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    //     // build graph
    //     vector<vector<int>> graph(n);
    //     for(int i = 0; i < n; ++i){
    //         if(i != headID)
    //             graph[manager[i]].push_back(i);
    //     }
    //     // dfs
    //     function<int(int)> dfs = [&](int current){
    //         int result = 0;
    //         for(int employee : graph[current]){
    //             result = max(result, dfs(employee));
    //         }
    //         return result + informTime[current];
    //     };
    //     return dfs(headID);
    // }

    // Solution 2: DFS + memoization
    //  ref: https://zxi.mytechroad.com/blog/searching/leetcode-1376-time-needed-to-inform-all-employees/
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // stores communication cost from head to i employee
        vector<int> cost(n, -1);
        // dfs
        function<int(int)> dfs = [&](int current){
            if(current == -1)   // if is head
                return 0;
            if(cost[current] == -1) // search reversly from employee to it's manager
                cost[current] = dfs(manager[current]) + informTime[current];
            return cost[current];
        };
        // find all employees' cost and take the max
        int result = 0;
        for(int i = 0; i < n; ++i)
            result = max(result, dfs(i));
        return result;
    }
};

// @lc code=end