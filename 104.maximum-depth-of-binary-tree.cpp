/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode *root)
    {
        if(!root)
            return 0;
        int result = 0;
        travel(root, result, 0);
        return result;
    }

    // ref - short ver. from grandyang (https://www.cnblogs.com/grandyang/p/4051348.html):
    // int maxDepth(TreeNode* root) {
    //     if (!root) return 0;
    //     return 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

private:
    void travel(TreeNode *root, int& result, int currentDepth){
        if(!root){
            result = max(currentDepth, result);
            return;
        }
        travel(root->left, result, currentDepth + 1);
        travel(root->right, result, currentDepth + 1);
    }
};

// @lc code=end
