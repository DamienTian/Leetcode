/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
    // Solution 1: inOrder traversal
    // int rangeSumBST(TreeNode *root, int low, int high)
    // {
    //     if(!root)
    //         return 0;
    //     rangeSumBST(root->left, low, high);
    //     if(root->val >= low && root->val <= high){
    //         result += root->val;
    //     }
    //     rangeSumBST(root->right, low, high);
    //     return result;
    // }

    // Solution 2: traversal with pruning
    //  ref: https://www.cnblogs.com/grandyang/p/12640445.html
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if(!root) return 0;
        if(root->val < low) return rangeSumBST(root->right, low, high);
        if(root->val > high) return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

private:
    int result = 0;
};
// @lc code=end
