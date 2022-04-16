/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS (using topological sorting method from #207)
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> result;
    //     vector<int> indegree(numCourses, 0);
    //     vector<vector<int>> graph(numCourses, vector<int>());
    //     for(auto p : prerequisites){
    //         graph[p[1]].push_back(p[0]);
    //         indegree[p[0]]++;
    //     }
    //     queue<int> q;
    //     for(int i = 0; i < numCourses; ++i){
    //         if(indegree[i] == 0)
    //             q.push(i);
    //     }
    //     while(!q.empty()){
    //         int c = q.front();
    //         q.pop();
    //         result.push_back(c);
    //         for(auto adj : graph[c]){
    //             indegree[adj]--;
    //             if(indegree[adj] == 0)
    //                 q.push(adj);
    //         }
    //     }
    //     return (result.size() == numCourses) ? result : vector<int>();
    // }

    // Solution 2: DFS
    //  ref: https://leetcode.com/problems/course-schedule-ii/solution/
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> result;
        vector<status> visited(numCourses, status::notVisited);
        unordered_map<int, unordered_set<int>> graph;
        for (auto p : prerequisites)
            graph[p[1]].insert(p[0]);
        for(int i = 0; i < numCourses; ++i){
            if(visited[i] == notVisited){
                if(!dfs(numCourses, graph, visited, result, i))
                    return {};
            }
        }
        // since the dfs put the end course into result first, result need to be reversed before return
        reverse(result.begin(), result.end());
        return (result.size() == numCourses) ? result : vector<int>();
    }

private:
    enum status
    {
        notVisited,
        visiting,
        visited
    };

    bool dfs(int numCourses, unordered_map<int, unordered_set<int>> &graph, vector<status> &visited, vector<int> &result, int course){
        if(visited[course] == status::visited)
            return true;
        if(visited[course] == status::visiting)
            return false;
        visited[course] = status::visiting;
        for(int c : graph[course]){
            if(!dfs(numCourses, graph, visited, result, c))
                return false;
        }
        visited[course] = status::visited;
        result.push_back(course);
        return true;
    }
};
// @lc code=end
