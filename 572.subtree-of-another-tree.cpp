/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    // Solution 1: DFS
    //  ref: https://www.cnblogs.com/grandyang/p/6828687.html
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if(!root)
            return false;
        if(isSametree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSametree(TreeNode *root, TreeNode *subRoot){
         if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val != subRoot->val)
            return false;
        return isSametree(root->left, subRoot->left) && isSametree(root->right, subRoot->right);
    }

    
};
// @lc code=end
