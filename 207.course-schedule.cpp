/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: BFS
    //  ref: https://www.cnblogs.com/grandyang/p/4484571.html
    //  note: check ref for term "indegree"
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int, unordered_set<int>> graph;
       // indegree of vertex indicates the # of edge point to the vertex
       vector<int> inDegree(numCourses, 0);
        for(auto pre: prerequisites){
           graph[pre[1]].insert(pre[0]);
           inDegree[pre[0]]++;
        }
        // bfs all the node that indegree is 0 (no prerequest)
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int c = q.front();
            q.pop();
            for(int cc : graph[c]){
                --inDegree[cc];
                if(inDegree[cc] == 0)
                    q.push(cc);
            }
        }
        // check loop
        for(int i : inDegree){
            if(i != 0)
                return false;
        }
        return true;
    }

    // Solution 2: DFS
    //  ref1: https://www.cnblogs.com/grandyang/p/4484571.html (code)
    //  ref2: http://zxi.mytechroad.com/blog/graph/leetcode-207-course-schedule/ (talks about topological sorting)
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, unordered_set<int>> graph;
        for (auto pre : prerequisites)
            graph[pre[1]].insert(pre[0]);
        // status: 0 = not visit, 1 = visiting, 2 = visited
        vector<int> status(numCourses, 0);
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(graph, status, i))
                return false;
        }
        return true;
    }

private:
    bool dfs(unordered_map<int, unordered_set<int>>& graph, vector<int>& status, int currentCourse){
        if(status[currentCourse] == 2)
            return true;
        if(status[currentCourse] == 1)  // found cycle;
            return false;
        // change the current searching course status to "visiting"
        status[currentCourse] = 1;
        for(int course : graph[currentCourse]){
            if(!dfs(graph, status, course))
                return false;
        }
        // if no cycle, change the status of current searching course to "visited"
        status[currentCourse] = 2;
        return true;
    }
};
// @lc code=end
