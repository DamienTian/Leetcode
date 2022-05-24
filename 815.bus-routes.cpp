/*
 * @lc app=leetcode id=815 lang=cpp
 *
 * [815] Bus Routes
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // failed solution: TLE + connect each stops as a graph
        //return bfsFailed(routes, source, target);
        return bfs(routes, source, target);
    }

private:
    // Solution: bfs
    //  ref: http://zxi.mytechroad.com/blog/graph/leetcode-815-bus-routes/
    int bfs(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;
        unordered_map<int, vector<int>> stopBusMapping;
        for(int i = 0; i < routes.size(); ++i){
            for(const int& stop : routes[i]){
                // map stop : buses can reach
                stopBusMapping[stop].push_back(i);
            }
        }
        vector<bool> visited(routes.size(), false);
        queue<int> q{{source}};
        int result = 0;
        while(!q.empty()){
            ++result;
            int level = q.size();
            for (int i = 0; i < level; ++i){
                int currStop = q.front();
                q.pop();
                for(const int& bus : stopBusMapping[currStop]){
                    if(visited[bus])
                        continue;
                    visited[bus] = true;
                    for(const int& stop : routes[bus]){
                        if(stop == target)
                            return result;
                        q.push(stop);
                    }
                }
            }
        }
        return -1;
    }

    int bfsFailed(vector<vector<int>>& routes, int source, int target){
        if (source == target)
            return 0;
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> &route : routes)
        {
            for (int i = 0; i < route.size(); ++i)
            {
                for (int j = 0; j < route.size(); ++j)
                {
                    if (i == j)
                        continue;
                    graph[route[i]].insert(route[j]);
                    graph[route[j]].insert(route[i]);
                }
            }
        }
        int result = 0;
        queue<int> q{{source}};
        unordered_set<int> visited{source};
        while (!q.empty())
        {
            ++result;
            int level = q.size();
            for (int i = 0; i < level; ++i)
            {
                int curr = q.front();
                q.pop();
                for (int reach : graph[curr])
                {
                    if (reach == target)
                        return result;
                    if (visited.count(reach))
                        continue;
                    q.push(reach);
                    visited.insert(reach);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

