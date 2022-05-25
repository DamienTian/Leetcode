/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
// Definition for a binary tree node.
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
// #include "dummyHead.h"

// NOTE: This problem is the same as problem 314... and 314 is a premium problem ...
////    so what did I pay for???

class Solution
{
public:
    // Solution: DFS
    //  note: check BFS solution in #314
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        vector<vector<int>> result;
        for (auto rm : mem)
        {
            result.push_back({});
            for(auto m : rm.second){
                sort(m.second.begin(), m.second.end());
                result.back().insert(result.back().end(), m.second.begin(), m.second.end());
            }
        }
        return result;
    }

private:
    map<int, map<int, vector<int>>> mem;
    void dfs(TreeNode *root, int rowIndex, int colIndex)
    {
        if (!root)
            return;
        mem[colIndex][rowIndex].push_back(root->val);
        dfs(root->left, rowIndex + 1, colIndex - 1);
        dfs(root->right, rowIndex + 1, colIndex + 1);
    }
};
// @lc code=end
