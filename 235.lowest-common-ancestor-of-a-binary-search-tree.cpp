/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    // Solution 1: without using BST property
    //  ref：https://www.cnblogs.com/grandyang/p/4641968.html
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        return left ? left : right;
    }

    // Solution 2: using BST property
    //  ref: https://www.cnblogs.com/grandyang/p/4640572.html
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root->left && root->val > max(p->val, q->val))
            return lowestCommonAncestor(root->left, p, q);
        if(root->right && root->val < min(p->val, q->val))
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
// @lc code=end
