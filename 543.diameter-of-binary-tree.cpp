/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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

// Review 1

class Solution
{
public:
    // Solution 1: DFS
    //  ref: http://zxi.mytechroad.com/blog/tree/leetcode-543-diameter-of-binary-tree/
    int diameterOfBinaryTree(TreeNode *root)
    {
        result_ = 0;
        dfs(root);
        return result_;
    }

private:
    int result_;
    int dfs(TreeNode *root)
    {
        if (!root)
            return -1;
        int left = dfs(root->left) + 1;
        int right = dfs(root->right) + 1;
        result_ = max(result_, left + right);
        return max(left, right);
    }
};
// @lc code=end
