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
    // vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    // {
    //     // consider each str as a node, edge connect them have different value
    //     unordered_map<string, unordered_map<string, double>> graph;
    //     for(int i = 0; i < equations.size(); ++i){
    //         string x = equations[i][0];
    //         string y = equations[i][1];
    //         graph[x][y] = values[i];
    //         graph[y][x] = 1 / values[i];
    //     }
    //     // search queries
    //     vector<double> result;
    //     for(auto query : queries){
    //         string x = query[0];
    //         string y = query[1];
    //         if(!graph.count(x) || !graph.count(y)){
    //             result.push_back(-1);
    //             continue;
    //         }
    //         unordered_set<string> visited;
    //         double res = dfs(x, y, graph, visited);
    //         result.push_back(res);
    //     }
    //     return result;
    // }

    // Solution 2: union find method
    //  ref: http://zxi.mytechroad.com/blog/graph/leetcode-399-evaluate-division/
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        for (int i = 0; i < equations.size(); ++i)
        {
            const string &x = equations[i][0];
            const string &y = equations[i][1];
            const double v = values[i];
            if (!root.count(x) && !root.count(y))
            {
                root[x] = {y, v};
                root[y] = {y, 1.0};
            }
            else if (!root.count(x))
            {
                root[x] = {y, v};
            }
            else if (!root.count(y))
            {
                root[y] = {x, 1 / v};
            }
            else
            {
                auto &xRoot = findRoot(x);
                auto &yRoot = findRoot(y);
                root[xRoot.first] = {yRoot.first, v / xRoot.second * yRoot.second};
            }
        }

        vector<double> result;
        for (const auto& q : queries)
        {
            const string &x = q[0], y = q[1];
            if (!root.count(x) || !root.count(y))
            {
                result.push_back(-1.0);
                continue;
            }
            auto &xRoot = findRoot(x);
            auto &yRoot = findRoot(y);
            if (xRoot.first != yRoot.first)
                result.push_back(-1.0);
            else
                result.push_back(xRoot.second / yRoot.second);
        }

        return result;
    }

private:
    double dfs(string x, string y, const unordered_map<string, unordered_map<string, double>> &graph, unordered_set<string> &visited)
    {
        if (x == y)
            return 1.0;
        visited.insert(x);
        // find the path between x to y, which is x / y
        for (const auto &g : graph.at(x))
        {
            string n = g.first;
            if (visited.count(n))
                continue;
            double d = dfs(n, y, graph, visited);
            if (d > 0)
                return d * graph.at(x).at(n);
        }
        return -1.0;
    }

    // Union find
    unordered_map<string, pair<string, double>> root;

    pair<string, double>& findRoot(const string &s)
    {
        if (s != root[s].first)
        {
            const auto &p = findRoot(root[s].first);
            root[s].first = p.first;
            root[s].second *= p.second;
        }
        return root[s];
    }
};
// @lc code=end
