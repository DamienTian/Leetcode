/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start

// IDEA: DFS (similar with Problem #200)
//  ref: https://zxi.mytechroad.com/blog/graph/leetcode-547-friend-circles/

class Solution {
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
        if(isConnected.empty()){
            return 0;
        }

        int result = 0;
        int n = isConnected.size();

        // mark if it has been visited
        vector<bool> visited(n, false);
        for(int i = 0; i < n; ++i){
            if(visited[i]){
                continue;
            }
            dfs(isConnected, n, i, visited);
            ++result;
        }

        return result;
    }

    void dfs(const vector<vector<int>>& isConnected, int n, int current, vector<bool>& visited){
        if(visited[current]) return;
        visited[current] = true;
        for(int i = 0; i < n; ++i){
            if(!visited[i] && isConnected[current][i] == 1){
                dfs(isConnected, n, i, visited);
            }
        }
    }
};
// @lc code=end

