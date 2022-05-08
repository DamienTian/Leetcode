/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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

class Solution
{
public:
    // Solution: DFS
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric(root->left, root->right);
    }

private:
    bool isSymmetric(TreeNode *r1, TreeNode *r2)
    {
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        if(r1->val != r2->val)
            return false;
        return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
    }
};
// @lc code=end
