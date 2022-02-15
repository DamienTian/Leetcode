/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 */

// @lc code=start
class Solution
{
public:
    // Solution 1: BFS
    //  ref1: https://zxi.mytechroad.com/blog/graph/leetcode-1162-as-far-from-land-as-possible/
    //  ref2: https://www.cnblogs.com/grandyang/p/15037404.html
    //  note: the refs find all lands first, and then search all waters to find max distance
    int maxDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = -1;
        queue<vector<int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    q.push({i, j});
                }
            }
        }

        // If no land or water exists in the grid, return -1.
        if (q.size() == 0 || q.size() == m * n)
            return -1;

        // Local max distance for land to water
        int localMax = 0;
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            ++localMax;
            for (int k = q.size(); k > 0; --k)
            {
                vector<int> currLand = q.front();
                q.pop();
                // Search for directions
                for(const auto& d : directions){
                    int i = currLand[0] + d[0];
                    int j = currLand[1] + d[1];
                    if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0){
                        grid[i][j] = localMax;
                        q.push({i,j});
                    }
                }
            }
        }

        // NOTE
        // why -1, because at the search layer 0 (lands), localMax = 1;
        //                 at the search layer 1 (lands), localMax = 2;
        //                                  ...
        //         so at the end, the localMax is always 1 larger than the furthest distance 
        return localMax - 1;
    }
};

// @lc code=end
