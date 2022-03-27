/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start

// #include "dummyHead.h"

class Solution
{
public:
    // Solution 1: DFS
    //  ref: http://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // consider each str as a node, edge connect them have different value
        unordered_map<string, unordered_map<string, double>> graph;
        for(int i = 0; i < equations.size(); ++i){
            string x = equations[i][0];
            string y = equations[i][1];
            graph[x][y] = values[i];
            graph[y][x] = 1 / values[i];
        }

        // search queries
        vector<double> result;
        for(auto query : queries){
            string x = query[0];
            string y = query[1];
            if(!graph.count(x) || !graph.count(y)){
                result.push_back(-1);
                continue;
            }
            unordered_set<string> visited;
            double res = dfs(x, y, graph, visited);
            result.push_back(res);
        }
        return result;
    }

    // TODO: Solution 2: union find method
    //  ref: http://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/

private:
    double dfs(string x, string y, const unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited){
        if(x == y)
            return 1.0;
        visited.insert(x);
        // find the path between x to y, which is x / y
        for(const auto& g : graph.at(x)){
            string n = g.first;
            if(visited.count(n))
                continue;
            double d = dfs(n, y, graph, visited);
            if(d > 0)   return d * graph.at(x).at(n);
        }
        return -1.0;
    }
};
// @lc code=end
