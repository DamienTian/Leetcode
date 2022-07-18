/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

// #include "dummyHead.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // return dfs(numCourses, prerequisites);
        return bfs(numCourses, prerequisites);
    }
private:
    // Solution 1: DFS (topological sorting)
    //  ref: https://www.cnblogs.com/grandyang/p/4484571.html
    bool dfs(int numCourses, vector<vector<int>>& prerequisites){
        // build a graph
        vector<vector<int>> graph(numCourses, vector<int>());
        for(const auto& p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        
        // visited has three status:
        //  0: has not been visited yet
        //  1: has been visited
        //  -1: is visiting
        vector<int> visited(numCourses, 0);
  
        // search every course to find circle (see topological sorting)
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i, graph, visited))
                return false;
        }
        return true;
    }

    bool dfs(int current, const vector<vector<int>>& graph, vector<int>& visited){
        if(visited[current] == -1)
            return false;
        if(visited[current] == 1)
            return true;
        visited[current] = -1;  // mark as "visiting"
        for(const int& course : graph[current]){
            if(!dfs(course, graph, visited))
                return false;
        }
        visited[current] = 1;   // makr as "visited"
        return true;
    }

    // Solution 2: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/4484571.html (code)
    //  ref: https://baike.baidu.com/item/%E5%85%A5%E5%BA%A6/6172141 (indegree)
    bool bfs(int numCourses, vector<vector<int>>& prerequisites){
        // build graph and store indegree of each vertices
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);
        for(const auto& p : prerequisites){
            graph[p[1]].push_back(p[0]);
            ++indegrees[p[0]];
        }

        // queue for bfs
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indegrees[i] == 0)
                q.push(i);
        }

        // do bfs
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(const int& course : graph[curr]){
                --indegrees[course];
                if(indegrees[course] == 0)
                    q.push(course);
            }
        }

        // check if all indegree is 0
        for(int i = 0; i < numCourses; ++i) {
            if(indegrees[i] != 0)
                return false;
        }
        return true;
    }
};
// @lc code=end

