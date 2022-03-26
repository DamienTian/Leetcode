/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Solution 1: DFS Recursion
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return dfs(root->left, root->right);
    }

    bool dfs(TreeNode *l, TreeNode *r)
    {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (!dfs(l->left, r->right))
            return false;
        if (l->val != r->val)
            return false;
        return dfs(l->right, r->left);
    }
};
// @lc code=end
