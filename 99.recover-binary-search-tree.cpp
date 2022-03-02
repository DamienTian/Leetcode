/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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

class Solution
{
public:
    // Solution 1: In Order traversal
    //  ref: https://zxi.mytechroad.com/blog/tree/leetcode-99-recover-binary-search-tree/
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(first->val, second->val);
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (prev && prev->val > root->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

private:
    TreeNode *first;
    TreeNode *second;
    TreeNode *prev;
};
// @lc code=end
